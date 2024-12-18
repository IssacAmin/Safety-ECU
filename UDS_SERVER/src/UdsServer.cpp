#include "UdsServer.hpp"

namespace uds::server
{
    // Initialize the static member variable
    UdsServer* UdsServer::instance = nullptr;

    // Private constructor definition
    UdsServer::UdsServer(uds::cfg::UdsCfg* config)
        : currentConfig(config) {}

    // Static method to get the single instance of UdsServer
    UdsServer& UdsServer::getInstance(uds::cfg::UdsCfg* config) {
        if (instance == nullptr) {
            instance = new UdsServer(config); // Create instance if it doesn't exist
        }
        return *instance;
    }

    // Method to change configuration dynamically
    void UdsServer::switchConfig(uds::cfg::UdsCfg* newConfig) {
        // Change to the new configuration
        currentConfig = newConfig;
    }
    void UdsServer::handleRequest() 
    {
        //timing()
            //validateRequest()->sub class
            //handleRequset()-> sub class
    }
} // namespace uds::server
