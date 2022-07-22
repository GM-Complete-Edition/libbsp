#include <bit>
#include <cstdint>

#include "libbsp/Decoder.hpp"

template<typename T>
std::vector<T> BSPDecoder::readMany(MemoryStream& stream) {
    auto size = read<int32_t>(stream);

    std::vector<T> elements;

    elements.reserve(size);

    for (int32_t i = 0; i < size; i++) {
        elements.push_back(read<T>(stream));
    }

    return elements;
}

template<typename T>
std::optional<T> BSPDecoder::readOptional(MemoryStream& stream) {
    auto isPresent = read<int32_t>(stream);

    if (isPresent) {
        return std::make_optional<T>(read<T>(stream));
    } else {
        return std::nullopt;
    };
}

template<typename... Ts>
std::tuple<Ts...> BSPDecoder::readTuple(MemoryStream& stream) {
    return std::tuple<Ts...>((read<Ts>(stream))...);
}

template<>
uint8_t BSPDecoder::read(MemoryStream& stream) {
    return stream.readByte();
}

template<>
uint16_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return (static_cast<uint16_t>(firstByte) << 8) | static_cast<uint16_t>(secondByte);
}

template<>
int32_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return std::bit_cast<int32_t>(
        (static_cast<uint32_t>(firstByte) << 24) 
        | (static_cast<uint32_t>(secondByte) << 16) 
        | (static_cast<uint32_t>(thirdByte) << 8) 
        | (static_cast<uint32_t>(fourthByte) << 0)
    );
}

template<>
uint32_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return (static_cast<uint32_t>(firstByte) << 24) 
        | (static_cast<uint32_t>(secondByte) << 16) 
        | (static_cast<uint32_t>(thirdByte) << 8) 
        | (static_cast<uint32_t>(fourthByte) << 0);
}

template<>
float BSPDecoder::read(MemoryStream& stream) {
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return std::bit_cast<float>(
        (static_cast<uint32_t>(firstByte) << 24) 
        | (static_cast<uint32_t>(secondByte) << 16) 
        | (static_cast<uint32_t>(thirdByte) << 8) 
        | (static_cast<uint32_t>(fourthByte) << 0)
    );
}
