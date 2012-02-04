/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <mesos/mesos.hpp>

#include <boost/lexical_cast.hpp>

#include "launcher.hpp"

using std::string;

using boost::lexical_cast;

using namespace mesos;
using namespace mesos::internal::launcher;


const char * getenvOrFail(const char *variable)
{
  const char *value = getenv(variable);
  if (!value)
    fatal("environment variable %s not set", variable);
  return value;
}


const char * getenvOrEmpty(const char *variable)
{
  const char *value = getenv(variable);
  if (!value) return "";
  return value;
}

/**
 * Send the slave the message. Will have to fork/exec in order to do this.
 * Send the pid of the child process. I think this would be executor->pid
 * This code taken from slave/slave.cpp
 */
void notifySlaveOfTask(int pid,const  FrameworkID& frameworkId,
		           const ExecutorID& executorId,
		       const *Framework theFramework){
    ExecutorRegisteredMessage message;
    ExecutorArgs* args = message.mutable_args();
    args->mutable_framework_id()->MergeFrom(frameworkId);
    args->mutable_executor_id()->MergeFrom(executorId);
    // TODO: figure out where slave_id comes from 
    args->mutable_slave_id()->MergeFrom(id);
    // TODO: figure out where hostname comes from
    args->set_hostname(info.hostname());
    // TODO: figure out where data comes from
    args->set_data(executor->info.data());
    send(id, message);
}


int main(int argc, char **argv)
{
  FrameworkID frameworkId;
  frameworkId.set_value(getenvOrFail("MESOS_FRAMEWORK_ID"));

  ExecutorID executorId;
  executorId.set_value(getenvOrFail("MESOS_EXECUTOR_ID"));

  // To fork off the child
  int pid;

  Executor *theExecutor = new    ExecutorLauncher(frameworkId,
			  executorId,
			  getenvOrFail("MESOS_EXECUTOR_URI"),
			  getenvOrFail("MESOS_USER"),
			  getenvOrFail("MESOS_WORK_DIRECTORY"),
			  getenvOrFail("MESOS_SLAVE_PID"),
			  getenvOrEmpty("MESOS_FRAMEWORKS_HOME"),
			  getenvOrFail("MESOS_HOME"),
			  getenvOrFail("MESOS_HADOOP_HOME"),
			  lexical_cast<bool>(getenvOrFail("MESOS_REDIRECT_IO")),
			  lexical_cast<bool>(getenvOrFail("MESOS_SWITCH_USER")),
			  getenvOrEmpty("MESOS_CONTAINER"),
						  map<string, string>());
  // fork here,
  if((pid = fork()) != 0){
    notifySlaveOfTask(pid,theExecutor)
    // Now send slave a notification of the child pid
  }
  // then exec the mesos_launcher found in this directory
  // then can send the child process to the slave
  else{
    theExecutor->run();
  }
}
