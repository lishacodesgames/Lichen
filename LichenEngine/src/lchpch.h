// ONLY MEANT TO BE INCLUDED IN CPP FILES 
#pragma once

// ---- GLFW ----
#include "GLFW/glfw3.h"

// ---- SPDLOG ----
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// ---- PLATFORM ----
#if defined(LCH_PLATFORM_WINDOWS)
   #include <Windows.h>
#endif

// ---- STL ----
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <array>

#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>
#include <memory>
#include <cstdint>