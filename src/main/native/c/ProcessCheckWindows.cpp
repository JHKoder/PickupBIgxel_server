#include <jni.h>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <cstring>
#include <iostream>
#include <cstring>
#include <chrono>
#include <string>
#include <ctime>

#include "../h/github_jhkoder_rest_system_ProcessAccessorWindows.h"

bool isProcessRunning(const char* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe)) {
        CloseHandle(hSnapshot);
        return false;
    }

    do {
        if (strcmp(processName, pe.szExeFile) == 0) {
        CloseHandle(hSnapshot);
        return true;
    }

std::cout << "-> " << processName << " == " << pe.szExeFile << " \n";
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return false;
}


JNIEXPORT jboolean JNICALL Java_github_jhkoder_rest_system_ProcessAccessorWindows_isProcessRunning
    (JNIEnv *env, jobject obj1, jstring name, jstring extension) {
    const char *nameStr = env->GetStringUTFChars(name, nullptr);
    const char *extensionStr = env->GetStringUTFChars(extension, nullptr);

    std::string processName = std::string(nameStr) + std::string(extensionStr);

    // 여기서 processName을 사용하여 프로세스를 조회하고 처리하는 코드를 작성합니다.
    bool result = isProcessRunning(processName.c_str());

    env->ReleaseStringUTFChars(name, nameStr);
    env->ReleaseStringUTFChars(extension, extensionStr);

    return result ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jobject JNICALL Java_github_jhkoder_rest_system_ProcessAccessorWindows_getTargetProfile
    (JNIEnv *env, jobject obj1, jstring name, jstring extension){
    // Java의 String 객체를 C++의 const char*로 변환
    const char *nameStr = env->GetStringUTFChars(name, nullptr);
    const char *extensionStr = env->GetStringUTFChars(extension, nullptr);

    // 프로세스 리소스 정보 가져오기 및 계산
    double cpuUsage = 0.0; // CPU 사용량 계산
    double memoryUsage = 0.0; // 메모리 사용량 계산

    // 프로세스 시작 시간 가져오기
    jlong startTimeMillis = std::chrono::system_clock::now().time_since_epoch().count();
    jobject startTime = env->NewObject(env->FindClass("java/util/Date"), env->GetMethodID(env->FindClass("java/util/Date"), "<init>", "(J)V"), startTimeMillis);

    // ProcessResourceResponse 객체 생성
    jclass prrClass = env->FindClass("ProcessResourceResponse");
    jmethodID constructor = env->GetMethodID(prrClass, "<init>", "(Ljava/util/Date;DD)V");
    jobject result = env->NewObject(prrClass, constructor, startTime, cpuUsage, memoryUsage);

    // Java의 String 객체 반환 및 메모리 해제
    env->ReleaseStringUTFChars(name, nameStr);
    env->ReleaseStringUTFChars(extension, extensionStr);

    return result;
}
