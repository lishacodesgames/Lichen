cmake_minimum_required(VERSION 3.20)
project(Lichen LANGUAGES C CXX)

set(LICHEN_OUTPUT_BASE ${CMAKE_SOURCE_DIR}/bin/${PRESET_NAME})
add_subdirectory(Engine)
add_subdirectory(Sandbox)