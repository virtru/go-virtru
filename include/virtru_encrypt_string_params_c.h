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

#ifndef VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_STRING_PARAMS_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_STRING_PARAMS_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Create a new encrypt string param opaque object.
/// \param vBytesPtr - Const pointer to the data buffer.
/// \param vBytesLength - The file on which the encryption is performed
/// \return VEncryptStringParams opaque object.
/// NOTE: On failure returns NULL ptr.
DLL_PUBLIC VEncryptStringParamsPtr VEncryptStringParamsCreate(VCBytesPtr vBytesPtr, VBytesLength vBytesLength);

/// Destruct the EncryptStringParams instance.
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
DLL_PUBLIC void VEncryptStringParamsDestroy(VEncryptStringParamsPtr vEncryptStringParamsPtr);

///
/// The below methods are optional, if not specified the defaults are used.
///

/// Set the mime type (format) of the file that will be encrypted
/// NOTE: The default will be 'application/octet-stream' if not specified
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
/// \param mimeType - The mime type of the file, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptStringParamsSetMimeType(VEncryptStringParamsPtr vEncryptStringParamsPtr, const char* mimeType);

/// Set the policy that to be applied to the tdf
/// NOTE: If there is no policy defined for the tdf, default policy settings
/// will be applied
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptStringParamsSetPolicy(VEncryptStringParamsPtr vEncryptStringParamsPtr, VPolicyPtr vPolicyPtr);

/// Set the display name for the tdf, this name shows up on the Virtru dashboard
/// NOTE: If not set, the basename of inFilePath will be used
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
/// \param displayName - The display name for the tdf, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptStringParamsSetDisplayName(VEncryptStringParamsPtr vEncryptStringParamsPtr, const char* displayName);

/// Set the display message for the tdf, this message shows up on the Virtru dashboard
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
/// \param displayMessage - The display message for the tdf, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptStringParamsSetDisplayMessage(VEncryptStringParamsPtr vEncryptStringParamsPtr, const char* displayMessage);

/// Add access to the TDF file/data for the users in the list
/// \param vEncryptStringParamsPtr - The pointer to EncryptStringParams opaque object.
/// \param users - Share the TDF with the users in the users array
/// \param usersCount - Total user count in the array.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEncryptStringParamsShareWithUsers(VEncryptStringParamsPtr vEncryptStringParamsPtr, const char ** users, unsigned int usersCount);

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_ENCRYPT_STRING_PARAMS_C_H
