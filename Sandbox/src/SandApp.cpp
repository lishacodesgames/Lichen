#include <Lichen.h>

class Sandbox : public Lichen::Application {
public:
   Sandbox() = default;
   ~Sandbox() = default;
};

Lichen::Application* Lichen::CreateApplication() { 
   int a = 100;
   LCH_CORE_TRACE("I'M BEING TRACED D:");
   LCH_CORE_INFO("Today is a Sunday.");
   LCH_CORE_WARN("This is a {}", "warning");
   LCH_FATAL("CRITICAL");
   LCH_DEBUG("DEBUGGING {}", a);
   LCH_ERROR("You've made an error!!!", a);
   
   return new Sandbox(); 
}