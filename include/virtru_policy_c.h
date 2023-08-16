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

#ifndef VIRTRU_TDF3_SRC_VIRTRU_POLICY_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_POLICY_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Create a new policy opaque object.
/// \return VPolicyPtr opaque object.
/// NOTE: On failure returns NULL ptr.
DLL_PUBLIC VPolicyPtr VPolicyCreate();

/// Destruct the policy instance.
/// \param vPolicyPtr - The pointer to policy opaque object.
DLL_PUBLIC void VPolicyDestroy(VPolicyPtr vPolicyPtr);

/// Set the owner of the policy
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param owner - The owner's email address, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
/// NOTE: By default, the owner is the address that was used when the client instance was created.
/// This method will change the owner to the specified email address for the instance.
DLL_PUBLIC VSTATUS VSetOwner(VPolicyPtr vPolicyPtr, const char* owner);

/// Get the owner of the policy
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param owner - The owner's email address, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
/// NOTE: The caller is responsible for freeing the owner.
DLL_PUBLIC VSTATUS VGetOwner(VPolicyPtr vPolicyPtr, char** owner);

/// Add access to the TDF file/data for the users in the array
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param users - Share the TDF with the users in the users array
/// \param usersCount - Total user count in the array.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VShareWithUsers(VPolicyPtr vPolicyPtr, const char ** users, unsigned int usersCount);

/// Remove access to the TDF file/data for the users in the array
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param users - Share the TDF with the users in the users array
/// \param usersCount - Total user count in the array.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VRemoveUsers(VPolicyPtr vPolicyPtr, const char ** users, unsigned int usersCount);

/// Return all the user who have access to the TDF.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param users - Holds the users who have access to the TDF.
/// \param usersCount - Total shared user count.
/// \return VSTATUS - VSTATUS_SUCCESS on success
/// NOTE: The caller is responsible for freeing users array.
DLL_PUBLIC VSTATUS VGetSharedUsers(VPolicyPtr vPolicyPtr, char*** users, unsigned int* usersCount);

/// Turns on reshare policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnableReshare(VPolicyPtr vPolicyPtr);

/// Turns off reshare policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisableReshare(VPolicyPtr vPolicyPtr);

/// Return the status of 'Reshare' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'Reshare' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsReshareEnabled(VPolicyPtr vPolicyPtr, bool* flag);

/// Turns on watermarking policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnableWatermarking(VPolicyPtr vPolicyPtr);

/// Turns off watermarking policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisableWatermarking(VPolicyPtr vPolicyPtr);

/// Return the status of 'Watermarking' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'Watermarking' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsWatermarkingEnabled(VPolicyPtr vPolicyPtr, bool* flag);

/// Turns on print policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnablePrint(VPolicyPtr vPolicyPtr);

/// Turns off print policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisablePrint(VPolicyPtr vPolicyPtr);

/// Return the status of 'Print' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'Print' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsPrintEnabled(VPolicyPtr vPolicyPtr, bool* flag);

/// Turns on copy policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnableCopy(VPolicyPtr vPolicyPtr);

/// Turns off copy policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisableCopy(VPolicyPtr vPolicyPtr);

/// Return the status of 'Copy' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'Copy' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsCopyEnabled(VPolicyPtr vPolicyPtr, bool* flag);

/// Turns on persistent protection policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnablePersistentProtection(VPolicyPtr vPolicyPtr);

/// Turns off persistent protection policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisablePersistentProtection(VPolicyPtr vPolicyPtr);

/// Return the status of 'PersistenProtection' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'PersistentProtection' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsPersistentProtection(VPolicyPtr vPolicyPtr, bool* flag);

/// Turns on prevent download policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VEnablePreventDownload(VPolicyPtr vPolicyPtr);

/// Turns off prevent download policy control flag
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VDisablePreventDownload(VPolicyPtr vPolicyPtr);

/// Return the status of 'PreventDownload' control flag.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param flag - True, if 'PreventDownload' control flag is set.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VIsPreventDownloadEnabled(VPolicyPtr vPolicyPtr, bool* flag);

/// Set the expiration in minutes\n
/// Access to the TDF data will be revoked for all users in the number of minutes specified, starting from the time this call is made.  The owner will retain access after the expiration time is reached.
/// \param mins - minutes until expiration
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VExpireInMins(VPolicyPtr vPolicyPtr, unsigned int mins);

/// Set the expiration in days\n
/// Access to the TDF data will be revoked for all users in the number of days specified, starting from the time this call is made.  The owner will retain access after the expiration time is reached.
/// \param days - days until expiration
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VExpireInDays(VPolicyPtr vPolicyPtr, unsigned int days);

/// Access to the TDF data will be revoked for all users at the specified date.  The owner will retain access after the expiration time is reached.
/// The expiration date is specified in ISO-8601 format, and can include a time component.  Ex: 2019-05-24T16:12:41Z
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param expirationDate - Expiration date when the TDF will expire, null terminated string.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VAddExpiration(VPolicyPtr vPolicyPtr, const char* expirationDate);

/// Remove the expiration
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \return VSTATUS - VSTATUS_SUCCESS on success
DLL_PUBLIC VSTATUS VRemoveExpiration(VPolicyPtr vPolicyPtr);

/// Return the expiration time(in ISO-8601 format) of the TDF.
/// \param vPolicyPtr - The pointer to policy opaque object.
/// \param expirationTimeStamp - The expiration time(in ISO-8601 format) of the TDF.
/// \return VSTATUS - VSTATUS_SUCCESS on success
/// NOTE: The caller is responsible for freeing the expirationTimeStamp.
DLL_PUBLIC VSTATUS VGetExpiration(VPolicyPtr vPolicyPtr, char** expirationTimeStamp);

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_POLICY_C_H
