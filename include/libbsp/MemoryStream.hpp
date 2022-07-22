#pragma once

#include <array>
#include <cstdint>
#include <filesystem>
#include <vector>

class MemoryStream {
private:
    std::vector<uint8_t> bytes;
    size_t currentPosition = 0;
public:
    MemoryStream(std::vector<uint8_t> bytes) : bytes(std::move(bytes)) {}

    static MemoryStream fromFile(const std::filesystem::path& filePath);

    [[nodiscard]] inline bool isNotEmpty() {
        return currentPosition < bytes.size();
    }

    inline void advance(size_t bytes) {
        currentPosition += bytes;
    }

    [[nodiscard]] uint8_t readByte();

    template<size_t COUNT>
    [[nodiscard]] std::array<uint8_t, COUNT> readBytes();
private:
    [[nodiscard]] inline uint8_t readByteUnsafe() {
        return bytes[currentPosition++];
    }
};
