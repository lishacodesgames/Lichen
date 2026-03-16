#include <lchpch.h>
#include "Log.h"

namespace lichen
{
   std::shared_ptr<spdlog::logger> Log::s_coreLogger;
   std::shared_ptr<spdlog::logger> Log::s_clientLogger;

   void Log::Init() {
      spdlog::set_pattern("%^[%n-%l]: %v%$"); // [23:55:59][Client,info]: message
      
      // logger with console and multi-threading properties
      s_coreLogger = spdlog::stdout_color_mt("lichen");
      s_coreLogger->set_level(spdlog::level::trace);

      s_clientLogger = spdlog::stdout_color_mt("client");
      s_clientLogger->set_level(spdlog::level::trace);
   }
}