// ONLY MEANT TO BE INCLUDED IN CPP FILES 
#pragma once

// ---- LICHEN ----
#include "Lichen/Log.h"

// ---- SPDLOG ----
#define SPDLOG_HEADER_ONLY
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

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

// ---- PLATFORM ----
#if defined(LCH_PLATFORM_WINDOWS)
   #include <Windows.h>
#endif