#include "libbsp/Decoder.hpp"
#include "libbsp/Primitives/Rgba.hpp"

template<>
Rgba<uint8_t> BSPDecoder::read(MemoryStream& stream) {
    return Rgba<uint8_t> {
    	.r = read<uint8_t>(stream),
    	.g = read<uint8_t>(stream),
    	.b = read<uint8_t>(stream),
    	.a = read<uint8_t>(stream)
    };
}

template<>
Rgba<int32_t> BSPDecoder::read(MemoryStream& stream) {
    return Rgba<int32_t> {
        .r = static_cast<uint8_t>(read<int32_t>(stream)),
        .g = static_cast<uint8_t>(read<int32_t>(stream)),
        .b = static_cast<uint8_t>(read<int32_t>(stream)),
        .a = static_cast<uint8_t>(read<int32_t>(stream))
    };
}
