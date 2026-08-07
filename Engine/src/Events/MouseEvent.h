#pragma once
#include "Event.h"

namespace lichen 
{
   class LCH_API MouseMovedEvent : public Event {
   public:  
      MouseMovedEvent(double x, double y) : m_mouseX(x), m_mouseY(y) {}

      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseMoved)
      inline double getX() const { return m_mouseX; }
      inline double getY() const { return m_mouseY; }

      std::string describe() const override { return std::format("Mouse moved to: ({}, {})", m_mouseX, m_mouseY); }

   private:
      double m_mouseX, m_mouseY;
   };

   class LCH_API MouseScrolledEvent : public Event {
   public:
      MouseScrolledEvent(double xOffset, double yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}
      
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
      EVENT_CLASS_TYPE(MouseScrolled)
      inline double getXOffset() const { return m_xOffset; }
      inline double getYOffset() const { return m_yOffset; }

      std::string describe() const override { return std::format("Mouse scrolled by ({}. {})", m_xOffset, m_yOffset); }

   private:
      double m_xOffset, m_yOffset;
   };

   /// Parent class only, for Pressed and Release Mouse events
   class LCH_API MouseButtonEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton)
      inline int getButton() const { return _button; }

   protected:
      int _button;

   protected:
      // This class is purely meant to serve as a parent to the MouseButtonEvent child classes, so only they can construct it.
      MouseButtonEvent(int button) : _button(button) {}
   };

   class LCH_API MouseButtonPressedEvent : public MouseButtonEvent {
   public:
      MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

      EVENT_CLASS_TYPE(MouseButtonPressed)

      std::string describe() const override { return std::format("Mouse Button ({}) pressed.", _button); }
   };

   class LCH_API MouseButtonReleasedEvent : public MouseButtonEvent {
   public:
      MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

      EVENT_CLASS_TYPE(MouseButtonReleased)

      /// @todo implemnt toString(button)
      std::string describe() const override { return std::format("Mouse Button ({}) released.", _button); }
   };
}