cmake_minimum_required(VERSION 3.20)
project(LichenEngine LANGUAGES C CXX)

# add preset and configuration macros
if(NOT DEFINED LICHEN_PRESET_NAME) # if someone is running without presets
   set(PRESET_NAME ${CMAKE_BUILD_TYPE})

   if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
      add_compile_definitions(LCH_CFG_DEBUG)
   elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
      add_compile_definitions(LCH_CFG_RELEASE)
   else()
      add_compile_definitions(LCH_CFG_DISTRO)
   endif()
else()
   set(PRESET_NAME ${LICHEN_PRESET_NAME})
   
   if("${LICHEN_PRESET_NAME}" STREQUAL "Debug")
      add_compile_definitions(LCH_CFG_DEBUG)
   elseif("${LICHEN_PRESET_NAME}" STREQUAL "Release")
      add_compile_definitions(LCH_CFG_RELEASE)
   else()
      add_compile_definitions(LCH_CFG_DISTRO)
   endif()
endif()

set(LICHEN_OUTPUT_BASE ${CMAKE_SOURCE_DIR}/bin/${PRESET_NAME})

# add platform macros
if(WIN32)
   message(STATUS "PLATFORM DETECTED: Windows")
   add_compile_definitions(LCH_PLATFORM_WINDOWS)
elseif(UNIX)
   message(STATUS "PLATFORM DETECTED: Linux")
   add_compile_definitions(LCH_PLATFORM_LINUX)
endif()

add_subdirectory(LichenEngine)
add_subdirectory(Sandbox)