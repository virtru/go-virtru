/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/10/18.
//

#ifndef __VIRTRU_CLIENT_C_H
#define __VIRTRU_CLIENT_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif
	/// Allows for .NET P/Invoke to free native memory
	/// \param vMemoryPtr - The malloc'd memory to be freed.
	DLL_PUBLIC VSTATUS VFreeMemory(void* vMemoryPtr);

	/// DEPRECATED in favor of OIDC client credential flows
	/// Create a new Virtru client instance with owner and appId.
	/// \param owner - The owner's email address to be used to authenticate for encrypt, decrypt
	/// and policy management. Any data encrypted will be owned by the supplied email address.
	/// The owner will always have access to the encrypted data (TDF).
	/// \param appId - The virtru application ID can be obtained from the
	/// <a href="https://developer.virtru.com/docs/how-to-download-appid-token">Virtru Dashboard</a>
	/// \return VirtruClient opaque object.
	/// NOTE: On failure returns NULL ptr.
	DLL_PUBLIC VClientPtr VClientCreateWithAppId(const char* owner, const char* appId);

	/// DEPRECATED in favor of OIDC client credential flows
	/// Create a new Virtru Client instance with owner and HMAC apiKey/apiSecret.
	/// <a href="https://developer.virtru.com/docs/how-to-add-authentication#section-3-hmac-token-and-secret">Contact Virtru</a> to get your
	/// organization's HMAC apiKey/apiSecret
	/// \param owner - The owner's email address to be used to authenticate  for encrypt, decrypt
	/// and policy management.
	/// \param apiKey - The HMAC api key
	/// \param apiSecret - The HMAC api secret
	/// \return VirtruClient opaque object.
	/// NOTE: On failure returns NULL ptr.
	DLL_PUBLIC VClientPtr VClientCreateWithHMAC(const char* owner, const char* apiKey, const char* apiSecret);

	/// Create a new Virtru Client instance with owner and organization/realm-scoped OIDC client credentials.
	/// <a href="TBDLINK">Contact Virtru</a> to get client credentials for clients in your organization
	/// \param owner - The owner's email address to be used to authenticate  for encrypt, decrypt
	/// \param organizationName - The OIDC realm or organization the client belongs to
	/// \param clientId - The clientId part of the client credentialset issued to the client
	/// \clientSecret - The clientSecret part of the client credentialset issued to the client
	/// \return VirtruClient opaque object.
	/// NOTE: On failure returns NULL ptr.
	DLL_PUBLIC VClientPtr VClientCreateWithOIDC(const char* owner, const char* organizationName, const char* clientId, const char* clientSecret);

	/// Destruct the Virtru client instance.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	DLL_PUBLIC void VClientDestroy(VClientPtr vClientPtr);

	/// Enable the internal logger class to write logs to the console for given LogLevel.
	/// The default logLevel is 'Warn'
	DLL_PUBLIC VSTATUS VEnableConsoleLogging(VClientPtr vClientPtr, VLogLevel logLevel);

	/// Set the TDF protocol (format) to be used for encryption and decryption operations. HTML is the
	/// default format.  The protocols refer to the data format after encryption.
	/// Options are .tdf (which is a zip) or HTML.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vProtocol - type of the protocol (format)
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VSetProtocol(VClientPtr vClientPtr, VProtocol vProtocol);

	/// Set the offline mode.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param state - If true, all the TDFs will be encrypted in offline mode that means the symmetric key
	/// stored part of the TDF instead on the server.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VSetOffline(VClientPtr vClientPtr, bool state);

	/// Encrypt the contents of the input file into a TDF. In the process of encryption, a policy is
	/// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vEncryptFileParamsPtr  - Encrypt file param opaque object holding all the required information for encrypt operations
	/// \param outPolicyId  - On success, it contains policy id.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free outPolicyId buffer.
	DLL_PUBLIC VSTATUS VClientEncryptFile(VClientPtr vClientPtr, VEncryptFileParamsPtr vEncryptFileParamsPtr, char** outPolicyId);

	/// Encrypt the contents of the input file into a RCA TDF. In the process of encryption, a policy is
	/// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vEncryptFileParamsPtr  - Encrypt file param opaque object holding all the required information for encrypt operations
	/// \param outPolicyId  - On success, it contains policy id.
	/// \param outRcaLink  - On success, it contains RCA tdf link.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free outPolicyId buffer and outRcaLink.
	DLL_PUBLIC VSTATUS VClientEncryptFileToRCA(VClientPtr vClientPtr, VEncryptFileParamsPtr vEncryptFileParamsPtr, char** outPolicyId, char** outRcaLink);

	/// Decrypt the contents of the TDF file into its original content.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param inFilepath - The TDF file on which the decryption is performed
	/// \param outFilepath - The file path of the original content after successful decryption
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientDecryptFile(VClientPtr vClientPtr, const char* inFilepath, const char* outFilepath);

	/// Decrypt the remote contents(RCA) file into its original content.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param rcaLink - The link contains the information of remote content
	/// \param outFilepath - The file path of the original content after successful decryption
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientDecryptRCAToFile(VClientPtr vClientPtr, const char* rcaLink, const char* outFilepath);

	/// Decrypt the remote content TDF(RCA)
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param rcaLink - The link contains the information of remote content
	/// \param outString - On success, it contains RCA tdf link.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientDecryptRCAToString(VClientPtr vClientPtr, const char* rcaLink, char** outString);

	/// Encrypt the plain data into a TDF. In the process of encryption, a policy is
	/// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vEncryptStringParamsPtr  - Encrypt string param opaque object holding all the required information for encrypt operations
	/// \param outPolicyId  - On success, it contains policy id.
	/// \param outBytesPtr  - On success, it contains the encrypted tdf data.
	/// \param outBytesLength  - On success, it is length of the encrypted tdf data.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free outPolicyId buffer and outBytesPtr.
	DLL_PUBLIC VSTATUS VClientEncryptString(VClientPtr vClientPtr, VEncryptStringParamsPtr vEncryptStringParamsPtr,
		char** outPolicyId, VBytesPtr* outBytesPtr, VBytesLength* outBytesLength);

	/// Encrypt the plain data into a remote TDF. In the process of encryption, a policy is
	/// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vEncryptStringParamsPtr  - Encrypt string param opaque object holding all the required information for encrypt operations
	/// \param outPolicyId  - On success, it contains policy id.
	/// \param outRcaLink  - On success, it contains RCA tdf link.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free outPolicyId buffer and outRcaLink.
	DLL_PUBLIC VSTATUS VClientEncryptStringToRCA(VClientPtr vClientPtr, VEncryptStringParamsPtr vEncryptStringParamsPtr, char** outPolicyId, char** outRcaLink);

	/// Decrypt the TDF data
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param inBytesPtr  - Pointer to buffer containing the TDF data.
	/// \param inBytesLength  - Length of buffer containing the TDF data.
	/// \param outBytesPtr  - On success, it contains the decrypted tdf data.
	/// \param outBytesLength  - On success, it is length of the decrypted tdf data.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free outBytesPtr.
	DLL_PUBLIC VSTATUS VClientDecryptString(VClientPtr vClientPtr, VCBytesPtr inBytesPtr,
		VBytesLength inBytesLength, VBytesPtr* outBytesPtr, VBytesLength* outBytesLength);

	/// Return the policy associated with the given policy uuid.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param policyUUID - The unique policy uuid.
	/// \param vPolicyPtr - On success, it hold the ptr to the policy object.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	/// NOTE: The caller of the api should free vPolicyPtr.
	DLL_PUBLIC VSTATUS VClientFetchPolicyForUUID(VClientPtr vClientPtr, const char* policyUUID, VPolicyPtr* vPolicyPtr);
	
	/// Update the policy for a given TDF file using its policy uuid.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vPolicyPtr - The pointer to Virtru policy opaque object.
	/// \param policyUUID - The policy uuid of the TDF
	DLL_PUBLIC VSTATUS VClientUpdatePolicyForUUID(VClientPtr vClientPtr, VPolicyPtr vPolicyPtr, const char* policyUUID);

	/// Update the policy for a given TDF file.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param vPolicyPtr - The pointer to Virtru policy opaque object.
	/// \param tdfFile - The TDF file path
	DLL_PUBLIC VSTATUS VClientUpdatePolicyForFile(VClientPtr vClientPtr, VPolicyPtr vPolicyPtr, const char* tdfFile);

	/// Revoke access for all the share users of the tdf files using the policy uuid.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param policyUUID - The policy uuid of the TDF
	DLL_PUBLIC VSTATUS VClientRevokePolicy(VClientPtr vClientPtr, const char* policyUUID);

	/// Revoke access for all the share users of the tdf file.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param tdfFile - The TDF file path
	DLL_PUBLIC VSTATUS VClientRevokeFile(VClientPtr vClientPtr, const char* tdfFile);

	/// Set the KAS url that will be used for tdf3 operations.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param kasUrl - The base URL for KAS communication.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientSetKasUrl(VClientPtr vClientPtr, const char* kasUrl);

	/// Set the OIDC IdP url that will be used to authenticate against.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param oidcUrl - The base URL for the OIDC IdP (e.g. Keycloak) for the client to authenticate against.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientSetOIDCProviderUrl(VClientPtr vClientPtr, const char* oidcUrl);

	/// DEPRECATED OIDC auth flows do not use EAS.
	///  Set the EAS url that will be used for tdf3 operations.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param easUrl - The base URL for EAS communication.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientSetEasUrl(VClientPtr vClientPtr, const char* easUrl);


	/// Set the ACM url that will be used for TDF policy sync operations.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param acmUrl - The base URL for ACM communication.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientSetAcmUrl(VClientPtr vClientPtr, const char* acmUrl);

	/// Set the secure reader url which will be used in html tdf.
	/// \param vClientPtr - The pointer to Virtru client opaque object.
	/// \param srUrl - The URL for Secure reader.
	/// \return VSTATUS - VSTATUS_SUCCESS on success
	DLL_PUBLIC VSTATUS VClientSetSecureReaderUrl(VClientPtr vClientPtr, const char* srUrl);


#ifdef __cplusplus
}
#endif

#endif // __VIRTRU_CLIENT_C_H
