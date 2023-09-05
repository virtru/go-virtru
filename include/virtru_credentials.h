/*
* Copyright © 2020 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Pat Mancuso on 2020/10/12
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_H
#define VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_H

#include <string>
#include <map>
#include <vector>
#include <memory>

namespace virtru {

    enum class CredentialsType {
        None   /// default - no credentials specified
        ,AppId /// AppId and email address
        ,HMAC  /// owner, apikey, and secret
        ,VJWT  /// issuer, tokenId, and secret
        ,OIDC  /// Open ID
    };

    class Credentials {
    public:
        /// Constructor
        /// \param type - The type of this credentials object, as specified by a CredentialsType enum value
        Credentials(CredentialsType type = CredentialsType::None);

        //JAVACPPSKIPBEGIN
        /// Create a new instance of this object
        /// \return - The new instance
#ifndef SWIG
        virtual std::unique_ptr<Credentials> clone() const;
#endif
        //JAVACPPSKIPEND

        /// Destructor
        virtual ~Credentials();

        /// Get the type of this credentials object, as specified by the CredentialsType enum value
        /// \return - The type enum value of this credentials instance
        CredentialsType getType() const;

        /// Get the type of this credentials object, as a string representation of the CredentialsType
        /// \return - The type of this credentials instance as a string
        std::string getTypeStr() const;

        /// Get a debug-friendly string describing this credentials object
        /// \return - The type of this credentials instance as a string
        virtual std::string str() const;

        //JAVACPPSKIPBEGIN
        /// Create the header key/value pairs that should be added to the request to establish authorization
        /// \param url - The full url for the request, including protocol prefix and parameter information
        /// \param method - The method for the request, such as 'get' or 'post'
        /// \param body - The body for the request, can be an empty string if there is no body content
        /// \param headers - a set of http header key/value pairs that should be included in calculations 
        /// \param date - the date string that should be used in calculations
	/// \return - map of key/value http header pairs
        virtual std::map<std::string, std::string> generateAuthHeaders(const std::string& url, const std::string& method, const std::string& body, const std::map<std::string, std::string> &headers, const std::string& date);
        //JAVACPPSKIPEND

        /// Get the userId associated with these credentials
        virtual std::string getUserId() const;

    protected:
        CredentialsType m_type;
        std::map<std::string, std::string> parseUrlTODO(const std::string& url) const;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_H
