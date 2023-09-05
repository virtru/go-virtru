#ifndef VIRTRU_TDF3_CPP_VIRTRU_AUDIT_SERVICE_H
#define VIRTRU_TDF3_CPP_VIRTRU_AUDIT_SERVICE_H

#include "network_interface.h"

namespace virtru {

    class AuditService {
      public:
        /// Constructor
        /// \param auditUrl - https-prefixed URL where Audit Service is hosted
        AuditService(const std::string &auditUrl);


        /// Get all Audit Events
        /// \return - All audit events as JSON
        std::string getEvents();


        /// Get an event which matches the provided event id.
        /// \param eventId - Event Id
        /// \return - JSON
        std::string getEventById(const std::string& eventId);


        /// Construct query string
        /// \param key - name of the Query, e.g. eventType
        /// \param value - value of the Query, e.g. : encrypt
        void addQueryParam(const std::string& key, const std::string& value);


        /// Add additional header
        /// \param key - name of the Header, e.g. Connection
        /// \param value - value of the Header, e.g. keep-alive
        void addHeader(const std::string& key, const std::string& value);


        /// Destructor
        ~AuditService() = default;

      private:
        std::string makeHttpGet(const std::string& fullUrl);


      private:
        std::string m_auditUrl;
        std::shared_ptr<INetwork> m_httpServiceProvider;
        std::string m_queryString;
        HttpHeaders m_additionalHeaders;
    };

} // namespace virtru
#endif // VIRTRU_TDF3_CPP_VIRTRU_AUDIT_SERVICE_H
