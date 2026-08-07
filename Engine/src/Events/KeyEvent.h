#pragma once
#include "Event.h"

namespace lichen 
{
   class LCH_API KeyEvent : public Event {
   public:
      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
      inline int getKeyCode() const { return _keycode; }

   protected:
      int _keycode;

   protected:
      // This class is purely meant to serve as a parent to the Key Event child classes, so only they can construct it.
      KeyEvent(int keycode) : _keycode(keycode) {}
   };

   class LCH_API KeyPressedEvent : public KeyEvent {
   public:
      KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_repeat(repeatCount) {}

      EVENT_CLASS_TYPE(KeyPressed)
      inline int getRepeats() const { return m_repeat; }

      std::string describe() const override {
         return
            "Key Pressed: " + std::to_string(_keycode) + "\t(" + std::to_string(m_repeat) + " times)";
      }

   private:
      int m_repeat; // how many types was a key pressed
   };

   class LCH_API KeyReleasedEvent : public KeyEvent {
   public:
      KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

      EVENT_CLASS_TYPE(KeyReleased)

      std::string describe() const override { return "Key Released: " + std::to_string(_keycode); }
   };
}