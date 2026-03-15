#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Lichen {
   class LCH_API Log {
   public:
      static void Init();

      static std::shared_ptr<spdlog::logger>& GetCoreLogger();
      static std::shared_ptr<spdlog::logger>& GetClientLogger();
   private:
      static std::shared_ptr<spdlog::logger> s_CoreLogger;
      static std::shared_ptr<spdlog::logger> s_ClientLogger;
   };
}

#ifndef LCH_CFG_DISTRO

   #define LCH_CORE_TRACE(...)   Lichen::Log::GetCoreLogger()->trace(__VA_ARGS__)
   #define LCH_CORE_INFO(...)    Lichen::Log::GetCoreLogger()->info(__VA_ARGS__)
   #define LCH_CORE_DEBUG(...)   Lichen::Log::GetCoreLogger()->debug(__VA_ARGS__)
   #define LCH_CORE_WARN(...)    Lichen::Log::GetCoreLogger()->warn(__VA_ARGS__)
   #define LCH_CORE_ERROR(...)   Lichen::Log::GetCoreLogger()->error(__VA_ARGS__)
   #define LCH_CORE_FATAL(...)   Lichen::Log::GetCoreLogger()->critical(__VA_ARGS__)

#else

   #define LCH_CORE_TRACE
   #define LCH_CORE_INFO
   #define LCH_CORE_DEBUG  
   #define LCH_CORE_WARN
   #define LCH_CORE_ERROR
   #define LCH_CORE_FATAL

#endif

#define LCH_TRACE(...)           Lichen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LCH_INFO(...)            Lichen::Log::GetClientLogger()->info(__VA_ARGS__)
#define LCH_DEBUG(...)           Lichen::Log::GetClientLogger()->debug(__VA_ARGS__)
#define LCH_WARN(...)            Lichen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LCH_ERROR(...)           Lichen::Log::GetClientLogger()->error(__VA_ARGS__)
#define LCH_FATAL(...)           Lichen::Log::GetClientLogger()->critical(__VA_ARGS__)