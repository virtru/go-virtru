#ifndef VIRTRU_TDF3_SRC_VIRTRU_CONFIG_SERVICE_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_CONFIG_SERVICE_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ConfigService ConfigService;

DLL_PUBLIC ConfigService* VConfigServiceCreate(const char* configUrl);

// Destructor
DLL_PUBLIC void VConfigServiceDestroy(ConfigService* configService);


/// Get the config from Config Service
/// \param configKey - compound key of the configuration to get
/// \param outputFilePath - path to the file to save the output
DLL_PUBLIC VSTATUS VGetConfig(ConfigService* configService, const char* configKey, const char* outputFilePath);


/// Create the Config Service entry
/// \param configKey - compound key of the configuration to post
/// \param inputFilePath - path to the file to read the config from
DLL_PUBLIC VSTATUS VCreateConfig(ConfigService* configService, const char* configKey, const char* inputFilePath);


/// Returns Configuration Metadata for a given key.
/// \param configKey - compound key of the configuration to post
/// \param inputFilePath - path to the file to read the config
/// \return - Last-Modified Header value
DLL_PUBLIC char* VGetConfigMetaData(ConfigService* configService, const char* configKey);


/// Add additional header
/// \param key - name of the Header, e.g. Connection
/// \param value - value of the Header, e.g. keep-alive
DLL_PUBLIC void VAddHeader(ConfigService* configService, const char* key, const char* value);

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_CONFIG_SERVICE_C_H