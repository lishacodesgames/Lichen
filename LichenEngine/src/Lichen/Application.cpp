#include <lchpch.h>
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Log.h"

lichen::Application::Application() : m_running(true) {
   m_window = std::unique_ptr<Window>(Window::Create());
}

void lichen::Application::Run() {
   while(m_running) {
      m_window->OnUpdate();
   }
}