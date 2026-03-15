add_executable(Sandbox
   src/SandApp.cpp
)

target_link_libraries(Sandbox PRIVATE lichen)
set_target_properties(Sandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Sandbox)
target_include_directories(Sandbox PRIVATE 
   ${CMAKE_SOURCE_DIR}/LichenEngine/src
   ${CMAKE_SOURCE_DIR}/LichenEngine/external/spdlog/include
)