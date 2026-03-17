#pragma once
#include "Window.h"
#include "Core.h"

namespace lichen 
{
   class LCH_API Application {
   public:
      Application();
      virtual ~Application() = default;

      void Run();
   private: 
      Window* m_window;
      bool m_running;
   };

   Application* CreateApplication(); /// TO BE DEFINED IN CLIENT
}