#pragma once
#include "Event.h"

namespace Lichen {

   class LCH_API MouseMovedEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseMoved)
      MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

      inline float getX() const { return m_mouseX; }
      inline float getY() const { return m_mouseY; }

      [[nodiscard]] std::string describe() const override {
         return "Mouse Moved to: (" + std::to_string(m_mouseX) + ", " + std::to_string(m_mouseY) + ")";
      }
   private:
      float m_mouseX, m_mouseY;
   };
}