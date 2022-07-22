#include "libbsp/BSP.hpp"
#include "libbsp/Chunks/ChunkHeader.hpp"
#include "libbsp/Decoder.hpp"

template<>
BSP BSPDecoder::read(MemoryStream& stream) {
	std::vector<ModelPart> modelParts;

	while (stream.isNotEmpty()) {
		auto header = read<ChunkHeader>(stream);

		switch (header.type) {
			case ChunkType::SPMesh:
				modelParts.push_back(read<ModelPart>(stream));
				
				break;
			default:
				stream.advance(header.size);

				break;
		}
	}

	return BSP {
		.modelParts = modelParts,
	};
}
