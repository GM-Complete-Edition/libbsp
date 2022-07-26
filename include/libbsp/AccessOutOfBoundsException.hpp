#pragma once

#include <exception>

namespace bsp {

class AccessOutOfBoundsException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Attempted to access a value out of bounds";
    }
};

}
