#pragma once

#include <array>
#include <cmath>
#include <cstdio>
#include <type_traits>
#include <stack>

#include "math/math.hpp"

#include "utility/Quad.hpp"

namespace p2d { namespace utility {
    constexpr unsigned NumberOfQuads(unsigned K) {
        return (static_cast<unsigned>(std::pow(4, K + 1)) - 1)/3;
    }
    unsigned indexOfParnet(const unsigned& i) {
        return (i - 1)/4;
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
        void setRootBoundingRect(const utility::Rect<float>& rect);
    private:
        const unsigned order;
        const unsigned numberOfQuads;

        std::array<Quad<T, N>, NumberOfQuads(K)> quads;
        std::array<unsigned, NumberOfQuads(K)> containedElements;
    }; // class Quadtree

    template <typename T, unsigned K, unsigned N>
    Quadtree<T, K, N>::Quadtree()
    : order(K), numberOfQuads(NumberOfQuads(K)) {
        printf("Quadtree containing type %s of order %u constructed.\n", typeid(T).name(), K);
        printf("  Total number of Quads = %u\n", NumberOfQuads(K));
        printf("  sizeof(this class) = %f kb\n", static_cast<float>(sizeof(*this))/1000.f);
    }

    template <typename T, unsigned K, unsigned N>
    void Quadtree<T, K, N>::setRootBoundingRect(const utility::Rect<float>& rect) {
        std::stack<unsigned> queue{0};
        while (queue.empty()) {
            queue.pop();
        }
    }
} // namespace utility
} // namespace p2d