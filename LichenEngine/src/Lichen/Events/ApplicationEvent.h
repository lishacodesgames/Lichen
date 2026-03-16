#pragma once
#include <cstdint>
#include "Event.h"

namespace lichen {
   // --------------
   // WINDOW EVENTS
   // --------------

   class LCH_API WindowResizeEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
      EVENT_CLASS_TYPE(WindowResize)
      WindowResizeEvent(uint32_t width, uint32_t height) : m_width(width), m_height(height) {}

      inline uint32_t getWidth() const { return m_width; }
      inline uint32_t getHeight() const { return m_height; }

      std::string describe() const override {
         return "Window Resized to: (" + std::to_string(m_width) + ", " + std::to_string(m_height) + ")";
      }
   private:
      uint32_t m_width, m_height;
   };

   class LCH_API WindowCloseEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
      EVENT_CLASS_TYPE(WindowClose)
   };

   // ---------------
   // APP EVENTS
   // ---------------

   class AppTickEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
      EVENT_CLASS_TYPE(AppTick)
   };

   class AppUpdateEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
      EVENT_CLASS_TYPE(AppUpdate)
   };

   class AppRenderEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryApplication)
      EVENT_CLASS_TYPE(AppRender)
   };

}