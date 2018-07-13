#pragma once

#include "math/Vector.hpp"

namespace p2d { namespace math {
    bool linesIntersect(const Vector2f& u0,
                        const Vector2f& u1,
                        const Vector2f& v0,
                        const Vector2f& v1);
}
}