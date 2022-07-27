#pragma once

#include <optional>
#include <string>
#include <tuple>
#include <vector>
#include <type_traits>

#include "libbsp/AccessOutOfBoundsException.hpp"
#include "libbsp/MemoryStream.hpp"

namespace bsp {

class BSPDecoder {
public:
    template<typename T>
    [[nodiscard]] T read(MemoryStream& stream);

    template<typename T, typename... PARAMETERS>
    [[nodiscard]] T read(MemoryStream& stream, PARAMETERS... parameters);

    template<typename T>
    [[nodiscard]] std::vector<T> readMany(MemoryStream& stream) {
        auto size = read<int32_t>(stream);

        std::vector<T> elements;

        elements.reserve(size);

        for (int32_t i = 0; i < size; i++) {
            elements.push_back(read<T>(stream));
        }

        return elements;
    }

    template<typename T> requires std::is_same_v<T, uint8_t> || std::is_same_v<T, int32_t>
    [[nodiscard]] std::string readString(MemoryStream& stream, bool isNullTerminated = false) {
        auto length = read<int32_t>(stream);

        if (length > 0) {
            if (isNullTerminated) {
                length -= 1;
            }

            char* const characters = new char[length + 1];

            for (int i = 0; i < length; i++) {
                characters[i] = static_cast<char>(read<T>(stream));
            }

            characters[length] = 0;

            std::string result = characters;

            return result;
        } else {
            return std::string();
        }
    }

    template<typename T> requires std::is_enum_v<T>
    [[nodiscard]] inline T readEnum(MemoryStream& stream) {
        return static_cast<T>(read<std::underlying_type_t<T>>(stream));
    }

    template<typename T>
    [[nodiscard]] std::optional<T> readOptional(MemoryStream& stream) {
        auto isPresent = read<int32_t>(stream);

        if (isPresent) {
            return std::make_optional<T>(read<T>(stream));
        } else {
            return std::nullopt;
        };
    }

    template<typename... Ts>
    [[nodiscard]] inline std::tuple<Ts...> readTuple(MemoryStream& stream) {
        return std::tuple<Ts...>((read<Ts>(stream))...);
    }
};

}
