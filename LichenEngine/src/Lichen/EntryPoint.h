#pragma once

#if defined(LCH_PLATFORM_WINDOWS) || defined(LCH_PLATFORM_LINUX)

   extern lichen::Application* lichen::CreateApplication();

   int main() {
      lichen::Log::Init();
      
      lichen::Application* app = lichen::CreateApplication();
      app->Run();
      
      delete app;
      return 0;
   }

#else
   #error Sorry! We do not support your platform
#endif