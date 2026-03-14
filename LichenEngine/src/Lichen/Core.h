#pragma once

#if defined(LC_PLATFORM_WINDOWS)
   #if defined(LC_BUILD_SHARED)
      #define LICH_API __declspec(dllexport)
   #else
      #define LICH_API __declspec(dllimport)
   #endif
#else
   #define LICH_API
#endif