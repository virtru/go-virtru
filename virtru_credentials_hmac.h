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
#ifndef VIRTRU_CREDENTIALS_HMAC_H_
#define VIRTRU_CREDENTIALS_HMAC_H_

#include "virtru_credentials.h"

// DEPRECATED non-OIDC flows are deprecated, and should be dropped eventually
namespace virtru {
    class CredentialsHmac : public Credentials {
      public:
        /// Constructor
        /// \param userId - The userId of the credentials
        /// \param apiKey - The apiKey of the credentials
        /// \param apiSecret - The API secret of the credentials
        CredentialsHmac(const std::string &userId, const std::string &apiKey, const std::string &apiSecret);

        //JAVACPPSKIPBEGIN
        /// Create a new instance of this object
        /// \return - The new instance
#ifndef SWIG
        virtual std::unique_ptr<Credentials> clone() const;
#endif
        //JAVACPPSKIPEND

        /// Destructor
        virtual ~CredentialsHmac();

        //JAVACPPSKIPBEGIN
        /// Create the header key/value pairs that should be added to the request to establish authorization
        /// \param url - The full url for the request, including protocol prefix and parameter information
        /// \param method - The method for the request, such as 'get' or 'post'
        /// \param body - The body for the request, can be an empty string if there is no body content
        /// \param headers - a set of http header key/value pairs that should be included in calculations
        /// \param date - the date string that should be used in calculations
        /// \return - map of key/value http header pairs
        virtual std::map<std::string, std::string> generateAuthHeaders(const std::string &url, const std::string &method, const std::string &body, const std::map<std::string, std::string> &headers, const std::string &date);
        //JAVACPPSKIPEND

        /// Get the userId associated with these credentials
        virtual std::string getUserId() const;

        /// Get a debug-friendly string describing this credentials object
        /// \return - The type of this credentials instance as a string
        virtual std::string str() const;

      private:
        std::string m_userId;
        std::string m_apiKey;
        std::string m_apiSecret;
    };
} // namespace virtru
#endif // VIRTRU_CREDENTIALS_HMAC_H_
