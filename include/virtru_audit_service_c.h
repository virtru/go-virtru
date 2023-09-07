#ifndef VIRTRU_TDF3_SRC_VIRTRU_AUDIT_SERVICE_C_H
#define VIRTRU_TDF3_SRC_VIRTRU_AUDIT_SERVICE_C_H

#include "virtru_constants_c.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AuditService AuditService;

/// Constructor
/// \param auditUrl - https-prefixed URL where Audit Service is hosted
DLL_PUBLIC AuditService* VAuditServiceCreate(const char* auditUrl);

// Destructor
DLL_PUBLIC void VAuditServiceDestroy(AuditService* auditService);


/// Get all Audit Events
/// \return - All audit events as JSON
DLL_PUBLIC char* VGetEvents(AuditService* auditService);


/// Get an event which matches the provided event id.
/// \param eventId - Event Id
/// \return - JSON
DLL_PUBLIC char* VGetEventById(AuditService* auditService,  const char* eventId);


/// Create the Audit Service entry
/// \param auditData - Audit Event Data
DLL_PUBLIC VSTATUS VWriteAuditEvent(AuditService* auditService, const char* auditData);


/// Construct query string
/// \param key - name of the Query, e.g. eventType
/// \param value - value of the Query, e.g. : encrypt
DLL_PUBLIC void VAddQueryParam(AuditService* auditService, const char* key, const char* value);


/// Add additional header
/// \param key - name of the Header, e.g. Connection
/// \param value - value of the Header, e.g. keep-alive
DLL_PUBLIC void VAuditAddHeader(AuditService* auditService, const char* key, const char* value);

#ifdef __cplusplus
}
#endif

#endif //VIRTRU_TDF3_SRC_VIRTRU_AUDIT_SERVICE_C_H