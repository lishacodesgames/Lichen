set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCL ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EXT ${CMAKE_CURRENT_SOURCE_DIR}/external)

file(GLOB_RECURSE LICHEN_SOURCES ${SRC}/*.cpp)
set(LICHEN_HEADERS ${INCL}/lchpch.h ${INCL}/Lichen.h)

find_package(OpenGL REQUIRED) # required for glfw
add_subdirectory(external/glfw)
add_subdirectory(external/spdlog)

# Maybe add a static lib version
add_library(lichen SHARED ${LICHEN_SOURCES} ${LICHEN_HEADERS})
target_link_libraries(lichen PRIVATE glfw spdlog::spdlog_header_only)
target_precompile_headers(lichen PUBLIC ${INCL}/lchpch.h)
target_include_directories(lichen PUBLIC 
   ${EXT}/spdlog/include
   ${EXT}/glfw/include
   ${INCL}
   ${SRC}
)

# used for dllexport macro on Windows
target_compile_definitions(lichen PRIVATE LCH_BUILD_SHARED) 

# add preset and configuration macros
if(NOT DEFINED LICHEN_PRESET_NAME) # if someone is running without presets
   message(FATAL_ERROR "Please use presets to build Lichen. See README.md for more information.")
else()
   set(PRESET_NAME ${LICHEN_PRESET_NAME})
   
   if("${LICHEN_PRESET_NAME}" STREQUAL "Debug")
      target_compile_definitions(lichen PRIVATE LCH_CFG_DEBUG)
   elseif("${LICHEN_PRESET_NAME}" STREQUAL "Release")
      target_compile_definitions(lichen PRIVATE LCH_CFG_RELEASE)
   else()
      target_compile_definitions(lichen PRIVATE LCH_CFG_DISTRO)
   endif()
endif()

# add platform macros
if(WIN32)
   message(STATUS "PLATFORM DETECTED: Windows")
   target_compile_definitions(lichen PUBLIC LCH_PLATFORM_WINDOWS)
elseif(APPLE)
   message(STATUS "PLATFORM DETECTED: MacOS")
   target_compile_definitions(lichen PUBLIC LCH_PLATFORM_MACOS)
elseif(UNIX AND NOT APPLE)
   message(STATUS "PLATFORM DETECTED: Linux")
   target_compile_definitions(lichen PUBLIC LCH_PLATFORM_LINUX)
endif()

set_target_properties(lichen PROPERTIES 
   LIBRARY_OUTPUT_DIRECTORY # Shared library (non-Windows)
      ${LICHEN_OUTPUT_BASE}/Lichen
   RUNTIME_OUTPUT_DIRECTORY # Windows DLL
      ${LICHEN_OUTPUT_BASE}/Lichen
)

# copy library into exe's folder otherwise Windows throws tantrum
add_custom_command(TARGET lichen POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:lichen>
      $<TARGET_FILE_DIR:Sandbox>
)
