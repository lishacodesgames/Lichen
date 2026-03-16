set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB LICHEN_SOURCES   ${SRC}/Lichen/*.cpp ${SRC}/Lichen/*.h)

# Maybe add a static lib version
add_library(lichen SHARED ${LICHEN_SOURCES})
target_precompile_headers(lichen PUBLIC ${SRC}/lchpch.h)

# used for dllexport macro on Windows
target_compile_definitions(lichen PRIVATE LCH_BUILD_SHARED) 

target_include_directories(lichen PUBLIC 
   ${SRC}
   ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include
)

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