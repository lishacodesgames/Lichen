#include <lchpch.h>
#include "Application.h"

#include "Events/Event.h"
#include "Log.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace lichen
{

   Application::Application() : m_running(true) {
      m_window = std::unique_ptr<Window>(Window::Create());
      m_window->setEventCallback(BIND_EVENT_FUNCTION(OnEvent)); // @params of bind: fxn, params...
   }

   void Application::Run() {
      while(m_running) {
         m_window->OnUpdate();
      }
   }

   void Application::OnEvent(Event& e) {
      EventDispatcher dispatcher(e);
      dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

      /// @bug ostream overload should allow us to pass just e
      LCH_CORE_TRACE("{}", e.describe());
   }

   bool Application::OnWindowClose(WindowCloseEvent& e) {
      m_running = false;
      return true;
   }
}  // namespace lichen
