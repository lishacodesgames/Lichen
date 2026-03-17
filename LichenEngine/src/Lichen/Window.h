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

   class LCH_API Window {
   public:
      using EventCallbackFxn = std::function<void(Event&)>;

      virtual ~Window() {}

      static Window* Create(const WindowProps& props = WindowProps("Lichen Game Engine"));

      // ---- PURE VIRTUALS ----

      virtual void OnUpdate() = 0;
      
      virtual uint32_t getWidth() const = 0;
      virtual uint32_t getHeight() const = 0;

      // window attributes
      virtual void setEventCallback(const EventCallbackFxn& ecf) = 0;
      virtual void setVSync(bool enabled) = 0;
      virtual bool isVSync() const = 0;
   };
}