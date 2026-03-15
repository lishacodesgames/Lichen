#pragma once
#include "Event.h"

namespace Lichen {

   class LCH_API MouseMovedEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseMoved)
      MouseMovedEvent(double x, double y) : m_mouseX(x), m_mouseY(y) {}

      inline double getX() const { return m_mouseX; }
      inline double getY() const { return m_mouseY; }

      [[nodiscard]] std::string describe() const override {
         return "Mouse Moved to: (" + std::to_string(m_mouseX) + ", " + std::to_string(m_mouseY) + ")";
      }
   private:
      double m_mouseX, m_mouseY;
   };

   class LCH_API MouseScrolledEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseScrolled)
      MouseScrolledEvent(double xOffset, double yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}
   
      double getXOffset() const { return m_xOffset; }
      double getYOffset() const { return m_yOffset; }

      [[nodiscard]] std::string describe() const override {
         return "Mouse Scrolled by (" + std::to_string(m_xOffset) + ", " + std::to_string(m_yOffset) + ")";
      }
   private:
      double m_xOffset, m_yOffset;
   };
}