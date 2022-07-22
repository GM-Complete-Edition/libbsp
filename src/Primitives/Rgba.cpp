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
