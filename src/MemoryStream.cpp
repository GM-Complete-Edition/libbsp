#include <fstream>

#include "libbsp/AccessOutOfBoundsException.hpp"
#include "libbsp/MemoryStream.hpp"

namespace bsp {

MemoryStream MemoryStream::fromFile(const std::filesystem::path& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    std::vector<uint8_t> fileContents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    return MemoryStream(fileContents);
}

uint8_t MemoryStream::readByte() {
    if (currentPosition >= bytes.size()) {
        throw AccessOutOfBoundsException();
    }

    return readByteUnsafe();
}

template<size_t COUNT>
std::array<uint8_t, COUNT> MemoryStream::readBytes() {
    if (currentPosition + (COUNT - 1) >= bytes.size()) {
        throw AccessOutOfBoundsException();
    }

    std::array<uint8_t, COUNT> readBytes;

    for (size_t i = 0; i < COUNT; i++) {
        readBytes[i] = readByteUnsafe();
    }

    return readBytes;
}

}
