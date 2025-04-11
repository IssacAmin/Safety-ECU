#pragma once
#include "UdsCfg.hpp"
#include <cstdint>
namespace uds::server
{
    class UdsServer
    {
    public:
        // Delete the copy constructor and assignment operator to prevent copying
        UdsServer(const UdsServer&) = delete;
        UdsServer& operator=(const UdsServer&) = delete;

        // Static method to access the single instance of UdsServer
        static UdsServer& getInstance(uds::cfg::UdsCfg* config = nullptr);
        // Method to change configuration dynamically
        void switchConfig(uds::cfg::UdsCfg* newConfig);

        //main request enrty function
        void handleRequest();
        

    private:
        // Reference to configuration object
        uds::cfg::UdsCfg* currentConfig;
        // Static instance of the UdsServer
        static UdsServer* instance;
        // Private constructor, can't be instantiated externally
        UdsServer(uds::cfg::UdsCfg* config);
    };
}