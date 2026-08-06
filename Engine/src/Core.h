#pragma once

#ifdef LCH_PLATFORM_WINDOWS
   #if defined(LCH_BUILD_SHARED)
      #define LCH_API __declspec(dllexport)
   #else
      #define LCH_API __declspec(dllimport)
   #endif
#else
   #define LCH_API
#endif

#ifdef LCH_CFG_DEBUG
   #define LCH_ENABLE_ASSERTS
#endif

#ifdef LCH_ENABLE_ASSERTS
   #define LCH_ASSERT(x, ...) { if(!(x)) { LCH_ERROR("Assertion failed: {}", __VA_ARGS__); } }
   #define LCH_CORE_ASSERT(x, ...) { if(!(x)) { LCH_CORE_ERROR("Assertion failed: {}", __VA_ARGS__); } }
#else
   #define LCH_ASSERT(x, ...)
   #define LCH_CORE_ASSERT(x, ...)
#endif

// sets the (x+1)th bit from the right to 1 i.e. BIT(2) = 2^2 = 0100
#define BIT(x) (1 << x)