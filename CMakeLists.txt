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

add_subdirectory(Lichen)
add_subdirectory(Sandbox)