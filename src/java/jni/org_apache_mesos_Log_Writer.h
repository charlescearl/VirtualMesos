/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_apache_mesos_Log_Writer */

#ifndef _Included_org_apache_mesos_Log_Writer
#define _Included_org_apache_mesos_Log_Writer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_apache_mesos_Log_Writer
 * Method:    append
 * Signature: ([B)Lorg/apache/mesos/Log/Position;
 */
JNIEXPORT jobject JNICALL Java_org_apache_mesos_Log_00024Writer_append
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     org_apache_mesos_Log_Writer
 * Method:    truncate
 * Signature: (Lorg/apache/mesos/Log/Position;)Lorg/apache/mesos/Log/Position;
 */
JNIEXPORT jobject JNICALL Java_org_apache_mesos_Log_00024Writer_truncate
  (JNIEnv *, jobject, jobject);

/*
 * Class:     org_apache_mesos_Log_Writer
 * Method:    initialize
 * Signature: (Lorg/apache/mesos/Log;)V
 */
JNIEXPORT void JNICALL Java_org_apache_mesos_Log_00024Writer_initialize
  (JNIEnv *, jobject, jobject);

/*
 * Class:     org_apache_mesos_Log_Writer
 * Method:    finalize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_apache_mesos_Log_00024Writer_finalize
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
