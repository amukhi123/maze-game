#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

using uint8 = uint8_t;
using uint32 = uint32_t;

using String = std::string;

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using UniquePtr = std::unique_ptr<T>;
