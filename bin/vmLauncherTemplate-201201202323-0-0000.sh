#!/bin/sh
export SPARK_CLASSPATH=/spark-distro/lib_managed/jars/xmlenc/xmlenc/xmlenc-0.52.jar:/spark-distro/lib_managed/jars/tomcat/jasper-runtime/jasper-runtime-5.5.12.jar:/spark-distro/lib_managed/jars/tomcat/jasper-compiler/jasper-compiler-5.5.12.jar:/spark-distro/lib_managed/jars/oro/oro/oro-2.0.8.jar:/spark-distro/lib_managed/jars/org.slf4j/slf4j-log4j12/slf4j-log4j12-1.6.1.jar:/spark-distro/lib_managed/jars/org.slf4j/slf4j-api/slf4j-api-1.6.1.jar:/spark-distro/lib_managed/jars/org.scala-tools.testing/test-interface/test-interface-0.5.jar:/spark-distro/lib_managed/jars/org.scala-tools.testing/scalacheck_2.9.1/scalacheck_2.9.1-1.9.jar:/spark-distro/lib_managed/jars/org.scalatest/scalatest_2.9.1/scalatest_2.9.1-1.6.1.jar:/spark-distro/lib_managed/jars/org.mortbay.jetty/servlet-api-2.5/servlet-api-2.5-6.1.14.jar:/spark-distro/lib_managed/jars/org.mortbay.jetty/jsp-api-2.1/jsp-api-2.1-6.1.14.jar:/spark-distro/lib_managed/jars/org.mortbay.jetty/jsp-2.1/jsp-2.1-6.1.14.jar:/spark-distro/lib_managed/jars/org.mortbay.jetty/jetty-util/jetty-util-6.1.14.jar:/spark-distro/lib_managed/jars/org.mortbay.jetty/jetty/jetty-6.1.14.jar:/spark-distro/lib_managed/jars/org.eclipse.jetty/jetty-util/jetty-util-7.5.3.v20111011.jar:/spark-distro/lib_managed/jars/org.eclipse.jetty/jetty-server/jetty-server-7.5.3.v20111011.jar:/spark-distro/lib_managed/jars/org.eclipse.jetty/jetty-io/jetty-io-7.5.3.v20111011.jar:/spark-distro/lib_managed/jars/org.eclipse.jetty/jetty-http/jetty-http-7.5.3.v20111011.jar:/spark-distro/lib_managed/jars/org.eclipse.jetty/jetty-continuation/jetty-continuation-7.5.3.v20111011.jar:/spark-distro/lib_managed/jars/org.eclipse.jdt/core/core-3.1.1.jar:/spark-distro/lib_managed/jars/org.apache.hadoop/hadoop-core/hadoop-core-0.20.2.jar:/spark-distro/lib_managed/jars/net.sf.kosmosfs/kfs/kfs-0.3.jar:/spark-distro/lib_managed/jars/net.java.dev.jets3t/jets3t/jets3t-0.7.1.jar:/spark-distro/lib_managed/jars/junit/junit/junit-4.5.jar:/spark-distro/lib_managed/jars/javax.servlet/servlet-api/servlet-api-2.5.jar:/spark-distro/lib_managed/jars/hsqldb/hsqldb/hsqldb-1.8.0.10.jar:/spark-distro/lib_managed/jars/de.javakaffee/kryo-serializers/kryo-serializers-0.9.jar:/spark-distro/lib_managed/jars/concurrent/concurrent/concurrent-1.3.4.jar:/spark-distro/lib_managed/jars/commons-net/commons-net/commons-net-1.4.1.jar:/spark-distro/lib_managed/jars/commons-logging/commons-logging/commons-logging-1.1.1.jar:/spark-distro/lib_managed/jars/commons-httpclient/commons-httpclient/commons-httpclient-3.0.1.jar:/spark-distro/lib_managed/jars/commons-el/commons-el/commons-el-1.0.jar:/spark-distro/lib_managed/jars/commons-codec/commons-codec/commons-codec-1.3.jar:/spark-distro/lib_managed/jars/commons-cli/commons-cli/commons-cli-1.2.jar:/spark-distro/lib_managed/jars/com.google.protobuf/protobuf-java/protobuf-java-2.3.0.jar:/spark-distro/lib_managed/jars/com.google.guava/guava/guava-r09.jar:/spark-distro/lib_managed/jars/com.googlecode/reflectasm/reflectasm-1.01.jar:/spark-distro/lib_managed/jars/com.googlecode/minlog/minlog-1.2.jar:/spark-distro/lib_managed/jars/com.googlecode/kryo/kryo-1.04.jar:/spark-distro/lib_managed/jars/colt/colt/colt-1.2.0.jar:/spark-distro/lib_managed/jars/asm/asm/asm-3.2.jar:/spark-distro/lib_managed/jars/asm/asm-all/asm-all-3.3.1.jar:/spark-distro/lib_managed/jars/ant/ant/ant-1.6.5.jar:/mesos-distro/lib/java/mesos.jar
export SPARK_MEM=512m
export MESOS_HADOOP_HOME=/hadoop-distro
export MESOS_FRAMEWORK_ID=201201202323-0-0000
export MESOS_EXECUTOR_URI=/spark-distro/spark-executor
export MESOS_USER=hduser
export MESOS_WORK_DIRECTORY=/mesos-distro/work/slaves/201201202323-0-0/frameworks/201201202323-0-0000/executors/default/runs/0
export MESOS_SLAVE_PID=slave@192.168.1.64:57744
export MESOS_REDIRECT_IO=1
export MESOS_SWITCH_USER=1
export MESOS_CONTAINER=hostvirkaz3-clone
export MESOS_HOME=/mesos-distro
export MESOS_FRAMEWORK_ID=201201202323-0-0000
export MESOS_EXECUTOR_URI=/spark-distro/spark-executor
export MESOS_EXECUTOR_ID=default
export MESOS_USER=hduser
export MESOS_WORK_DIRECTORY=/mesos-distro/work/slaves/201201202323-0-0/frameworks/201201202323-0-0000/executors/default/runs/0
export MESOS_SLAVE_PID=slave@192.168.1.64:57744
export MESOS_HOME=/mesos-distro
export MESOS_HADOOP_HOME=/hadoop-distro
export MESOS_REDIRECT_IO=1
export MESOS_SWITCH_USER=1
export MESOS_CONTAINER=hostvirkaz3-clone
mkdir -p /mesos-distro/work/slaves/201201202323-0-0/frameworks/201201202323-0-0000/executors/default/runs/0
/mesos-distro/bin/mesos-launcher
