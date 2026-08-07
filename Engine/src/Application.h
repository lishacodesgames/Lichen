#pragma once
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace lichen 
{
   class LCH_API Application {
   public:
      Application();
      virtual ~Application() = default;

      void Run();
      void OnEvent(Event& e);

   private:
      std::unique_ptr<Window> m_window;
      bool m_running;

   private:
      /// @todo move to Window class
      bool OnWindowClose(WindowCloseEvent& e);
   };

   extern std::unique_ptr<Application> CreateApplication(); /// TO BE DEFINED IN CLIENT
}
