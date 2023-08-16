/*
* Copyright © 2018 - 2019 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2019/07/18.
//

#ifndef VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_FILE_PARAM_H
#define VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_FILE_PARAM_H

#include <string>
#include "virtru_policy.h"
#include "virtru_encrypt_params.h"

namespace virtru {

    /// Forward declaration
    class Client;

    class EncryptFileParams : public EncryptParams {
    public:
        /// Constructor
        /// NOTE: The out file path will have .html/.tdf extension appended to
        /// inFilePath based on protocol.
        /// \param inFilePath - The file on which the encryption is performed
        EncryptFileParams(const std::string& inFilePath);

        /// Constructor
        /// \param inFilePath - The file on which the encryption is performed
        /// \param outFilePath - The file path of the tdf after successful encryption
        EncryptFileParams(const std::string& inFilePath, const std::string& outFilePath);

        /// Default constructor not supported
        EncryptFileParams() = delete;

        /// Destructor
        virtual ~EncryptFileParams();

        /// Copy constructor
        EncryptFileParams(const EncryptFileParams& encryptedFileParams);

        /// Assignment operator
        EncryptFileParams& operator=(const EncryptFileParams& encryptedFileParams);

        /// Move copy constructor
        EncryptFileParams(EncryptFileParams&& encryptedFileParams);

        /// Move assignment operator
        EncryptFileParams& operator=(EncryptFileParams&& encryptedFileParams);

    private:
        friend Client;

        std::string m_inputFilePath;
        std::string m_outFilePath;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_FILE_PARAM_H
