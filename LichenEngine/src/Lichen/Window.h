#include <GLFW/glfw3.h>
#include <functional>
#include <cstdint>
#include <string>
#include "Core.h"

namespace lichen 
{
   class Event;

   struct WindowProps {
      uint32_t width, height;
      std::string title;

      WindowProps(const std::string& title, uint32_t width = 600, uint32_t height = 600) 
         : width(width), height(height), title(title)
      {}
   };

   /// Parent window class for future platform abstraction
   class LCH_API Window {
   public:
      using EventCallbackFxn = std::function<void(Event&)>;

      Window(const WindowProps& props);
      ~Window(); // Might make virtual for platform abstraction

      static Window* Create(const WindowProps& props = WindowProps("Lichen Game Engine"));

      void OnUpdate();
      
      inline uint32_t getWidth() const { return m_data.properties.width; }
      inline uint32_t getHeight() const { return m_data.properties.height; }

      // window attributes
      inline void setEventCallback(const EventCallbackFxn& ecf) {
         m_data.eventCallback = ecf;
      }
      void setVSync(bool enabled);
      bool isVSync() const;
   private: 
      void Init(const WindowProps& props);
      void Shutdown();

      struct WindowData {
         WindowProps properties;
         bool VSync;
         EventCallbackFxn eventCallback;
      };

      GLFWwindow* m_window;
      WindowData m_data;
   };
}