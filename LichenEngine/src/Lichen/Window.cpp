#include <lchpch.h>
#include "Window.h"

#include "Log.h"

namespace lichen
{
   static bool s_isGLFWinit = false;

   Window* Window::Create(const WindowProps& props) { return new Window(props); }

   Window::Window(const WindowProps& props) { Init(props); }
   Window::~Window() { Shutdown(); }

   void Window::Init(const WindowProps& props) {
      m_data.properties = props;
      LCH_CORE_INFO(
         "Creating window \"{}\", ({}, {})", props.title, props.width, props.height
      );

      if(!s_isGLFWinit) {
         bool success = glfwInit();
         LCH_CORE_ASSERT(success, "GLFW Initialisation failed")
         s_isGLFWinit = success;
      }

      m_window = glfwCreateWindow(
         (int)m_data.properties.width, (int)m_data.properties.height, 
         m_data.properties.title.c_str(), nullptr, nullptr
      );
      glfwMakeContextCurrent(m_window);
      glfwSetWindowUserPointer(m_window, &m_data);
      setVSync(true);
   }

   void Window::Shutdown() { glfwDestroyWindow(m_window); }

   void Window::OnUpdate() {
      glfwPollEvents();
      glfwSwapBuffers(m_window);
   }

   void Window::setVSync(bool enabled) {
      glfwSwapInterval(enabled); // 1 or 0 frames
      m_data.VSync = enabled;
   }
}