#pragma once

#if defined(LC_PLATFORM_WINDOWS) || defined(LC_PLATFORM_LINUX)

   extern Lichen::Application* Lichen::CreateApplication();

   int main() {
      Lichen::Log::Init();

      int a = 100;
      Lichen::Log::GetCoreLogger()->info("Today is a Sunday.");
      Lichen::Log::GetCoreLogger()->warn("This is a {}", "warning");
      Lichen::Log::GetClientLogger()->debug("DEBUGGING {}", a);
      Lichen::Log::GetClientLogger()->error("You've made an error!!!", a);
      
      Lichen::Application* app = Lichen::CreateApplication();
      app->Run();
      
      delete app;
      return 0;
   }

#else
   #error Sorry! We do not support your platform
#endif