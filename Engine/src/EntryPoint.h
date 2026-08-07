#include "Application.h"
#include "Log.h"

// THIS FILE IS MEANT TO BE INCLUDED IN ONLY ONE C++ FILE
// OTHERWISE main() WILL BE DEFINED MULTIPLE TIMES
// To ensure this, there is no #pragma once directive

#ifdef ENTRY_POINT_ACCESSED
   #error "Entry point accessed more than once!"
#endif

#define ENTRY_POINT_ACCESSED

int main() {
   lichen::Log::Init();

   std::unique_ptr<lichen::Application> app = lichen::CreateApplication();
   app->Run();
}
