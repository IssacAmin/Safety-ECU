#pragma once
#include <cstdint>
#include <unordered_map>
#include <functional>

namespace uds::cfg {

    using RequestHandler = std::function<void()>;
    using RequestValidator = std::function<void()>;

    struct UdsCfg 
    {
        std::unordered_map<uint8_t, RequestHandler> requestHandlers;
        std::unordered_map<uint8_t, RequestValidator> requestValidators;
    };

} // namespace uds::cfg