#include "ConvexPolygon.hpp"

namespace p2d { namespace math {
    ConvexPolygon::ConvexPolygon(const std::vector<Vector2f>& vectors)
    : vertices(vectors) {
        ;
    }

    bool ConvexPolygon::containsPoint(const Vector2f& point) const {
        for (size_t i = 0; i < vertices.size(); i++) {
            const size_t ipp = (i + 1) % vertices.size();
            const Vector2f edge = vertices[ipp] - vertices[i];
            const Vector2f edgeToPoint = point - vertices[i];
            if (dot(edge, edgeToPoint) < 0.f) {
                return false;
            }
        }

        return true;
    }
}
}