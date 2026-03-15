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

// sets the (x+1)th bit from the right to 1 i.e. BIT(2) = 2^2 = 0100
#define BIT(x) (1 << x)