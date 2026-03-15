set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/Lichen)

file(GLOB LICHEN_CPP_SOURCES ${SRC}/*.cpp)
add_library(LICHEN_H_SOURCES INTERFACE
   ${SRC}/Core.h
   ${SRC}/EntryPoint.h
)
# Maybe add a static lib version

add_library(LichenShared SHARED ${LICHEN_CPP_SOURCES})
add_library(LichenStatic STATIC ${LICHEN_CPP_SOURCES})

target_link_libraries(LichenShared PUBLIC LICHEN_H_SOURCES)
target_link_libraries(LichenStatic PUBLIC LICHEN_H_SOURCES)

target_include_directories(LichenShared PUBLIC 
   ${SRC}
   ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
)
target_include_directories(LichenStatic PUBLIC
   ${SRC}
   ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
)

## used for dllexport macro on Windows
target_compile_definitions(LichenShared PRIVATE LCH_BUILD_SHARED) 

set_target_properties(LichenShared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)
set_target_properties(LichenStatic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)