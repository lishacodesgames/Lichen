#include <lchpch.h>
#include "Window.h"

namespace lichen
{
   Window* Window::s_instance = nullptr;

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
      Init(props);
   }
   void Window::Init(const WindowProps& props) {
      m_data.properties = props;
      LCH_CORE_INFO("Creating window \"{}\", ({}, {})", props.title, props.width, props.height);

      InitWindow (props.width, props.height, props.title.c_str());
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