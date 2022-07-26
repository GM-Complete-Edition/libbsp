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
    [[nodiscard]] std::vector<T> readMany(MemoryStream& stream);

    template<typename T> requires std::is_same_v<T, uint8_t> || std::is_same_v<T, int32_t>
    [[nodiscard]] std::string readString(MemoryStream& stream, bool isNullTerminated = false);

    template<typename T> requires std::is_enum_v<T>
    [[nodiscard]] T readEnum(MemoryStream& stream);

    template<typename T>
    [[nodiscard]] std::optional<T> readOptional(MemoryStream& stream);

    template<typename... Ts>
    [[nodiscard]] std::tuple<Ts...> readTuple(MemoryStream& stream);
};

}
