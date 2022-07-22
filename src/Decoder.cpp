#include <bit>
#include <cstdint>

#include "libbsp/Decoder.hpp"

template<>
int8_t BSPDecoder::read(MemoryStream& stream) {
    return std::bit_cast<int8_t>(stream.readByte());
}

template<>
uint8_t BSPDecoder::read(MemoryStream& stream) {
    return stream.readByte();
}

template<>
int16_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return std::bit_cast<int16_t>(
        static_cast<uint16_t>((static_cast<uint16_t>(firstByte) << 8) | static_cast<uint16_t>(secondByte))
    );
}

template<>
uint16_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return static_cast<uint16_t>((static_cast<uint16_t>(firstByte) << 8) | static_cast<uint16_t>(secondByte));
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
int64_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t eightByte = stream.readByte();
    uint8_t seventhByte = stream.readByte();
    uint8_t sixthByte = stream.readByte();
    uint8_t fifthByte = stream.readByte();
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return std::bit_cast<int64_t>((static_cast<uint64_t>(firstByte) << 56) 
        | (static_cast<uint64_t>(secondByte) << 48) 
        | (static_cast<uint64_t>(thirdByte) << 40) 
        | (static_cast<uint64_t>(fourthByte) << 32)
        | (static_cast<uint64_t>(fifthByte) << 24)
        | (static_cast<uint64_t>(sixthByte) << 16)
        | (static_cast<uint64_t>(seventhByte) << 8)
        | (static_cast<uint64_t>(eightByte) << 0));
}

template<>
uint64_t BSPDecoder::read(MemoryStream& stream) {
    uint8_t eightByte = stream.readByte();
    uint8_t seventhByte = stream.readByte();
    uint8_t sixthByte = stream.readByte();
    uint8_t fifthByte = stream.readByte();
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return (static_cast<uint64_t>(firstByte) << 56) 
        | (static_cast<uint64_t>(secondByte) << 48) 
        | (static_cast<uint64_t>(thirdByte) << 40) 
        | (static_cast<uint64_t>(fourthByte) << 32)
        | (static_cast<uint64_t>(fifthByte) << 24)
        | (static_cast<uint64_t>(sixthByte) << 16)
        | (static_cast<uint64_t>(seventhByte) << 8)
        | (static_cast<uint64_t>(eightByte) << 0);
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

template<>
double BSPDecoder::read(MemoryStream& stream) {
    uint8_t eightByte = stream.readByte();
    uint8_t seventhByte = stream.readByte();
    uint8_t sixthByte = stream.readByte();
    uint8_t fifthByte = stream.readByte();
    uint8_t fourthByte = stream.readByte();
    uint8_t thirdByte = stream.readByte();
    uint8_t secondByte = stream.readByte();
    uint8_t firstByte = stream.readByte();

    return std::bit_cast<double>((static_cast<uint64_t>(firstByte) << 56) 
        | (static_cast<uint64_t>(secondByte) << 48) 
        | (static_cast<uint64_t>(thirdByte) << 40) 
        | (static_cast<uint64_t>(fourthByte) << 32)
        | (static_cast<uint64_t>(fifthByte) << 24)
        | (static_cast<uint64_t>(sixthByte) << 16)
        | (static_cast<uint64_t>(seventhByte) << 8)
        | (static_cast<uint64_t>(eightByte) << 0));
}

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

template<typename T> requires std::is_enum_v<T>
T BSPDecoder::readEnum(MemoryStream& stream) {
    return read<std::underlying_type_t<T>>(stream);
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
