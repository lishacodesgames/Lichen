#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Lichen {
   class LICH_API Log {
   public:
      static void Init();

      static std::shared_ptr<spdlog::logger>& GetCoreLogger();
      static std::shared_ptr<spdlog::logger>& GetClientLogger();
   private:
      static std::shared_ptr<spdlog::logger> s_CoreLogger;
      static std::shared_ptr<spdlog::logger> s_ClientLogger;
   };
}