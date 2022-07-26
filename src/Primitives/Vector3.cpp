#include "libbsp/Decoder.hpp"
#include "libbsp/Primitives/Vector3.hpp"

namespace bsp {

template<>
Vector3 BSPDecoder::read(MemoryStream& stream) {
	return Vector3 {
		.x = read<float>(stream),
		.y = read<float>(stream),
		.z = read<float>(stream)
	};
}

}
