cmake_minimum_required(VERSION 3.20)
project(LichenEngine LANGUAGES C CXX)

if(NOT DEFINED ENV{CMAKE_PRESET_NAME}) # if someone is running without presets
   set(PRESET_NAME ${CMAKE_BUILD_TYPE})
else()
   set(PRESET_NAME $ENV{CMAKE_PRESET_NAME})
endif()

set(LICHEN_OUTPUT_BASE
   # example: bin/LinuxDebug-x86_64
   ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${PRESET_NAME}-${CMAKE_SYSTEM_PROCESSOR}
)

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