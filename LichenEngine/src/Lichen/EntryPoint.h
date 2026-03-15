#pragma once

#if defined(LCH_PLATFORM_WINDOWS) || defined(LCH_PLATFORM_LINUX)

   extern Lichen::Application* Lichen::CreateApplication();

   int main() {
      Lichen::Log::Init();

      int a = 100;
      LCH_CORE_TRACE("I'M BEING TRACED D:");
      LCH_CORE_INFO("Today is a Sunday.");
      LCH_CORE_WARN("This is a {}", "warning");
      LCH_FATAL("CRITICAL");
      LCH_DEBUG("DEBUGGING {}", a);
      LCH_ERROR("You've made an error!!!", a);
      
      Lichen::Application* app = Lichen::CreateApplication();
      app->Run();
      
      delete app;
      return 0;
   }

#else
   #error Sorry! We do not support your platform
#endif