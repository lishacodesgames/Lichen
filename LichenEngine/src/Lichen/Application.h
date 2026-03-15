#pragma once
#include "Core.h"

namespace lichen {
   class LCH_API Application {
   public:
      Application() = default;
      virtual ~Application() = default;

      void Run();
   };

   Application* CreateApplication(); /// TO BE DEFINED IN CLIENT

}