#pragma once

#include <array>
#include <cmath>
#include <cstdio>
#include <type_traits>

#include "math/math.hpp"
#include "utility/Rect.hpp"

namespace p2d { namespace utility {
    template <typename T, unsigned N>
    class Quad {
    public:
        Quad();

        inline bool isEmpty() const { return elementsInLeaf == 0; }
        inline bool isFull() const { return elementsInLeaf == elementsPerLeaf; }
        inline unsigned numElements() const { return elementsInLeaf; }
        inline utility::Rect<float> getBoundingRect() const { return boundingRect; }

        bool contains(math::Vector2f& point) const;

        bool push(const T& obj);
    private:
        utility::Rect<float> boundingRect;
        std::array<T, N> elements;

        const unsigned elementsPerLeaf;
              unsigned elementsInLeaf;
    }; // class Quad

    template <typename T, unsigned N>
    Quad<T, N>::Quad() : 
    elementsPerLeaf(N), 
    elementsInLeaf(0) {;}

    template <typename T, unsigned N>
    bool Quad<T, N>::push(const T& obj) {
        if (isFull()) {
            return false;
        } else {
            elements[elementsInLeaf] = obj;
            ++elementsInLeaf;
        }
    } // bool push

    template <typename T, unsigned N>
    bool Quad<T, N>::contains(math::Vector2f& point) const {
        return boundingRect.contains(point);
    } // bool contains
} // namespace utility
} // namespace p2d