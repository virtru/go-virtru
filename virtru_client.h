/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/07/17.
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_CLIENT_H
#define VIRTRU_TDF3_SDK_VIRTRU_CLIENT_H

#include <string>
#include <vector>

#include "virtru_policy.h"
#include "virtru_encrypt_file_params.h"
#include "virtru_encrypt_stream_params.h"
#include "virtru_encrypt_data_params.h"
#include "virtru_encrypt_string_params.h"
#include "tdf_constants.h"
#include "virtru_credentials.h"

/// The Client is the entry point for all the major Virtru operations, such as encrypt, decrypt
/// and policy management. The user of this class should catch virtru::Expection for any failure.

namespace virtru {

    /// Forward declaration.
    class ILogger;
    class VirtruTDF3Builder;
    class EncryptFileParams;

    class Client {
    public:
        /// DEPRECATED in favor of OIDC client credential flows
        /// Constructs a new Client instance with owner and appId.
        /// \param owner - The owner's email address to be used to authenticate for encrypt, decrypt
        /// and policy management. Any data encrypted will be owned by the supplied email address.
        /// The owner will always have access to the encrypted data (TDF). 
        /// \param appId - The virtru application ID can be obtained from the 
        /// <a href="https://developer.virtru.com/docs/how-to-download-appid-token">Virtru Dashboard</a>
        Client(std::string owner, std::string appId);

        /// DEPRECATED in favor of OIDC client credential flows
        /// Constructs a new Client instance with owner and HMAC apiKey/apiSecret.  <a href="https://developer.virtru.com/docs/how-to-add-authentication#section-3-hmac-token-and-secret">Contact Virtru</a> to get your
        /// organization's HMAC apiKey/apiSecret 
        /// \param owner - The owner's email address to be used to authenticate  for encrypt, decrypt
        /// and policy management.
        /// \param apiKey - The HMAC api key
        /// \param apiSecret - The HMAC api secret
        Client(std::string owner, std::string apiKey, std::string apiSecret);

        /// Constructs a new Client instance with Owner and OIDC client credentials, associated with a specific
        /// organization/realm.
        /// \param owner - The owner's email address to be used to authenticate  for encrypt, decrypt
        /// \param organizationName - The OIDC realm or organization the client belongs to
        /// \param clientId - The clientId part of the client credentialset issued to the client
        /// \clientSecret - The clientSecret part of the client credentialset issued to the client
        Client(std::string owner, std::string organizationName, std::string clientId, std::string clientSecret);

        /// Constructs a new Client instance based on a Credentials object
        /// \param credentials - The Credentials object containing authorization details
        Client(const Credentials& credentials);

        /// Default constructor is not supported
        Client() = delete;

        /// Destroy the Client instance.
        ~Client();

        /// Copy constructor
        Client(const Client& client) = delete;

        /// Assignment operator
        Client& operator=(const Client& client)  = delete;

        /// Move copy constructor
        Client(Client&& client) = delete;

        /// Move assignment operator
        Client& operator=(Client&& client)  = delete;

    public: /// Optional \n
        ///
        /// Note: Defaults will be used if these methods are not used. \n
        ///

        /// Set the KAS url that will be used for TDF operations.  Optional - this method should be only used
        /// if you have your own key access server infrastructure.
        /// \param kasUrl - The KAS (Key Access Server) url
        void setKasUrl(const std::string& kasUrl);

        /// Set the OIDC provider url that the client will authenticate with, if using OIDC credentials.
        /// Optional - You should typically only set this if you're not using Virtru's OIDC provider.
        /// \param oidcUrl - The OIDC IdP (Identity Provider) url to use.
        void setOIDCProviderUrl(const std::string& oidcUrl);

	/// DEPRECATED OIDC auth flows do not use EAS.
        /// Set the EAS url that will be used for TDF operations.  Optional - this method should be only used
        /// if you have your own entity attribute server infrastructure.
        /// \param easUrl - The EAS (Entity Attribute Server) url
        void setEasUrl(const std::string& easUrl);

        /// Set the ACM url that will be used for TDF policy sync operations.  Optional - this method should be only used
        /// if you have your own acm server infrastructure.
        /// \param acmUrl - The ACM server url
        void setAcmUrl(const std::string& acmUrl);

        /// Set the secure reader url which will be used in html format TDF. This is the URL that will be used on opening
        /// the .html TDF. Optional - Should be only used if you host your own secure reader.
        /// \param srUrl - The secure reader url
        void setSecureReaderURL(const std::string& srUrl);

        /// Set the encrypted storage url that will be used for storing remote TDFs.
        /// Optional - this method should be only used if you have your own secure storage server infrastructure.
        /// \param encryptedStorageUrl - The encrypted storage url
        void setEncryptedStorageURL(const std::string& encryptedStorageUrl);

        /// Set the rca service url that will be used for storing remote TDFs.
        /// Optional - this method should be only used if you have your own rca service server infrastructure.
        /// \param rcaServiceURL -  The rca service url
        void setRCAServiceURL(const std::string& rcaServiceURL);

        /// Set the TDF protocol (format) to be used for encryption and decryption operations. HTML is the
        /// default format.  The protocols refer to the data format after encryption. 
        /// Options are .tdf (which is a zip) or HTML.
        /// \param protocol - type of the protocol (format)
        void setProtocol(Protocol protocol);

        /// Set the offline mode.
        /// \param state - If true, all the TDFs will be encrypted in offline mode that means the sysmetric key
        /// stored part of the TDF instead on the server.
        /// NOTE: This is same as setKeyAccessType
        void setOffline(bool state);

        /// Set the type of key access. The types of key access are 'Remote' and 'Wrapped'.
        ///     Remote - The key is stored on remote server.
        ///     Wrapped - The key is embedded in TDF.
        /// The default is the recommended type 'Remote' 
        /// \param keyAccessType - The key access type.
        void setKeyAccessType(KeyAccessType keyAccessType);

    public: /// Optional - Logging \n
        /// Enable the internal logger class to write logs to the console for given LogLevel. The default Loglevel is
        /// to keep the current level if not specified.
        /// \param logLevel - The log level
        void enableConsoleLogging(LogLevel logLevel = LogLevel::Current);

        //JAVACPPSKIPBEGIN
        /// Optional - Set the external logger instance. The internal logger will be used if the caller does not
        /// specify one.  The caller is responsible for ownership of the logger instance.\n
        /// \n NOTE: Once you use this method, the internal logger class is freed, and the internal logger will no longer be used.
        /// \param externalLogger - The external logger instance (std::shared_ptr).
        /// \param logLevel - The log level, the default is to keep the current level if not specified.
        void setExternalLogger(std::shared_ptr<ILogger> externalLogger, LogLevel logLevel = LogLevel::Current);
        //JAVACPPSKIPEND

    public: /// Optional - configure root CA's \n
        /// Set the cert authority which will be used in SSL handshake for all the network I/O. \n NOTE: This is 
        /// optional. If not specified, the SDK will supply a default.
        /// \param certAuthority - A string which holds the cert authority which will be used in SSL handshake
        /// for all the network I/O
        void setCertAuthority(const std::string& certAuthority);

    public: // Encrypt and Decrypt
        /// Encrypt the contents of the input file into a TDF. In the process of encryption, a policy is
        /// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
        /// \param encryptFileParams  - Object holding all the required information for encrypt operations
        /// \return Policy uuid of the TDF, can be used later to update the policy controls
        std::string encryptFile(const EncryptFileParams& encryptFileParam);

        /// Encrypt the contents of the input file into a RCA TDF. In the process of encryption, a policy is
        /// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
        /// \param encryptFileParams  - Object holding all the required information for encrypt operations
        /// \return std::pair of policy uuid and RCA tdf link. policy uuid can be used later to update the policy controls
        std::pair<std::string, std::string> encryptFileToRCA(const EncryptFileParams& encryptFileParam);

        /// Encrypt the contents of the stream into a TDF. In the process of encryption, a policy is
        /// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
        /// \param encryptStreamParams  - Object holding all the required information for encrypt operations
        /// \return Policy uuid of the TDF, can be used later to update the policy controls
        std::string encryptStream(const EncryptStreamParams& encryptStreamParams);

        //JAVACPPSKIPBEGIN
        /// Encrypt the plain data into a TDF. In the process of encryption, a policy is
        /// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
        /// \param encryptFileParam  - Object holding all the required information for encrypt operations
        /// \return std::pair of policy uuid and tdf data. policy uuid can be used later to update the policy controls
        std::pair<std::string, std::string> encryptString(const EncryptStringParams& encryptStringParams);
        //JAVACPPSKIPEND

        /// Encrypt the plain data into a remote TDF. In the process of encryption, a policy is
        /// associated with the TDF. The policy has a unique id which can be used to identify the TDF policy.
        /// \param encryptFileParam  - Object holding all the required information for encrypt operations
        /// \return std::pair of policy uuid and rca link. policy uuid can be used later to update the policy controls
        std::pair<std::string, std::string> encryptStringToRCA(const EncryptStringParams& encryptStringParams);

        /// Decrypt the contents of the TDF file into its original content.
        /// \param inFilepath - The TDF file on which the decryption is performed
        /// \param outFilepath - The file path of the original content after successful decryption
        void decryptFile(const std::string& inFilepath, const std::string& outFilepath);

        /// Decrypt the remote contents(RCA) file into its original content.
        /// \param rcaLink - The link contains the information of remote content
        /// \param outFilepath - The file path of the original content after successful decryption
        void decryptRCAToFile(const std::string& rcaLink, const std::string& outFilepath);

        /// Decrypt the contents of the TDF stream data into its original content.
        /// \param inStream - The TDF stream on which the decryption is performed
        /// \param outStream - The output stream with the original content after successful decryption
        void decryptStream(std::istream& inStream, std::ostream& outStream);

        /// Decrypt the TDF data
        /// \param tdfData - The tdf data to be decrypted.
        /// \return plain data - Return the decrypted tdf data.
        std::string decryptString(std::string tdfData);

        /// Decrypt the remote content TDF(RCA)
        /// \param rcaLink - The link contains the information of remote content
        /// \return plain data - Return the decrypted tdf data.
        std::string decryptRCAToString(const std::string& rcaLink);

    public: // Update policy
        /// Update the policy for a given TDF file using its policy uuid.
        /// \param policy - The policy object with new controls
        /// \param policyUUID - The policy uuid of the TDF
        void updatePolicyForUUID(const Policy& policy, const std::string& policyUUID);

        /// Update the policy for multiple TDFs using their policy uuids.
        /// \param policy - The policy object with new controls
        /// \param policyUUIDs - The vector of policy uuids for the TDFs
        void updatePolicyForUUIDs(const Policy& policy, const std::vector<std::string>& policyUUIDs);

        /// Update the policy for the given TDF file
        /// \param policy - The policy object with new controls
        /// \param tdfFile - The TDF file path
        void updatePolicyForFile(const Policy& policy, const std::string& tdfFile);

        /// Update the policy for multiple TDF files
        /// \param policy - The policy object with new controls
        /// \param files - List of TDF files
        void updatePolicyForFiles(const Policy& policy, const std::vector<std::string>& files);

        /// Revoke access for all the users that were granted access to the TDF file associated with the specified policy. The owner
        /// of the TDF will still have access.
        /// \param policyUUID - The policy uuid of the TDF
        void revokePolicy(const std::string& policyUUID);

        /// Revoke access for all users that were granted access to the TDF files associated with the specified policies. The owner
        /// of the TDF will still have access.
        /// \param policyUUIDs - Vector of policy uuids
        void revokePolicies(const std::vector<std::string>& policyUUIDs);

        /// Revoke access for all users that were granted access to the TDF file. The owner of the TDF will still have access.
        /// \param tdfFile - The TDF file
        void revokeFile(const std::string& tdfFile);

        /// Revoke access for all users that were granted acccess to the TDF files. The owner of the TDF will still have access.
        /// \param files - Vector of TDF files.
        void revokeFiles(const std::vector<std::string>& files);

    public: // Retrieve policy
        /// Return the policy associated with the given policyId.
        /// \param policyUUID - The policy uuid of the TDF.
        /// \return Policy - The policy associated with the TDF.
        Policy fetchPolicyForUUID(const std::string& policyUUID);

        /// Return the userId associated with this client according to the EntityObject
        /// \return userId - The userId associated with this client
        std::string getUserId();
    private:
        /// A helper method to update the TDF builder;
        void initClient();

        /// Prepare tdf3 builder object for encrypt.
        std::string prepareForEncrypt(const EncryptParams& encryptParams);

    private: /// Data
        std::unique_ptr<VirtruTDF3Builder> m_virtruTDF3Builder;
    };
}



#endif // VIRTRU_TDF3_SDK_VIRTRU_CLIENT_H
