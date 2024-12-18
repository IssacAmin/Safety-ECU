#pragma once
#include <cstdint>

namespace uds::services {

class UdsAbstractServiceManager
{
protected:
    const uint8_t serviceId;           // Service ID
    const uint8_t requestLength;       // Request Length
    const uint8_t responseLength;      // Response Length

public:
    // Constructor with default values for service attributes
    UdsAbstractServiceManager(
        uint8_t serviceId = 0,
        uint8_t requestLength = 0,
        uint8_t responseMaxLength = 0,
        uint8_t diagSessionMask = 0,
        uint8_t securityLevelMask = 0
    )
    : serviceId(serviceId),
      requestLength(requestLength),
      responseLength(responseLength),
    {}

    // Pure virtual function for handling requests
    virtual void validateRequest() = 0; 
    virtual void handleRequest() = 0;

    // Getters for service information
    uint8_t getServiceId() const {
        return serviceId;
    }

    uint8_t getRequestLength() const {
        return requestLength;
    }

    uint8_t getResponseLength() const {
        return responseLength;
    }
};

} // namespace uds::services