#pragma once
#include "Core.h"

namespace Lichen {

   class LICH_API Application {
   public:
      Application() = default;
      virtual ~Application() = default;

      void Run();
   };
}