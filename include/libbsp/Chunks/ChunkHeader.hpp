#pragma once

#include <cstdint>

#include "libbsp/Chunks/ChunkType.hpp"

struct ChunkHeader {
	ChunkType type;
	int32_t size;
	int32_t version;
};
