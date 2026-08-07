#include <lchpch.h>
#include "Window.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace lichen
{
   static bool s_isGLFWinit = false; // ...what is this for?
   static void GLFWErrorCallback(int error, const char* description) {
      LCH_CORE_ERROR("GLFW Error! Error code {}: {}", error, description);
   }

   void Window::OnUpdate() {
      glfwPollEvents();
      glfwSwapBuffers(m_window);
   }

   void Window::setVSync(bool enabled) {
      glfwSwapInterval(enabled); // 1 or 0 frames
      m_data.isVSync = enabled;
   }

   void Window::Init(const WindowProperties& props) {
      m_data.properties = props;
      LCH_CORE_INFO(
         "Creating window \"{}\", ({}, {})", props.title, props.width, props.height
      );

      if(!s_isGLFWinit) {
         bool success = glfwInit();
         LCH_CORE_ASSERT(success, "GLFW Initialisation failed!")
         glfwSetErrorCallback(GLFWErrorCallback);
         s_isGLFWinit = success;
      }

      // checking so c-style cast to int is safe
      LCH_CORE_ASSERT(m_data.properties.width <= INT_MAX && m_data.properties.height <= INT_MAX, "Window dimensions are too large!");

      m_window = glfwCreateWindow(
         (int)m_data.properties.width, (int)m_data.properties.height, 
         m_data.properties.title.c_str(), nullptr, nullptr);
      glfwMakeContextCurrent(m_window);
      glfwSetWindowUserPointer(m_window, &m_data); // so we can access m_data from inside glfw callback setter fxns
      setVSync(true);

      // -- set glfw callbacks --

      // resize
      glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
         windowData.properties.width = width;
         windowData.properties.height = height;

         WindowResizeEvent resizeEvent(width, height);
         windowData.eventCallback(resizeEvent);
      });

      // close
      glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
         WindowCloseEvent closeEvent;
         windowData.eventCallback(closeEvent);
      });

      // keys
      glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

         switch(action) {
            case GLFW_PRESS: {
               KeyPressedEvent keyEvent(key);
               windowData.eventCallback(keyEvent);
               break;
            }

            case GLFW_RELEASE: {
               KeyReleasedEvent keyEvent(key);
               windowData.eventCallback(keyEvent);
               break;
            }

            case GLFW_REPEAT: {
               KeyPressedEvent keyEvent(key, 1); /// @todo getting repeat count
               windowData.eventCallback(keyEvent);
               break;
            }
         }
      });

      // mouse click
      glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);

         switch(action) {
            case GLFW_PRESS: {
               MouseButtonPressedEvent pressedEvent(button);
               windowData.eventCallback(pressedEvent);
               break;
            }
            case GLFW_RELEASE: {
               MouseButtonReleasedEvent releasedEvent(button);
               windowData.eventCallback(releasedEvent);
               break;
            }
         }
      });

      // mouse scroll
      glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
         MouseScrolledEvent scrollEvent(xOffset, yOffset);
         windowData.eventCallback(scrollEvent);
      });

      // mouse movement
      glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double x, double y) {
         WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
         MouseMovedEvent moveEvent(x, y);
         windowData.eventCallback(moveEvent);
      });
   }
}