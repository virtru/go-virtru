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

#ifndef VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_DATA_PARAMS_H
#define VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_DATA_PARAMS_H

#include "tdf_constants.h"
#include "virtru_encrypt_params.h"

namespace virtru {

    /// Forward declaration
    class Client;

    class EncryptDataParams : public EncryptParams {
    public:
        /// Constructor
        /// \param dataSourceCb -  The callback producing the data to be encrypted. 
        /// \param dataSinkCb - The callback consuming the encrypted data after successful encryption
        EncryptDataParams(TDFDataSourceCb&& dataSourceCb, TDFDataSinkCb&& dataSinkCb);

        /// Destructor
        ~EncryptDataParams();

        /// Default constructor not supported
        EncryptDataParams() = delete;

        /// Copy constructor
        EncryptDataParams(const EncryptDataParams& encryptDataParams) = delete;

        /// Assignment operator
        EncryptDataParams& operator=(const EncryptDataParams& encryptDataParams) = delete;

        /// Move copy constructor
        EncryptDataParams(EncryptDataParams&& encryptDataParams) = delete;

        /// Move assignment operator
        EncryptDataParams& operator=(EncryptDataParams&& encryptDataParams) = delete;

    private:
        friend Client;

        TDFDataSourceCb m_dataSourceCb;
        TDFDataSinkCb m_dataSinkCb;
    };
}

#endif //VIRTRU_TDF3_SDK_VIRTRU_ENCRYPT_DATA_PARAMS_H
