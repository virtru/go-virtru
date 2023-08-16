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

#ifndef VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_FILE_PARAMS_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_FILE_PARAMS_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Create a new encrypt file param opaque object.
/// NOTE: The out file path will have .html/.tdf extension appended to
/// inFilePath based on protocol.
/// \param inFilePath - The file on which the encryption is performed
/// \return VEncryptFileParams opaque object.
/// NOTE: On failure returns NULL ptr.
DLL_PUBLIC VEncryptFileParamsPtr VEncryptFileParamsCreate1(const char* inFilePath);

/// Create a new encrypt file param opaque object.
/// \param inFilePath - The file on which the encryption is performed
/// \param outFilePath - The file path of the tdf after successful encryption
/// \return VEncryptFileParams opaque object.
/// NOTE: On failure returns NULL ptr.
DLL_PUBLIC VEncryptFileParamsPtr VEncryptFileParamsCreate2(const char* inFilePath, const char* outFilePath);

/// Destruct the EncryptFileParams instance.
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
DLL_PUBLIC void VEncryptFileParamsDestroy(VEncryptFileParamsPtr vEncryptFileParamsPtr);

///
/// The below methods are optional, if not specified the defaults are used.
///

/// Set the mime type (format) of the file that will be encrypted
/// NOTE: The default will be 'application/octet-stream' if not specified
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
/// \param mimeType - The mime type of the file, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptFileParamsSetMimeType(VEncryptFileParamsPtr vEncryptFileParamsPtr, const char* mimeType);

/// Set the policy that to be applied to the tdf
/// NOTE: If there is no policy defined for the tdf, default policy settings
/// will be applied
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptFileParamsSetPolicy(VEncryptFileParamsPtr vEncryptFileParamsPtr, VPolicyPtr vPolicyPtr);

/// Set the display name for the tdf, this name shows up on the Virtru dashboard
/// NOTE: If not set, the basename of inFilePath will be used
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
/// \param displayName - The display name for the tdf, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptFileParamsSetDisplayName(VEncryptFileParamsPtr vEncryptFileParamsPtr, const char* displayName);

/// Set the display message for the tdf, this message shows up on the Virtru dashboard
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
/// \param displayMessage - The display message for the tdf, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptFileParamsSetDisplayMessage(VEncryptFileParamsPtr vEncryptFileParamsPtr, const char* displayMessage);

/// Add access to the TDF file/data for the users in the list
/// \param vEncryptFileParamsPtr - The pointer to EncryptFileParams opaque object.
/// \param users - Share the TDF with the users in the users array
/// \param usersCount - Total user count in the array.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptFileParamsShareWithUsers(VEncryptFileParamsPtr vEncryptFileParamsPtr,const char ** users, unsigned int usersCount);

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_FILE_PARAMS_C_H
