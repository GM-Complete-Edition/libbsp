#include <cstdint>

#include "libbsp/BSP.hpp"
#include "libbsp/Decoder.hpp"
#include "libbsp/Chunks/ChunkHeader.hpp"

template<>
BSP BSPDecoder::read(MemoryStream& stream) {
	std::vector<Texture> textures;
	std::vector<ModelPart> modelParts;

	while (stream.isNotEmpty()) {
		auto header = read<ChunkHeader>(stream);

		switch (header.type) {
			case ChunkType::Textures:
				{
					auto length = read<int32_t>(stream);

					for (int i = 0; i < length; i++) {
						textures.push_back(read<Texture>(stream));
					}

					break;
				}
			case ChunkType::SPMesh:
				modelParts.push_back(read<ModelPart>(stream));
				
				break;
			default:
				stream.advance(header.size);

				break;
		}
	}

	return BSP {
		.textures = textures,
		.modelParts = modelParts,
	};
}
