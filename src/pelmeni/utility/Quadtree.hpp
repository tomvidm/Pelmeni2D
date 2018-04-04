#pragma once

#include <array>
#include <cmath>
#include <cstdio>
#include <type_traits>

#include "math/math.hpp"

#include "utility/Quad.hpp"

namespace p2d { namespace utility {
    constexpr unsigned NumberOfQuads(unsigned K) {
        return (static_cast<unsigned>(std::pow(4, K + 1)) - 1)/3;
    }

    unsigned indexOfNW(const unsigned& i) {
        return 4*i + 1;
    }

    unsigned indexOfNE(const unsigned& i) {
        return 4*i + 2;
    }

    unsigned indexOfSW(const unsigned& i) {
        return 4*i + 3;
    }

    unsigned indexOfSE(const unsigned& i) {
        return 4*i + 4;
    }

    template <typename T, unsigned K, unsigned N>
    class Quadtree {
    public:
        Quadtree();
    private:
        const unsigned order;

        std::array<Quad<T, N>, NumberOfQuads(K)> quads;
    }; // class Quadtree

    template <typename T, unsigned K, unsigned N>
    Quadtree<T, K, N>::Quadtree()
    : order(K) {
        printf("Quadtree containing type %s of order %u constructed.\n", typeid(T).name(), K);
        printf("  Total number of Quads = %u\n", NumberOfQuads(K));
        printf("  sizeof(this class) = %zu\n bytes", sizeof(*this));
    }
} // namespace utility
} // namespace p2d