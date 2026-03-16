#pragma once
#include <string>
#include "Lichen/Core.h"
#include "Event.h"

namespace lichen 
{
   class LCH_API MouseMovedEvent : public Event {
   public:  
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseMoved)
      MouseMovedEvent(double x, double y) : m_mouseX(x), m_mouseY(y) {}

      inline double getX() const { return m_mouseX; }
      inline double getY() const { return m_mouseY; }

      std::string describe() const override {
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
   
      inline double getXOffset() const { return m_xOffset; }
      inline double getYOffset() const { return m_yOffset; }

      std::string describe() const override {
         return "Mouse Scrolled by (" + std::to_string(m_xOffset) + ", " + std::to_string(m_yOffset) + ")";
      }
   private:
      double m_xOffset, m_yOffset;
   };

   /// Parent class only, for Pressed and Release Mouse events
   class LCH_API MouseButtonEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
      inline int getButton() const { return m_button; }
   protected:
      int m_button;
      MouseButtonEvent(int button) : m_button(button) {}
   };

   class LCH_API MouseButtonPressedEvent : public MouseButtonEvent {
   public:
      EVENT_CLASS_TYPE(MouseButtonPressed)
      MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

      std::string describe() const override {
         return "Mouse Button (" + std::to_string(m_button) + ") Pressed";
      }
   };

   class LCH_API MouseButtonReleasedEvent : public MouseButtonEvent {
   public:
      EVENT_CLASS_TYPE(MouseButtonReleased)
      MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

      std::string describe() const override {
         return "Mouse Button (" + std::to_string(m_button) + ") Released";
      }
   };
}