/*
* Copyright 2023 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Sujan Reddy on 2023/08/23.
//

#ifndef VIRTRU_TDF3_SRC_VIRTRU_OIDC_CLIENT_H
#define VIRTRU_TDF3_SRC_VIRTRU_OIDC_CLIENT_H

#include "tdf_client.h"

namespace virtru {
    class TDFClientOIDC {
    public:
        /// Construct
        /// \param attributesInfoAsJson
        /// \param kasInfoAsJson
        TDFClientOIDC(const std::string& attributesInfoAsJson, const std::string& kasInfoAsJson);

        /// Default constructor is not supported
        TDFClientOIDC() = delete;

        /// Destructor
        ~TDFClientOIDC() = default;

    public: // Interface
        /// Add attributes that will applied for all TDFs creating by this instance
        /// \param attName - Attribute name
        /// \param attValue - Attribute value
        void addAttribute(const std::string& attName, const std::string& attValue);

        /// Encrypt the file to tdf format.
        /// \param tdfStorageType - The type of the tdf.
        /// \param outFilepath - The file path of the tdf after successful encryption.
        /// NOTE: virtru::exception will be thrown if there is issues while performing the encryption process.
        void encryptFile(const TDFStorageType &tdfStorageType, const std::string &outFilepath);

        /// Encrypt the bytes to tdf format.
        /// \param tdfStorageType - The type of the tdf.
        /// \return std::vector<VBYTE> - The vector containing the encrypted data.
        /// NOTE: virtru::exception will be thrown if there are issues while performing the encryption process.
        /// NOTE: The caller should copy the bytes from the return value and should not hold on to the
        /// return value.
        std::vector<VBYTE> encryptData(const TDFStorageType &tdfStorageType);

        /// Decrypt file to tdf file format.
        /// \param tdfStorageType - The type of the tdf.
        /// \param outFilepath - The file path of the tdf after successful encryption.
        /// NOTE: virtru::exception will be thrown if there is issues while performing the decryption process.
        void decryptFile(const TDFStorageType &tdfStorageType, const std::string &outFilepath);

        /// Decrypt the bytes to tdf format.
        /// \param tdfStorageType - The type of the tdf.
        /// \return std::vector<VBYTE> - The vector containing the decrypted data.
        /// NOTE: virtru::exception will be thrown if there are issues while performing the decryption process.
        /// NOTE: The caller should copy the bytes from the return value and should not hold on to the
        /// return value.
        std::vector<VBYTE> decryptData(const TDFStorageType &tdfStorageType);

        /// Enable the internal logger class to write logs to the console for given LogLevel. The default Loglevel is
        /// to keep the current level if not specified.
        /// \param logLevel - The log level
        void enableConsoleLogging(LogLevel logLevel = LogLevel::Current);

    private: /// Helpers
        /// Initialize the TDF Client which is used for creating the TDF instance
        /// used for encrypt and decrypt.
        void initTDFClientForEncrypt();

        /// Initialize the TDF Client which is used for creating the TDF instance
        /// used for decrypt.
        /// \param tdfStorageType - The type of the tdf.
        void initTDFClientForDecrypt(const TDFStorageType &tdfStorageType);

        /// Return the kas url form TDF
        /// \param tdfStorageType -  - The type of the tdf.
        /// \return Kas url
        static std::string getKasUrl(const TDFStorageType &tdfStorageType);

    private: // Data
        bool m_rebuildClient{false};
        std::string m_attributeInfo;
        std::string m_kasInfo;
        std::vector<std::pair<std::string, std::string>> m_attributes;
        std::unique_ptr<TDFClient> m_tdfClient;
    };
}

#endif //VIRTRU_TDF3_SRC_VIRTRU_OIDC_CLIENT_H
