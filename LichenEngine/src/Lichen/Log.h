#pragma once
#include <spdlog/spdlog.h>
#include <memory>
#include "Lichen/Core.h"

namespace lichen 
{
   class LCH_API Log {
   public:
      static void Init();

      inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
      inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }
   private:
      static std::shared_ptr<spdlog::logger> s_coreLogger;
      static std::shared_ptr<spdlog::logger> s_clientLogger;
   };
}

#ifndef LCH_CFG_DISTRO
   #define LCH_CORE_TRACE(...)   lichen::Log::getCoreLogger()->trace(__VA_ARGS__)
   #define LCH_CORE_INFO(...)    lichen::Log::getCoreLogger()->info(__VA_ARGS__)
   #define LCH_CORE_DEBUG(...)   lichen::Log::getCoreLogger()->debug(__VA_ARGS__)
   #define LCH_CORE_WARN(...)    lichen::Log::getCoreLogger()->warn(__VA_ARGS__)
   #define LCH_CORE_ERROR(...)   lichen::Log::getCoreLogger()->error(__VA_ARGS__)
   #define LCH_CORE_FATAL(...)   lichen::Log::getCoreLogger()->critical(__VA_ARGS__)
#else
   #define LCH_CORE_TRACE(...)
   #define LCH_CORE_INFO(...)
   #define LCH_CORE_DEBUG(...)
   #define LCH_CORE_WARN(...)
   #define LCH_CORE_ERROR(...)
   #define LCH_CORE_FATAL(...)
#endif

#define LCH_TRACE(...)           lichen::Log::getClientLogger()->trace(__VA_ARGS__)
#define LCH_INFO(...)            lichen::Log::getClientLogger()->info(__VA_ARGS__)
#define LCH_DEBUG(...)           lichen::Log::getClientLogger()->debug(__VA_ARGS__)
#define LCH_WARN(...)            lichen::Log::getClientLogger()->warn(__VA_ARGS__)
#define LCH_ERROR(...)           lichen::Log::getClientLogger()->error(__VA_ARGS__)
#define LCH_FATAL(...)           lichen::Log::getClientLogger()->critical(__VA_ARGS__)