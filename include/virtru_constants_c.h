/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/10/24.
//

#ifndef VIRTRU_TDF3_SRC_VIRTRU_CONSTANTS_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_CONSTANTS_C_H

#define LogDefaultError()    LogError("Default exception!");
#ifdef __ANDROID__
#include <android/log.h>
#define LOGE(message) __android_log_print(ANDROID_LOG_ERROR  , "VIRTRU_SDK", "Native error: %s", message)
#else
#define LOGE(message) LogError(message)
#endif

#if defined _WIN32 || defined WIN32  || defined _WINDOWS || defined __CYGWIN__
  #ifdef _DLL
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllexport))
    #else
      #define DLL_PUBLIC __declspec(dllexport) 
    #endif
  #else
    #ifdef __GNUC__
      #define DLL_PUBLIC __attribute__ ((dllimport))
    #else
      #define DLL_PUBLIC __declspec(dllimport) 
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
  #if __APPLE__
    #define DLL_PUBLIC __attribute__((visibility("default"))) __attribute__((used))
  #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Status code
typedef enum {
    VSTATUS_SUCCESS = 0,
    VSTATUS_FAILURE = 1, // Generic failure
    VSTATUS_INVALID_PARAMS = 2 // Check the input parameters if they are valid.
} VSTATUS;

// TDF Protocol
typedef enum {
    VProtocolZip = 0,
    VProtocolHtml = 1
} VProtocol;

/// Defines a log level.
typedef enum  {
    VLogLevelTrace = 0,  /// Most detailed output
    VLogLevelDebug,
    VLogLevelInfo,
    VLogLevelWarn,
    VLogLevelError,
    VLogLevelFatal  /// Least detailed output
} VLogLevel;

// Virtru client opaque object.
typedef void* VClientPtr;

// Virtru OIDC client opaque object
typedef void* VClientOidcPtr;

// Virtru storage type opaque object
typedef void* VTDFStorageTypePtr;

// Encrypt file params opaque object.
typedef void* VEncryptFileParamsPtr;

// Encrypt string params opaque object.
typedef void* VEncryptStringParamsPtr;

// Policy opaque object.
typedef void* VPolicyPtr;

typedef unsigned char* VBytesPtr;
typedef const unsigned char* VCBytesPtr;
typedef unsigned int VBytesLength;

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_CONSTANTS_C_H
