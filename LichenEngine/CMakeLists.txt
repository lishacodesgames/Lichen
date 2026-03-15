set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/Lichen)

file(GLOB LICHEN_SOURCES   ${SRC}/*.cpp ${SRC}/*.h)

# Maybe add a static lib version
add_library(Lichen_SharedLib SHARED ${LICHEN_SOURCES})

## used for dllexport macro on Windows
target_compile_definitions(Lichen_SharedLib PRIVATE LCH_BUILD_SHARED) 

target_include_directories(Lichen_SharedLib PUBLIC 
   ${SRC}
   ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
)

set_target_properties(Lichen_SharedLib PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Lichen)