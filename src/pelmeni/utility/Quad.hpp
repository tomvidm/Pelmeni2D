#pragma once

#include <array>
#include <cmath>
#include <cstdio>
#include <type_traits>

#include "math/math.hpp"

namespace p2d { namespace utility {
    template <typename T, unsigned N>
    class Quad {
    public:
        Quad();
    private:
        std::array<T, N> elements;

        const unsigned elementsPerLeaf;
    }; // class Quad

    template <typename T, unsigned N>
    Quad<T, N>::Quad()
    : elementsPerLeaf(N) {

    }
} // namespace utility
} // namespace p2d