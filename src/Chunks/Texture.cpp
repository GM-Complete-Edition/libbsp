#include "libbsp/Decoder.hpp"
#include "libbsp/Chunks/Texture.hpp"

namespace bsp {

template<>
Texture BSPDecoder::read(MemoryStream& stream) {
	auto name = readString<int32_t>(stream);
	auto maskName = readString<int32_t>(stream);
	auto width = read<int32_t>(stream);
	auto height = read<int32_t>(stream);
	auto filter = read<int32_t>(stream);
	auto address = read<int32_t>(stream);
	auto format = read<int32_t>(stream);
	auto borderColor = read<Rgba<int32_t>>(stream);

	std::vector<Rgba<int32_t>> pixels;

	pixels.reserve(width * height);

	for (int32_t i = 0; i < width * height; i++) {
		pixels.push_back(read<Rgba<int32_t>>(stream));
	}

	return Texture {
		.name = name,
		.maskName = maskName,
		.width = width,
		.height = height,
		.filter = filter,
		.address = address,
		.format = format,
		.borderColor = borderColor,
		.pixels = pixels
	};
}

}
