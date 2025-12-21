//
// Created by zegof on 20.12.2025.
//
#ifndef MFTalk_clientresources_bridge
#define MFTalk_clientresources_bridge

#include <jni.h>
#include <android/log.h>
#include "client-resources/ambercypher.h"



// https://stackoverflow.com/a/20111129
#define  LOG_TAG    "bridgeDebug"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


JNIEXPORT jstring JNICALL
Java_org_mftalk_android_1client_MainActivity_amberCencrypt(
        JNIEnv *env,
        jclass clazz,
        jstring text,
        jstring key,
        jlong seed1,
        jlong seed2
        ) {
    LOGD("called AmberCencrypt with parameters, %s, %s, %i, %i", text, key, seed1, seed2);
    const unsigned char * textC = (unsigned char*)(*env)->GetStringUTFChars(env, text, 0);
    const unsigned char * keyC = (unsigned char*)(*env)->GetStringUTFChars(env, key, 0);
    const unsigned long int seed1C = (unsigned long int)seed1;
    const unsigned long int seed2C = (unsigned long int)seed2;

    LOGD("input converted: %s, %s, %li, %li", textC, keyC, seed1C, seed2C);

    const unsigned char * encryptedC = amberCencrypt(textC, keyC, seed1C, seed2C);
    LOGD("envyptedC: %s", encryptedC);
    jstring encryptedJ = (*env)->NewStringUTF(env, (const char *)encryptedC);
    LOGD("envyptedJ: %s", encryptedJ);

    free(encryptedC);

    return encryptedJ;
}







#endif