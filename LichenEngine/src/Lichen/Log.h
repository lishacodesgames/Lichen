#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Lichen {
   class LCH_API Log {
   public:
      static void Init();

      inline static std::shared_ptr<spdlog::logger>& Log::getCoreLogger() { return s_coreLogger; }
      inline static std::shared_ptr<spdlog::logger>& Log::getClientLogger() { return s_clientLogger; }
   private:
      static std::shared_ptr<spdlog::logger> s_coreLogger;
      static std::shared_ptr<spdlog::logger> s_clientLogger;
   };
}

#ifndef LCH_CFG_DISTRO

   #define LCH_CORE_TRACE(...)   Lichen::Log::getCoreLogger()->trace(__VA_ARGS__)
   #define LCH_CORE_INFO(...)    Lichen::Log::getCoreLogger()->info(__VA_ARGS__)
   #define LCH_CORE_DEBUG(...)   Lichen::Log::getCoreLogger()->debug(__VA_ARGS__)
   #define LCH_CORE_WARN(...)    Lichen::Log::getCoreLogger()->warn(__VA_ARGS__)
   #define LCH_CORE_ERROR(...)   Lichen::Log::getCoreLogger()->error(__VA_ARGS__)
   #define LCH_CORE_FATAL(...)   Lichen::Log::getCoreLogger()->critical(__VA_ARGS__)

#else

   #define LCH_CORE_TRACE
   #define LCH_CORE_INFO
   #define LCH_CORE_DEBUG  
   #define LCH_CORE_WARN
   #define LCH_CORE_ERROR
   #define LCH_CORE_FATAL

#endif

#define LCH_TRACE(...)           Lichen::Log::getClientLogger()->trace(__VA_ARGS__)
#define LCH_INFO(...)            Lichen::Log::getClientLogger()->info(__VA_ARGS__)
#define LCH_DEBUG(...)           Lichen::Log::getClientLogger()->debug(__VA_ARGS__)
#define LCH_WARN(...)            Lichen::Log::getClientLogger()->warn(__VA_ARGS__)
#define LCH_ERROR(...)           Lichen::Log::getClientLogger()->error(__VA_ARGS__)
#define LCH_FATAL(...)           Lichen::Log::getClientLogger()->critical(__VA_ARGS__)