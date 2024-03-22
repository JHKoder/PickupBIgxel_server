#include <jni.h>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <cstring>
#include <iostream>
#include <string>
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
        printf("-> %s == %s ",processName ,pe.szExeFile);
        return true;
//        if (processName.compare(pe.szExeFile) == 0) {
//            CloseHandle(hSnapshot);
//            return true;
//        }
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return false;
}


JNIEXPORT jboolean JNICALL Java_github_jhkoder_rest_system_ProcessAccessorWindows_isProcessRunning
    (JNIEnv *env, jobject obj1, jstring name, jstring extension) {
    const char *nameStr = env->GetStringUTFChars(name, nullptr);
    const char *extensionStr = env->GetStringUTFChars(extension, nullptr);
    std::cout << "2020년 3월 20일\n나는 잠도 못 자고 포스팅을 하고 있다.";

    std::string processName = std::string(nameStr) + std::string(extensionStr);

    // 여기서 processName을 사용하여 프로세스를 조회하고 처리하는 코드를 작성합니다.
    bool result = isProcessRunning(processName.c_str());

    env->ReleaseStringUTFChars(name, nameStr);
    env->ReleaseStringUTFChars(extension, extensionStr);

    return result ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jstring JNICALL Java_github_jhkoder_rest_system_ProcessAccessorWindows_getTargetProfile
    (JNIEnv *env, jobject obj1, jstring name, jstring extension){
    const char *str = "Hello from C!";

    // Java 문자열로 변환하여 반환
    return env->NewStringUTF(str);
}



/*

문자열 포인터 얻기
GetStringUTFChars() [UTF-8] env->GetStringUTFChars(str, nullptr);
GetStringChars() [UTF-16]

문자열에 할당한 메모리 해제
ReleaseStringUTFChars() [UTF-8] ReleaseStringUTFChars(name, cName);
ReleaseStringChars() [UTF-16]

문자열 길이
GetStringUTFLength() [UTF-8]
GetStringLength() [UTF-16]

자바 문자열 생성
NewStringUTF() [UTF-8] NewStringUTF("This is our string!");
NewString [UTF-16]

*/