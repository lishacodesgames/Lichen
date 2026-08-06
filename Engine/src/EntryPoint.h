#pragma once

extern lichen::Application* lichen::CreateApplication();

int main() {
   lichen::Log::Init();
   
   lichen::Application* app = lichen::CreateApplication();
   app->Run();
   
   delete app;
   return 0;
}
