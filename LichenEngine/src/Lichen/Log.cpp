#include "Log.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lichen
{
   std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
   std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

   void Log::Init() {
      spdlog::set_pattern("%^[%n]%T-[%l]: %v%$"); // [23:55:59][Client,info]: message
      
      // logger with console and multi-threading properties
      s_CoreLogger = spdlog::stdout_color_mt("LICHEN");
      s_CoreLogger->set_level(spdlog::level::trace);

      s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
      s_ClientLogger->set_level(spdlog::level::trace);
   }

   std::shared_ptr<spdlog::logger>& Log::GetCoreLogger() { return s_CoreLogger; }
   std::shared_ptr<spdlog::logger>& Log::GetClientLogger() { return s_ClientLogger; }

} // namespace Lichen
