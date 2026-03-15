#pragma once

#if defined(LCH_PLATFORM_WINDOWS)
   #if defined(LCH_BUILD_SHARED)
      #define LCH_API __declspec(dllexport)
   #else
      #define LCH_API __declspec(dllimport)
   #endif
#else
   #define LCH_API
#endif