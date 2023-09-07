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

// DEPRECATED non-OIDC flows are deprecated, and should be dropped eventually
#ifndef VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_APPID_H
#define VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_APPID_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "virtru_credentials.h"

namespace virtru {
    class CredentialsAppId : public Credentials {
    public:
        /// Constructor
        /// \param owner - The owner email of the credentials
        /// \param appId - The AppId the credentials
        CredentialsAppId(const std::string& owner, const std::string& appId);

        //JAVACPPSKIPBEGIN
        /// Create a new instance of this object
        /// \return - The new instance
#ifndef SWIG
        virtual std::unique_ptr<Credentials> clone() const;
#endif
        //JAVACPPSKIPEND

        /// Destructor
        virtual ~CredentialsAppId();

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

        /// Get a debug-friendly string describing this credentials object
        /// \return - The type of this credentials instance as a string
        virtual std::string str() const;

    private:
        std::string m_owner;
        std::string m_appId;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_CREDENTIALS_APPID_H
