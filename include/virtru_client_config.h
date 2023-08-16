//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/07/12
//  Copyright © 2019 Virtru. All rights reserved.

#ifndef VIRTRU_TDF3_VIRTRU_CLIENT_CONFIG_H
#define VIRTRU_TDF3_VIRTRU_CLIENT_CONFIG_H

#include <string>

namespace virtru {

    /// A virtru client configuration information class(singleton) hold all the endpoint addresses and
    /// other information like platform it's being used.
    class ClientConfig {
    public: // Interface

        /// Returns the singleton instance of ClientConfig, if the instance is not yet created it will create one.
        /// \return - Returns single instance of the ClientConfig.
        static ClientConfig &getInstance();

        /// Sets the base URL for KAS communication
		/// \param kasUrl - The base URL for KAS
        void setKasUrl(const std::string& kasUrl);

        /// Return the base URL for KAS communication
        /// \return - The current base KAS url value
        std::string getKasUrl() const;

        /// Sets the base URL that client will authenticate against
	/// \param oidcUrl - The base URL for the OIDC IdP
        void setOIDCUrl(const std::string& oidcUrl);

        /// Return the base URL that client will authenticate against
	/// \return oidcUrl - The base URL for the OIDC IdP
        std::string getOIDCUrl() const;

        /// DEPRECATED - EAS is not used in OIDC flows
        /// Sets the base URL for EAS server communication
        /// \param easUrl - The base URL for EAS
        void setEasUrl(const std::string& easUrl);

        /// DEPRECATED - EAS is not used in OIDC flows
        /// Return the base URL for EAS server communication
        /// \return - The current EAS url value
        std::string getEasUrl() const;

        /// Sets the base URL for ACM server communication
        /// \param acmUrl - The base URL for ACM
        void setAcmUrl(const std::string& acmUrl);

        /// Return the base URL for ACM server communication
        /// \return - The current ACM url value
        std::string getAcmUrl() const ;

        /// Sets the base URL for RCA server communication
        /// \param rcaUrl - The base URL for RCA
        void setRcaUrl(const std::string& rcaUrl);

        /// Return the base URL for RCA server communication
        /// \return - The current RCA url value
        std::string getRcaUrl() const;

        /// Sets the base URL for encrypted storage server communication
        /// \param encryptedStorageUrl - The base URL for encrypted storage
        void setEncryptedStorageUrl(const std::string& encryptedStorageUrl);

        /// Return the base URL for  encrypted storage server communication
        /// \return - The current  encrypted storage url value
        std::string getEncryptedStorageUrl() const;

        /// Set the secure reader url which will be used in html format TDF. This is the URL that will be used on opening
        /// the .html TDF.
        /// \param srUrl - The secure reader url
        void setSecureReaderUrl(const std::string& srUrl);

        /// Return the secure reader url which will be used in html format TDF
        /// \return - The secure reader url value
        std::string getSecureReaderUrl() const;

        /// Set the current platform the SDK is being used (ex: cpp, python,...)
        /// \param platform - The current platform of the SDK
        void setPlatform(const std::string& platform);

        /// Return the current platform of this SDK.
        /// \return platform - The current platform of the SDK
        std::string getPlatform() const;

        /// Return virtru client value which is passed as HTTP header value while communicating with Virtru servers
        /// \return The virtru client value
        std::string getVirtruClient() const;

        /// Return virtru client build version
        /// \return The virtru client build version
        std::string getBuildVersion() const;

        //TODO: Return the user agent passed on SDK platform.

    protected:
        /// Constructs a new ClientConfig instance.
        ClientConfig();

        /// Destructor
        ~ClientConfig() = default;

    private:
        std::string m_kasUrl;
        std::string m_oidcUrl;
        std::string m_easUrl;
        std::string m_acmUrl;
        std::string m_rcaUrl;
        std::string m_encryptedStorageUrl;
        std::string m_secureReaderUrl;
        std::string m_platform;
    };

}


#endif // VIRTRU_TDF3_VIRTRU_CLIENT_CONFIG_H
