// ONLY MEANT TO BE INCLUDED IN CPP FILES 
// To ensure this, there is no #pragma once

// ---- PLATFORM ----
#if defined(LCH_PLATFORM_WINDOWS)
   #include <Windows.h>
#endif

// ===================================
// 1. STANDARD TEMPLATE LIBRARY (STL)
// ===================================

// Core Types & Utilities
#include <typeinfo>
#include <stdarg.h>
#include <cstdint>
#include <utility>
#include <memory>
#include <tuple>

// Functional & Logic
#include <functional>
#include <algorithm>
#include <optional>
#include <ranges>

// Data Containers
#include <unordered_map>
#include <string_view>
#include <string>
#include <vector>
#include <array>

// Streams & I/O
#include <fstream>
#include <sstream>
#include <format>
#include <cstdio>

#include <iostream> 
#include <iomanip>

// System, Time & Concurrency
#include <source_location>
#include <filesystem>
#include <stdexcept>
#include <chrono>
#include <random>
#include <thread>
#include <ctime>

// ====================================
// 2. THIRD-PARTY / EXTERNAL LIBRARIES
// ====================================

// ---- GLFW ----
#include "GLFW/glfw3.h"

// ---- SPDLOG ----
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// ========================
// 3. INTERNAL ENGINE CORE
// ========================

// tbd
