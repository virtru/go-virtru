//
//  Virtru TDF3 SDK
//
//  Created by Pat Mancuso on 2019/05/06
//  Copyright � 2019 Virtru. All rights reserved.

#ifndef VIRTRU_TDF3_SDK_CONSTANTS_H
#define VIRTRU_TDF3_SDK_CONSTANTS_H

namespace virtru {

    constexpr auto kKasUrl = "https://api.virtru.com/kas";
    constexpr auto kAcmUrl = "https://api.virtru.com/acm";
    constexpr auto kEasUrl = "https://api.virtru.com/accounts";
    constexpr auto kRcaUrl = "https://api.virtru.com/rca";
    constexpr auto kEncryptedStorageUrl = "https://api.virtru.com/encrypted-storage";

    constexpr auto kSecureReaderUrl = "https://secure.virtru.com/start?htmlProtocol=1";
    static constexpr auto kKasUrlUpsert = "/upsert";
    static constexpr auto kEntityobjectURL = "/entityobject";
    static constexpr auto kUserSettingsURL = "/userSettings";
    static constexpr auto kRegisterClientPubKey = "/appIdBundle/public-key";
    static constexpr auto kRevokeUrl = "/api/policies/revoke";
    static constexpr auto kPoliciesUrl = "/api/policies";

    static constexpr auto kAcceptHeaderKey = "Accept";
    static constexpr auto kAcceptHeaderValue = "application/json";
    static constexpr auto kUserAgentHeaderKey = "User-Agent";
    static constexpr auto kVirtruSignedRequestToken = "x-virtru-signed-request-token";
    static constexpr auto kDefaultSegmentSize = (2 * 1024 * 1024);

    // Virtru control flags
    static constexpr auto kFlagReshare = "forward";
    static constexpr auto kFlagOneClick = "no-auth";
    static constexpr auto kFlagWatermark = "watermark";
    static constexpr auto kFlagPrint = "print";
    static constexpr auto kFlagCopy = "copy";
    static constexpr auto kFlagPersistentProtection = "persistent-protection";
    static constexpr auto kFlagPreventDownload = "prevent-download";

    static constexpr auto kFlagExpiration = "expiration";

    static constexpr auto kTDFOwner = "owner";
    static constexpr auto kPolicyOwner = "owner";
    static constexpr auto kDisplayName = "displayName";
    static constexpr auto kDisplayMessage = "displayMessage";
    static constexpr auto kFileProvider = "fileProvider";

    static constexpr auto kEmail = "email";
    static constexpr auto kUuid = "uuid";
    static constexpr auto kUuids = "uuids";
    static constexpr auto kDissems = "dissems";
    static constexpr auto kSimplePolicy = "simplePolicy";
    static constexpr auto kEmailUsers = "emailUsers";
    static constexpr auto kAuthorizations = "authorizations";
    static constexpr auto kState = "state";
    static constexpr auto kStateActive = "active";
    static constexpr auto kStateDeactivated = "deactivated";
    static constexpr auto kActiveBegin = "activeBegin";
    static constexpr auto kActiveEnd = "activeEnd";
    static constexpr auto kIsManaged = "isManaged";
    static constexpr auto kAccessedBy = "accessedBy";

    static constexpr auto k_Id = "_id";
    static constexpr auto k_Rev = "_rev";
    static constexpr auto kId = "id";
    static constexpr auto kVersion = "version";
    static constexpr auto kType = "type";
    static constexpr auto kOwner = "owner";
    static constexpr auto kLicenseOwnerId = "licenseOwnerId";
    static constexpr auto kKey = "key";
    static constexpr auto kValue = "value";
    static constexpr auto kVirtruDataOwner = "virtru:data:owner";

    static constexpr auto kHtmlTDFExtension = ".html";
    static constexpr auto kZipTDFExtension = ".tdf";

    static constexpr auto kCPPFileProvider = "virtru-sdk-cpp";
    static constexpr auto kDefaultDisplayMessage = "Encrypted using Virtru C++ SDK";
    static constexpr auto kPythonDisplayMessage = "Encrypted using Virtru Python SDK";
    static constexpr auto kPythonFileProvider = "virtru-sdk-python";

    static constexpr auto kCPPPlatform = "virtru-sdk-cpp";
    static constexpr auto kPythonPlatform = "virtru-sdk-python";

    /// User Settings
    static constexpr auto kAppIdBundle = "appIdBundle";
    static constexpr auto kOrgPublicKey = "orgPublicKey";
    static constexpr auto kDelegatedKey = "delegatedKey";
    static constexpr auto kFingerprint = "fingerprint";
    static constexpr auto kPublicKeyFingerprint = "publicKeyFingerprint";

}

#endif
