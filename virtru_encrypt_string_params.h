/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/10/01.
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STRING_PARAM_H
#define VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STRING_PARAM_H

#include <iostream>
#include "virtru_encrypt_params.h"

namespace virtru {

    /// Forward declaration
    class Client;

    class EncryptStringParams : public EncryptParams {
    public:
        /// Constructor
        /// \param plainText -  The data to be encrypted.
        EncryptStringParams(const std::string& plainText);

        /// Constructor
        /// \param plainText -  The text to be encrypted.
        EncryptStringParams(std::string&& plainText);

        /// Destructor
        ~EncryptStringParams();

        /// Default constructor not supported
        EncryptStringParams() = delete;

        /// Copy constructor
        EncryptStringParams(const EncryptStringParams& encryptStreamParams);

        /// Assignment operator
        EncryptStringParams& operator=(const EncryptStringParams& encryptStreamParams);

        /// Move copy constructor
        EncryptStringParams(EncryptStringParams&& encryptStreamParams) noexcept;

        /// Move assignment operator
        EncryptStringParams& operator=(EncryptStringParams&& encryptStreamParams);

    private:
        friend Client;

        std::string m_plainData;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STRING_PARAM_H
