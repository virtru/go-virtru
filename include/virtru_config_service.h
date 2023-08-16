#ifndef VIRTRU_TDF3_CPP_VIRTRU_CONFIG_SERVICE_H
#define VIRTRU_TDF3_CPP_VIRTRU_CONFIG_SERVICE_H

#include "network_interface.h"

namespace virtru {

    class ConfigService {
    public:
        /// Constructor
        /// \param configUrl - https-prefixed URL where Config Service is hosted
        ConfigService(const std::string &configUrl);


        /// Get the config from Config Service
        /// \param configKey - compound key of the configuration to get
        /// \param outputFilePath - path to the file to save the output
        void getConfig(const std::string& configKey, const std::string& outputFilePath);


        /// Create the Config Service entry
        /// \param configKey - compound key of the configuration to post
        /// \param inputFilePath - path to the file to read the config from
        void createConfig(const std::string& configKey, const std::string& inputFilePath);


        /// Returns Configuration Metadata for a given key.
        /// \param configKey - compound key of the configuration to post
        /// \param inputFilePath - path to the file to read the config
        /// \return - Last-Modified Header value
        std::string getConfigMetaData(const std::string& configKey);


        /// Add additional header
        /// \param key - name of the Header, e.g. Connection
        /// \param value - value of the Header, e.g. keep-alive
        void addHeader(const std::string& key, const std::string& value);


        /// Destructor
        ~ConfigService() = default;


    private:
        std::string m_configUrl;
        std::shared_ptr<INetwork> m_httpServiceProvider;
        HttpHeaders m_additionalHeaders;
    };

} // namespace virtru
#endif // VIRTRU_TDF3_CPP_VIRTRU_CONFIG_SERVICE_H
