#pragma once

#if defined(LC_PLATFORM_WINDOWS) || defined(LC_PLATFORM_LINUX)

extern Lichen::Application* Lichen::CreateApplication();

   int main() {
      Lichen::Application* app = Lichen::CreateApplication();
      app->Run();
      
      delete app;
      return 0;
   }

#else
   #error Sorry! We do not support your platform
#endif