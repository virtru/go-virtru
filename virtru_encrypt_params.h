/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/09/25.
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_PARAM_H
#define VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_PARAM_H

#include <string>
#include "virtru_policy.h"

namespace virtru {

    /// Forward declaration
    class Client;

    class EncryptParams {
    public:
        /// Destructor
        ~EncryptParams();

        /// Copy constructor
        EncryptParams(const EncryptParams& encryptedParams);

        /// Assignment operator
        EncryptParams& operator=(const EncryptParams& encryptedParams);

        /// Move copy constructor
        EncryptParams(EncryptParams&& encryptedParams) noexcept ;

        /// Move assignment operator
        EncryptParams& operator=(EncryptParams&& encryptedParams);

    public:
        /// Set the mime type (format) of the file that will be encrypted
        /// NOTE: The default will be 'application/octet-stream' if not specified
        /// \param mimeType - The mime type of the file
        void setMimeType(const std::string& mimeType);

        /// Set the policy that to be applied to the tdf
        /// NOTE: If there is no policy defined for the tdf, default policy settings
        /// will be applied
        /// \param policy - The policy object
        void setPolicy(const Policy& policy);

        /// Set the display name for the tdf, this name shows up on the Virtru dashboard
        /// NOTE: If not set, the basename of inFilePath will be used
        /// \param displayName - The display name for the tdf
        void setDisplayName(const std::string& displayName);

        /// Set the display message for the tdf, this message shows up on the Virtru dashboard
        /// \param displayMessage - The display message for the tdf
        void setDisplayMessage(const std::string& displayMessage);

        /// Add access to the TDF file/data for the users in the list
        /// \param users - Share the TDF with the users in the vector
        void shareWithUsers(const std::vector<std::string>& users);

    protected:
        /// Constructor
        EncryptParams();

        friend Client;

        std::string m_tdfOwner;
        std::string m_mimeType;
        std::string m_displayName;
        std::string m_displayMessage;
        std::vector<std::string> m_sharedUsers;
        Policy m_policy;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_PARAM_H
