#pragma once

#include <optional>
#include <tuple>
#include <vector>

#include "libbsp/AccessOutOfBoundsException.hpp"
#include "libbsp/MemoryStream.hpp"

class BSPDecoder {
public:
    template<typename T>
    [[nodiscard]] T read(MemoryStream& stream);

    template<typename T, typename... PARAMETERS>
    [[nodiscard]] T read(MemoryStream& stream, PARAMETERS... parameters);

    template<typename T>
    [[nodiscard]] std::vector<T> readMany(MemoryStream& stream);

    template<typename T>
    [[nodiscard]] std::optional<T> readOptional(MemoryStream& stream);

    template<typename... Ts>
    [[nodiscard]] std::tuple<Ts...> readTuple(MemoryStream& stream);
};
