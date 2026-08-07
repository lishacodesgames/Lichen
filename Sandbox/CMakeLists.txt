add_executable(Sandbox
   src/SandApp.cpp
)

target_link_libraries(Sandbox PRIVATE lichen)
set_target_properties(Sandbox PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Sandbox
)
