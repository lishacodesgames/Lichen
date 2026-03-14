set(LICHEN_CPP_SOURCES
   src/Lichen/Application.cpp
)
add_library(LICHEN_H_SOURCES INTERFACE
   src/Lichen/Core.h
)

add_library(LichenShared SHARED ${LICHEN_CPP_SOURCES})
add_library(LichenStatic STATIC ${LICHEN_CPP_SOURCES})

target_link_libraries(LichenShared PUBLIC LICHEN_H_SOURCES)
target_link_libraries(LichenStatic PUBLIC LICHEN_H_SOURCES)

target_include_directories(LichenShared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(LichenStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(LichenShared PRIVATE LICHEN_BUILD_SHARED) ## used for dllexport macro on Windows

# add platform macros
if(WIN32)
   target_compile_definitions(LichenShared PUBLIC LC_PLATFORM_WINDOWS)
   target_compile_definitions(LichenStatic PUBLIC LC_PLATFORM_WINDOWS)
endif()

set_target_properties(LichenShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)
set_target_properties(LichenStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)