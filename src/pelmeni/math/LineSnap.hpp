#pragma once

#include "Vector.hpp"

namespace p2d { namespace math {
    bool snapsToLine(const Vector2f& point, 
                     const Vector2f& p0, 
                     const Vector2f& p1, 
                     float longitudinalMargin, 
                     float widthMargin);
}
}