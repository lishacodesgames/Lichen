#include <lchpch.h>
#include "Application.h"

namespace lichen
{
   Application::Application() : m_running(true) {
      m_window = Window::Create(WindowProps(650, 650));
   }

   void Application::Run() {
      while(m_running) {
         m_window->OnUpdate();

         m_running = !(WindowShouldClose() && !IsKeyDown(KEY_ESCAPE)); // only pressing X will close the app
      }
   }
}