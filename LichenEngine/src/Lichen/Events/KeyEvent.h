#pragma once
#include <string>
#include "Event.h"

namespace lichen {

   class LCH_API KeyEvent : public Event {
   public:
      inline int getKeyCode() const { return m_key; }
      EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
   protected:
      int m_key;

      // This class is purely meant to serve as a parent to the Key Event child classes, so only they can construct it.
      KeyEvent(int keycode) : m_key(keycode) {}
   };

   class LCH_API KeyPressedEvent : public KeyEvent {
   public:
      EVENT_CLASS_TYPE(KeyPressed)
      KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_repeat(repeatCount) {}

      inline int getRepeats() const { return m_repeat; }
      std::string describe() const override {
         return
            "Key Pressed: " + std::to_string(m_key) + "\t(" + std::to_string(m_repeat) + " times)";
      }
   private:
      int m_repeat; // how many types was a key pressed
   };

   class LCH_API KeyReleasedEvent : public KeyEvent {
   public:
      EVENT_CLASS_TYPE(KeyReleased)
      KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

      std::string describe() const override { return "Key Released: " + std::to_string(m_key); }
   };
}