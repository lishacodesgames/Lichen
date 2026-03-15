#pragma once

#if defined(LCH_PLATFORM_WINDOWS) || defined(LCH_PLATFORM_LINUX)

   extern Lichen::Application* Lichen::CreateApplication();

   int main() {
      Lichen::Log::Init();
      
      Lichen::Application* app = Lichen::CreateApplication();
      app->Run();
      
      delete app;
      return 0;
   }

#else
   #error Sorry! We do not support your platform
#endif