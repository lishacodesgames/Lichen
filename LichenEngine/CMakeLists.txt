set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB LICHEN_SOURCES   ${SRC}/Lichen/*.cpp ${SRC}/Lichen/*.h)

# Maybe add a static lib version
add_library(lichen SHARED ${LICHEN_SOURCES})

## used for dllexport macro on Windows
target_compile_definitions(lichen PRIVATE LCH_BUILD_SHARED) 

target_include_directories(lichen PUBLIC 
   ${SRC}
   ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
)

set_target_properties(lichen PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)