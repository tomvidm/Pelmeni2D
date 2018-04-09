#include <cmath>

#include "Helpers.hpp"

namespace p2d { namespace ut {
    bool floatCompare(const float& lhs, const float& rhs) {
        static const float epsilon = 0.00005;
        return std::abs(lhs - rhs) < epsilon;
    }
}
}