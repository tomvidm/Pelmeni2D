#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>

#include "vector.hpp"

namespace p2d { namespace math {
    bool floatComp(float a, float b);

    template <typename T>
    T ipow(T base, T exp) {
        T result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result *= base;
            }
            exp >>= 1;
            if (exp == 0) {
                break;
            } else {
                base *= base;
            }
        }
        return result;
    }
} // namespace math
} // namespace p2d

#endif