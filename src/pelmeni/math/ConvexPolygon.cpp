#include <limits>

#include "ConvexPolygon.hpp"

namespace p2d { namespace math {
    ConvexPolygon::ConvexPolygon(const std::vector<Vector2f>& vectors)
    : vertices(vectors) {
        updateMostDistantVertex();
        calculateBoundingBox();
    }

    utility::Rect<float> ConvexPolygon::getBoundingBox() const {
        return boundingBox;
    }

    bool ConvexPolygon::containsPoint(const Vector2f& point) const {
        // Check if point is contained in the bounding box.
        if (!boundingBox.contains(point)) {
            return false;
        }

        for (size_t i = 0; i < vertices.size(); i++) {
            const size_t ipp = (i + 1) % vertices.size();
            const Vector2f edge = vertices[ipp] - vertices[i];
            const Vector2f edgeToPoint = point - vertices[i];
            if (cross(edge, edgeToPoint) < 0.f) {
                return false;
            }
        }

        return true;
    }

    const std::vector<Vector2f>& ConvexPolygon::getVertices() const {
        return vertices;
    }

    // When checking for collision, the first check should be to check if the enclosing circle
    // of two convex polygons overlap. This can be done independed of rotation, so any trasforms
    // other than scale can be ignored. This saves computation in the negative case.
    void ConvexPolygon::updateMostDistantVertex() {
        float rangeToMostDistantVertex = 0.f;
        for (auto v : vertices) {
            float vDistance = magnitudeSquared(v);
            if (vDistance > rangeToMostDistantVertex) {
                rangeToMostDistantVertex = vDistance;
            }
        }
    }

    void ConvexPolygon::calculateCenter() {
        centerPoint = Vector2f(0.f, 0.f);
        for (auto v : vertices) {
            centerPoint = centerPoint + v;
        }
        centerPoint = centerPoint * (1.f / static_cast<float>(vertices.size()));
    }

    void ConvexPolygon::calculateBoundingBox() {
        float min_x = std::numeric_limits<float>::max();
        float max_x = std::numeric_limits<float>::lowest();
        float min_y = std::numeric_limits<float>::max();
        float max_y = std::numeric_limits<float>::lowest();

        for (auto v : vertices) {
            if (v.x < min_x) {
                min_x = v.x;
            }
            if (v.x > max_x) {
                max_x = v.x;
            }
            if (v.y < min_y) {
                min_y = v.y;
            }
            if (v.y > max_y) {
                max_y = v.y;
            }
        }

        boundingBox = utility::Rect<float>(min_x, min_y, max_x - min_x, max_y - min_y);
    }
}
}