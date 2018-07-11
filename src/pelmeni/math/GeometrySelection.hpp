#pragma once

#include "Vector.hpp"

namespace p2d { namespace math {
    bool snapsToLine(const Vector2f& point, 
                     const Vector2f& p0, 
                     const Vector2f& p1, 
                     const float longitudinalMargin, 
                     const float widthMargin);

    bool snapsToPoint(const Vector2f& queryPoint,
                      const Vector2f& point,
                      const float threshold);

    bool snapsToRing(const Vector2f& queryPoint,
                     const Vector2f& center,
                     const float ringRadius,
                     const float ringThreshold);
}
}