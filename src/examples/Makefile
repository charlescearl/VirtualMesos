# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Makefile.

SHELL = '/bin/sh'

SRCDIR = .
INCLUDEDIR = ../../include
BINDIR = ../../bin
LIBDIR = ../../lib

CC = gcc
CXX = g++
SWIG = @SWIG@

CFLAGS = -O2 -fno-strict-aliasing -fPIC 
CXXFLAGS = -O2 -fno-strict-aliasing -fPIC 
LDFLAGS = 
LIBS = 

OS_NAME = linux

JAVA_HOME = /usr/lib/jvm/java-6-openjdk
PYTHON_HEADERS = /usr/include/python2.7

WITH_ZOOKEEPER = 1

WITH_INCLUDED_ZOOKEEPER = 1

BOOST = third_party/boost-1.37.0
PROTOBUF = third_party/protobuf-2.3.0
GLOG = third_party/glog-0.3.1
LIBPROCESS = third_party/libprocess
LIBEV = $(LIBPROCESS)/third_party/libev-3.8
ZOOKEEPER = third_party/zookeeper-3.3.1/src/c

# Ensure that we get better debugging info.
CFLAGS += -g
CXXFLAGS += -g

# Add include and build include to CFLAGS and CXXFLAGS.
CFLAGS += -I../../include -I$(INCLUDEDIR)
CXXFLAGS += -I../../include -I$(INCLUDEDIR)

# Add boost to CFLAGS and CXXFLAGS.
CFLAGS += -I../../$(BOOST)
CXXFLAGS += -I../../$(BOOST)

# Add glog to include and lib paths.
CXXFLAGS += -I../../$(GLOG)/src -I../../$(GLOG)/src
LDFLAGS += -L../../$(GLOG)/.libs

# Add protobuf to include and lib paths.
CXXFLAGS += -I../../$(PROTOBUF)/src
LDFLAGS += -L../../$(PROTOBUF)/src/.libs

# Add libprocess to CFLAGS, CXXFLAGS, and LDFLAGS.
CFLAGS += -I../../$(LIBPROCESS)
CXXFLAGS += -I../../$(LIBPROCESS)
LDFLAGS += -L../../$(LIBPROCESS)

# Add libev to LDFLAGS.
LDFLAGS += -L../../$(LIBEV)/.libs

# Add included ZooKeeper to include and lib paths if necessary.
ifeq ($(WITH_INCLUDED_ZOOKEEPER),1)
  CXXFLAGS += -I../../$(ZOOKEEPER)/include -I../../$(ZOOKEEPER)/generated
  LDFLAGS += -L../../$(ZOOKEEPER)/.libs
endif

# Add dependency tracking to CFLAGS, CXXFLAGS.
CFLAGS += -MMD -MP
CXXFLAGS += -MMD -MP

# Add protobuf, glog, libev, libprocess, pthread, and dl to LIBS.
LIBS += -lprotobuf -lglog -lprocess -lev -lpthread -ldl

# Add ZooKeeper if necessary.
ifeq ($(WITH_ZOOKEEPER),1)
  LIBS += -lzookeeper_mt
endif

SCHED_EXES = $(BINDIR)/examples/cpp-test-framework	\
	     $(BINDIR)/examples/long-lived-framework	\
             $(BINDIR)/examples/memhog			\
             $(BINDIR)/examples/scheduled-memhog

EXEC_EXES = $(BINDIR)/examples/cpp-test-executor	\
            $(BINDIR)/examples/long-lived-executor	\
            $(BINDIR)/examples/memhog-executor

EXAMPLES_EXES = $(SCHED_EXES) $(EXEC_EXES)

MESOS_SCHED_LIB = $(LIBDIR)/libmesos_sched.a
MESOS_EXEC_LIB = $(LIBDIR)/libmesos_exec.a

# Create rules for building the directories that aren't created
# automagically by configure.
DIRECTORIES = $(BINDIR)/examples


default: all

-include $(patsubst %, %.d, $(EXAMPLES_EXES))

$(DIRECTORIES): %:
	mkdir -p $@

$(EXAMPLES_EXES): | $(BINDIR)/examples

$(BINDIR)/examples/test-framework: ./test_framework.cpp $(MESOS_SCHED_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_SCHED_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/test-executor: ./test_exec.cpp $(MESOS_EXEC_LIB)
	g++ $(CXXFLAGS) -o $@ $< $(MESOS_EXEC_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/cpp-test-framework: ./cpp_test_framework.cpp $(MESOS_SCHED_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_SCHED_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/cpp-test-executor: ./cpp_test_executor.cpp $(MESOS_EXEC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_EXEC_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/long-lived-framework: ./long_lived_framework.cpp $(MESOS_SCHED_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_SCHED_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/long-lived-executor: ./long_lived_executor.cpp $(MESOS_EXEC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_EXEC_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/memhog: ./memhog.cpp $(MESOS_SCHED_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_SCHED_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/memhog-executor: ./memhog_executor.cpp $(MESOS_EXEC_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_EXEC_LIB) $(LDFLAGS) $(LIBS)

$(BINDIR)/examples/scheduled-memhog: ./scheduled_memhog.cpp $(MESOS_SCHED_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(MESOS_SCHED_LIB) $(LDFLAGS) $(LIBS)

java:
ifdef JAVA_HOME
	$(MAKE) -C java
endif

python:
ifdef PYTHON_HEADERS
	$(MAKE) -C python
endif

all: $(EXAMPLES_EXES) java python

clean:
	rm -f $(patsubst %, %.d, $(EXAMPLES_EXES))
	rm -rf $(patsubst %, %.dSYM, $(EXAMPLES_EXES))
	rm -f $(EXAMPLES_EXES)
	rm -f TAGS
ifdef JAVA_HOME
	$(MAKE) -C java clean
endif
ifdef PYTHON_HEADERS
	$(MAKE) -C python clean
endif

.PHONY: default all clean java python
