#include "libbsp/Chunks/ChunkHeader.hpp"
#include "libbsp/Decoder.hpp"

template<>
ChunkHeader BSPDecoder::read(MemoryStream& stream) {
	auto type = readEnum<ChunkType>(stream);
	auto size = read<int32_t>(stream);
	auto version = read<int32_t>(stream);

	return ChunkHeader {
		.type = type,
		.size = size,
		.version = version,
	};
}
