#pragma once

#include <cstdlib>

#include "math/Vector.hpp"

namespace p2d { namespace math {
    template <typename T>
    T cubicCatmullRom(const std::vector<T>& controlPoints, float t, size_t i) {
        const float tt = t * t;
        const float ttt = tt * t;
        const float b0 = 0.5f * (-t + 2*tt - ttt);
        const float b1 = 0.5f * (2 - 5*tt + 3*ttt);
        const float b2 = 0.5f * (t + 4*tt - 3*ttt);
        const float b3 = 0.5f * (-tt + ttt);
        return controlPoints[i] * b0 +
               controlPoints[i + 1] * b1 +
               controlPoints[i + 2] * b2 +
               controlPoints[i + 3] * b3;
    }
} // namespace math
} // namespace p2d