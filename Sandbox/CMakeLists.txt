add_executable(Sandbox
   src/Application.cpp
)

target_link_libraries(Sandbox PRIVATE LichenShared)
set_target_properties(Sandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LICHEN_OUTPUT_BASE}/Sandbox)