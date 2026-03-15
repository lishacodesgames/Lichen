#pragma once
#include <string>
#include "Core.h"

namespace Hazel {
   /** Current status of Events: Blocking
    * Meaning, Events get dispatched as soon as they occur
    * No queuing has been implemented as of now
    * 
    * Ideally, dispatching should occur during the Event part of the update stage of a frame
   */

   enum class EventType {
      None,
      WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
      AppTick, AppUpdate, AppRender,
      MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
   };

   /// an event can have multiple categories at once, hence each enum is defined on a separate position on a bitfield (each is a power of 2)
   enum EventCategory {
      None,
      EventCategoryApplication   = BIT(0),
      EventCategoryInput         = BIT(1), 
      EventCategoryKeyboard      = BIT(2),
      EventCategoryMouse         = BIT(3),
      EventCategoryMouseButton   = BIT(4)
   };

   class LCH_API Event {
   public:
      /// ---- GETTERS ----
      virtual EventType GetEventType() const = 0;
      virtual std::string GetName() const = 0;
      virtual int GetCategoryFlags() const = 0;

      /// if true bits are overlapping, returns true
      inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
   protected:
      bool m_Handled = false; 
   };
}