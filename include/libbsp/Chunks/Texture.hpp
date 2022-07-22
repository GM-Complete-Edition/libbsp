#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "libbsp/Primitives/Rgba.hpp"

struct Texture {
	std::string name;
	std::string maskName;
	int32_t width;
	int32_t height;
	int32_t filter;
	int32_t address;
	int32_t format;
	Rgba<int32_t> borderColor;
	std::vector<Rgba<int32_t>> pixels;
};
