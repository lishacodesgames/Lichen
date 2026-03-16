// ONLY MEANT TO BE INCLUDED IN CPP FILES 
#pragma once

// ---- SPDLOG ----
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"

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