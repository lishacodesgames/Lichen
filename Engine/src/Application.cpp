#include <lchpch.h>
#include "Application.h"

namespace lichen
{
   void Application::Run() {
      while(m_running) {
         m_window->OnUpdate();
      }
   }
}
