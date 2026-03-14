set(LICHEN_SOURCES
   src/Test.cpp
)

add_library(LichenShared SHARED ${LICHEN_SOURCES})
add_library(LichenStatic STATIC ${LICHEN_SOURCES})

target_include_directories(LichenShared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(LichenStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(LichenShared PRIVATE LICHEN_BUILD_DLL)

set_target_properties(LichenShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)
set_target_properties(LichenStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)