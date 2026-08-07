#pragma once
#include "Window.h"

namespace lichen 
{
   class LCH_API Application {
   public:
      Application() : m_running(true) {
         m_window = std::unique_ptr<Window>(Window::Create());
      }
      virtual ~Application() = default;

      void Run();

   private:
      std::unique_ptr<Window> m_window;
      bool m_running;
   };

   extern std::unique_ptr<Application> CreateApplication(); /// TO BE DEFINED IN CLIENT
}