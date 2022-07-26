#pragma once

#include <cstdint>
#include <optional>
#include <tuple>
#include <vector>

#include "libbsp/Primitives/Rgba.hpp"
#include "libbsp/Primitives/Vector3.hpp"

namespace bsp {

constexpr uint32_t HAS_VERTEX = 1 << 8;
constexpr uint32_t HAS_RECIPROCAL_HOMOGENEOUS_W = 1 << 9;
constexpr uint32_t HAS_NORMAL = 1 << 10;
constexpr uint32_t HAS_DIFFUSE = 1 << 11;
constexpr uint32_t HAS_WEIGHT = 1 << 12;
constexpr uint32_t HAS_INDICES = 1 << 13;
constexpr uint32_t UV_COUNT_MASK = 0xFF;

struct Vertex {
    std::optional<Vector3> vertex;
    std::optional<Vector3> normal;
    std::optional<float> reciprocalHomogeneousW;
    std::optional<Rgba<uint8_t>> diffuse;
    std::optional<float> weight;
    std::optional<std::tuple<uint16_t, uint16_t>> indices;
    std::vector<std::tuple<float, float>> uvs;
};

struct Index {
	uint32_t index0;
	uint32_t index1;
	uint32_t index2;
};

struct ModelPart {
    uint32_t readAccessFlags;
    uint32_t vertexReadFlags;
    uint32_t writeAccessFlags;
    uint32_t vertexWriteFlags;
    uint32_t hintFlags;
    uint32_t constantFlags;
    uint32_t vertexFlags;
    uint32_t renderFlags;
    uint16_t trianglesCount;
    uint16_t stripsCount;
    uint16_t stripTrianglesCount;
    uint32_t materialHash;
    int32_t triangleIndex0;
    int32_t triangleIndex1;
    int32_t vertexIndex0;
    int32_t vertexIndex1;
    uint32_t layerZ;
    uint32_t floorFlags;
    uint32_t flags;
    uint32_t lightingSid;
    std::vector<Vertex> vertices;
    std::vector<Index> indices;
};

}
