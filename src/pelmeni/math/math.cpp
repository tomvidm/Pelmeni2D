#include "math.hpp"

namespace p2d { namespace math {
    bool floatComp(float a, float b) {
        return std::abs(a - b) < 0.000001f;
    }
} // namespace math
} // namespace p2d