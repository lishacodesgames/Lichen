#pragma once
#include "Core.h"

namespace lichen 
{
   /** Current status of Events: Blocking
    * Meaning, Events get dispatched as soon as they occur
    * No queuing has been implemented as of now
    * 
    * Ideally, dispatching should occur during the Event part of the update stage of a frame
   */

   enum class EventType {
      None,
      WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, // Window events
      AppTick, AppUpdate, AppRender,                                        // App events
      KeyPressed, KeyReleased,                                              // Key events
      MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled    // Mouse events
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

   /// @param category an integer bitfield of the categories an event belongs to as per EventCategory enum
   #define EVENT_CLASS_CATEGORY(category) int getCategoryFlags() const override { return category; }

   /// @param type Name of the type as per EventType's members
   #define EVENT_CLASS_TYPE(type) \
      static EventType getStaticType() { return EventType::type; }  /* For compiletime access, template type checking */ \
      EventType getEventType() const override { return EventType::type; } /* Same as GetStaticType, but for runtime polymorphic access */ \
      const char* getName() const override { return #type; }

   class LCH_API Event {
   public:
      virtual ~Event() = default;

      /// ---- GETTERS ----
      virtual EventType getEventType() const = 0;
      virtual const char* getName() const = 0;
      virtual int getCategoryFlags() const = 0;

      virtual std::string describe() const { return getName(); }

      /// @return TRUE, if: true bits are overlapping
      inline bool hasCategory(EventCategory category) { return (getCategoryFlags() & category) != 0; }

   protected:
      bool _handled = false; 

   private:
      friend class EventDispatcher;
   };

   class EventDispatcher {
   public:
      EventDispatcher(Event& e) : m_event(e) {}

      /// @note checks if the event type is the one that has occurred
      /// @tparam Child: a child class of Event
      template <typename Child> 
      bool Dispatch(std::function<bool(Child&)> handleEvent) {
         // comparing compiletime type with runtime type
         if(m_event.getEventType() == Child::getStaticType()) { 
            m_event._handled = handleEvent(static_cast<Child&>(m_event));
            return true;
         } 

         return false;
      }

   private:
      Event& m_event;
   };

   /// @bug not working
   inline std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.describe(); }
}