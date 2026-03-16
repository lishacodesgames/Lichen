#include <lchpch.h>
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"

void lichen::Application::Run() {
   int a = 100;
   LCH_CORE_TRACE("I'M BEING TRACED D:");
   LCH_CORE_INFO("Today is a Sunday.");
   LCH_CORE_WARN("This is a {}", "warning");
   LCH_FATAL("CRITICAL");
   LCH_DEBUG("DEBUGGING {}", a);
   LCH_ERROR("You've made an error!!!\n", a);
   
   WindowResizeEvent e(120, 322);
   LCH_CORE_TRACE("{}", e.describe());

   if(e.hasCategory(EventCategoryApplication))
      LCH_INFO("This is an Application event.");
   else  
      LCH_CORE_ERROR("Window reisze is supposed to be an Application event!");
}