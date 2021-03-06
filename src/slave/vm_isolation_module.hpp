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

#ifndef __VM_ISOLATION_MODULE_HPP__
#define __VM_ISOLATION_MODULE_HPP__

#include <string>
#include <vector>

#include "isolation_module.hpp"
#include "reaper.hpp"
#include "slave.hpp"

#include "common/hashmap.hpp"

#include "launcher/launcher.hpp"

namespace mesos { namespace internal { namespace slave {

class VmIsolationModule
  : public IsolationModule, public ProcessExitedListener
{
public:
  VmIsolationModule();

  virtual ~VmIsolationModule();

  virtual void initialize(const Configuration& conf,
                          bool local,
                          const process::PID<Slave>& slave);


  virtual void launchExecutor(const FrameworkID& frameworkId,
                              const FrameworkInfo& frameworkInfo,
                              const ExecutorInfo& executorInfo,
                              const std::string& directory,
                              const Resources& resources);

  virtual void killExecutor(const FrameworkID& frameworkId,
                            const ExecutorID& executorId);

  virtual void resourcesChanged(const FrameworkID& frameworkId,
                                const ExecutorID& executorId,
                                const Resources& resources);

  virtual void processExited(pid_t pid, int status);



private:
  // No copying, no assigning.
  VmIsolationModule(const VmIsolationModule&);
  VmIsolationModule& operator = (const VmIsolationModule&);

  // Attempt to set a resource limit of a container for a given
  // control group property (e.g. cpu.shares).
  bool setControlGroupValue(const std::string& container,
                            const std::string& property,
                            int64_t value);

  void replacePathSubstring(std::string & path, const std::string & orig, const std::string & rep);

  std::string mapHostToGuestPath(std::string & path);
  /*
  void copyEnvParametersToScriptFile (const std::ofstream & ofs, 
				    ExecutorLauncher* launcher)  ;
  */

  int launchVirtualTask(const ExecutorInfo&  executorInfo,
			const ExecutorID& executorId,
			const FrameworkID& frameworkId,
			const FrameworkInfo& frameworkInfo,
			const std::string& vm,
			const std::string& vmIp,
			const std::string& directory,
			const process::PID<Slave>& slave,
			const Configuration& conf,
			bool local);

  std::vector<std::string> getControlGroupOptions(const Resources& resources);

  // Per-framework information object maintained in info hashmap.
  struct VmInfo
  {
    FrameworkID frameworkId;
    ExecutorID executorId;
    std::string vmId; // Name of Linux virtual machine used for this framework.
    std::string vm; // The unique virtual machine
    pid_t pid; // PID of vm-execute command running the executor.
  };

  // Actually, launch the process which is responsible for control of the
  // virtual machine
  int launchVirtualMachine(VmInfo* info);

  // Get the ip address of the virtual machine 
  std::string getVirtualMachineIp(std::string& vm);

  // Handle the setup of a virtual machine launch
  void launchVirtualTask(const std::string & vmIp,std::string & launchFileName,const FrameworkInfo& frameworkInfo);

  // TODO(benh): Make variables const by passing them via constructor.
  Configuration conf;
  bool local;
  process::PID<Slave> slave;
  bool initialized;
  Reaper* reaper;
  hashmap<FrameworkID, hashmap<ExecutorID, VmInfo*> > infos;
};

}}} // namespace mesos { namespace internal { namespace slave {

#endif // __VM_ISOLATION_MODULE_HPP__
