#pragma once

#include <vector>

#include "Vector.hpp"

namespace p2d { namespace math {
    class ConvexPolygon {
    public:
        ConvexPolygon(const std::vector<Vector2f>& vectors);
        bool containsPoint(const Vector2f& point) const;
    private:
        std::vector<Vector2f> vertices;
    };
}
}