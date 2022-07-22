#pragma once

#include <vector>

#include "libbsp/Chunks/ModelPart.hpp"
#include "libbsp/Chunks/Texture.hpp"

class BSP {
public:
	std::vector<Texture> textures;
	std::vector<ModelPart> modelParts;
};
