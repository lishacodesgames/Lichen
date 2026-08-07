#include "Core.h"

namespace lichen 
{
   class Event;

   struct WindowProperties {
      uint32_t width, height;
      std::string title;

      WindowProperties(const std::string& title = "Lichen Game Engine", uint32_t width = 800, uint32_t height = 600) 
         : width(width), height(height), title(title) {}
   };

   /// Parent window class for future platform abstraction
   class LCH_API Window {
   public:
      using EventCallbackFunction = std::function<void(Event&)>;
      static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties()) { return std::make_unique<Window>(props); }

      Window(const WindowProperties& props) { Init(props); }
      ~Window() { Shutdown(); } // Might make virtual for platform abstraction

      void OnUpdate();

   public: // setters
      inline void setEventCallback(const EventCallbackFunction& fxn) { m_data.eventCallback = fxn; }
      void setVSync(bool enabled);

   public: // getters
      inline uint32_t getWidth() const { return m_data.properties.width; }
      inline uint32_t getHeight() const { return m_data.properties.height; }

      inline bool isVSync() const { return m_data.isVSync; }

   private: 
      struct WindowData {
         WindowProperties properties;
         bool isVSync;
         EventCallbackFunction eventCallback;
      };

   private: 
      GLFWwindow* m_window;
      WindowData m_data;

   private: 
      void Init(const WindowProperties& props);
      void Shutdown() { glfwDestroyWindow(m_window); }
   };
}