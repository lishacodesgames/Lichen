#include <lchpch.h>
#include "Window.h"

namespace lichen
{
   Window* Window::s_instance = nullptr;
   WindowProps Window::m_properties;
   Window::EventCallbackFxn Window::m_eventCallback;

   Window* Window::Create(const WindowProps& props) {
      if(!s_instance)
         return new Window(props);
      else {
         LCH_CORE_WARN("Window already exists!");
         return s_instance;
      }
   }

   Window::Window(const WindowProps& props) { 
      s_instance = this;
      m_properties = props;
      Init(props);
   }
   void Window::Init(const WindowProps& props) {
      LCH_CORE_INFO(
         "Creating window \"{}\", ({}, {})", 
         m_properties.title, m_properties.width, m_properties.height
      );

      InitWindow (m_properties.width, m_properties.height, m_properties.title.c_str());
   }

   Window::~Window() {
      s_instance = nullptr;
      Shutdown();
   }
   void Window::Shutdown() { CloseWindow(); }

   void Window::OnUpdate() {
      BeginDrawing();
      ClearBackground(BLACK);
      EndDrawing();
   }
}