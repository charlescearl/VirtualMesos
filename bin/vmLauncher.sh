#!/bin/sh
# Temporary launcher for virtual machine.
# Takes environment variables from the command line.
# Sets them and spawns the appropriate executor
# An alternative is to create a new file in local dir
# Append values to the temp file
# Copy the file to the guest /mesos-distro/remote-scripts/script-<script_id>.sh
# Run ssh user@guest '/mesos-distro/remote-scripts/script-<script_id>.sh'

# Setup the environment
# lxc_isolation_module.cpp:182 export the received environment
# launcher.cpp:268
# have to create a work directory on the guest
# MESOS_DIRECTORY and MESOS_WORK_DIRECTORY

# Call the executor
# $MESOS_EXECUTOR_URI $MESOS_ARGS