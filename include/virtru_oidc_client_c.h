//
//  Virtru TDF3 SDK
//
//  Created by Pat Mancuso on 2023/09/09.
//  Copyright 2023 Virtru. All rights reserved.
//

#ifndef __VIRTRU_OIDC_CLIENT_C_H
#define __VIRTRU_OIDC_CLIENT_C_H

#include <virtru_client.h>
#include <virtru_client_c.h>
#include <tdf_constants.h>

#include "virtru_oidc_client.h"
#include "virtru_oidc_client_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Create a Virtru client instance
/// \param attributesInfoAsJson - json describing the mapping between attributes and KAS URLs
/// \param kasInfoAsJson - json describing the mapping between KAS URLs and credentials
/// \return completion status of the operation
DLL_PUBLIC VClientOidcPtr VClientOidcCreate(const std::string& attributesInfoAsJson, const std::string& kasInfoAsJson);

/// Destruct the Virtru client instance.
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOidcDestroy(VClientOidcPtr vClientPtr);

/// Add attributes that will applied for all TDFs creating by this instance
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \param attName - Attribute name
/// \param attValue - Attribute value
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOIDCAddAttribute(VClientOidcPtr vClientPtr, const char* attName, const char* attValue);

/// Encrypt the file to tdf format.
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \param vStoragePtr - The storage handle for the TDF
/// \param outFilepath - path and filename where the tdf will be written
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOidcEncryptFile(VClientOidcPtr vClientPtr, VTDFStorageTypePtr vStoragePtr, const char *outFilepath);

/// Decrypt the contents of the TDF file into its original content.
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \param vStoragePtr - The storage handle for the TDF
/// \param outFilepath - path and filename where the plaintext will be written
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOidcDecryptFile(VClientOidcPtr vClientPtr, VTDFStorageTypePtr vStoragePtr, const char* outFilepath);

/// Encrypt the bytes to tdf format.
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \param vStoragePtr - The storage handle for the TDF
/// \param outBytesPtr - return value, pointer to buffer containing plaintext
/// \param outBytesLength - return value, pointer to length of plaintext
/// NOTE: The caller is responsible for freeing the malloc'ed storage pointed to by outBytesPtr
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOidcEncryptData(VClientOidcPtr vClientPtr, VTDFStorageTypePtr vStoragePtr, VBytesPtr* outBytesPtr,
                                          VBytesLength* outBytesLength);

/// Decrypt the TDF data into a buffer
/// \param vClientPtr - handle to ClientOidc object created with VClientOidcCreate
/// \param tdfStoragePtr - The storage handle for the TDF
/// \param outBytesPtr - return value, pointer to buffer containing plaintext
/// \param outBytesLength - return value, pointer to length of plaintext
/// NOTE: The caller is responsible for freeing the malloc'ed storage pointed to by outBytesPtr
/// \return completion status of the operation
DLL_PUBLIC VSTATUS VClientOidcDecryptData(VClientOidcPtr vClientPtr, VTDFStorageTypePtr vStoragePtr, VBytesPtr* outBytesPtr,
                                          VBytesLength* outBytesLength);

#ifdef __cplusplus
}
#endif

#endif // __VIRTRU_OIDC_CLIENT_C_H
