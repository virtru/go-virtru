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

#ifndef VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STREAM_PARAM_H
#define VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STREAM_PARAM_H

#include <iostream>
#include "virtru_encrypt_params.h"

namespace virtru {

    /// Forward declaration
    class Client;

    class EncryptStreamParams : public EncryptParams {
    public:
        /// Constructor
        /// \param inStream -  The stream containing a data to be encrypted. The file on which the encryption is performed
        /// \param outStream - The stream containing the encrypted data after successful encryption
        EncryptStreamParams(std::istream& inStream, std::ostream& outStream);

        /// Destructor
        ~EncryptStreamParams();

        /// Default constructor not supported
        EncryptStreamParams() = delete;

        /// Copy constructor
        EncryptStreamParams(const EncryptStreamParams& encryptStreamParams) = delete;

        /// Assignment operator
        EncryptStreamParams& operator=(const EncryptStreamParams& encryptStreamParams) = delete;

        /// Move copy constructor
        EncryptStreamParams(EncryptStreamParams&& encryptStreamParams) = delete;

        /// Move assignment operator
        EncryptStreamParams& operator=(EncryptStreamParams&& encryptStreamParams) = delete;

    private:
        friend Client;

        std::istream& m_inStream;
        std::ostream& m_outStream;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_STREAM_PARAM_H
