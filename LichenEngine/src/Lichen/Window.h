#pragma once
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

      WindowProps(uint32_t width = 600, uint32_t height = 600, const std::string& title = "Lichen Game Engine") 
         : width(width), height(height), title(title)
      {}
   };

   /// Parent window class for future platform abstraction
   class LCH_API Window {
      static Window* s_instance;
      Window(const WindowProps& props);
   public:
      using EventCallbackFxn = std::function<void(Event&)>;

      ~Window(); // Might make virtual for platform abstraction

      static Window* Create(const WindowProps& props = WindowProps());

      static void OnUpdate();
      
      inline static uint32_t getWidth() { return m_properties.width; }
      inline static uint32_t getHeight() { return m_properties.height; }

      // window attributes
      inline static void setEventCallback(const EventCallbackFxn& ecf) {
         m_eventCallback = ecf;
      }
   private: 
      static void Init(const WindowProps& props);
      static void Shutdown();

      static WindowProps m_properties;
      static EventCallbackFxn m_eventCallback;
   };
}