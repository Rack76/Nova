#include "Log.hpp"

#include "Log.hpp"

#include "spdlog\sinks\stdout_color_sinks.h"

namespace Nova {

    NOVA_API std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    NOVA_API std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
    
    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
    
        s_CoreLogger = spdlog::stdout_color_mt("GHOSTLINE");
        s_CoreLogger->set_level(spdlog::level::trace);
    
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
    
}  // namespace Nova