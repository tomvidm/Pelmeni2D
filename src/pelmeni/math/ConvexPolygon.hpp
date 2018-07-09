#pragma once

#include <vector>

#include "../utility/Rect.hpp"

#include "Vector.hpp"

namespace p2d { namespace math {
    class ConvexPolygon {
    public:
        ConvexPolygon(const std::vector<Vector2f>& vectors);
        utility::Rect<float> getBoundingBox() const;
        bool containsPoint(const Vector2f& point) const;
        const std::vector<Vector2f>& getVertices() const;
    private:
        void calculateBoundingBox();
        void updateMostDistantVertex();
        void calculateCenter();
        std::vector<Vector2f> vertices;
        utility::Rect<float> boundingBox;
        Vector2f centerPoint;
        float rangeToMostDistantVertex;
    };

    bool intersects(const ConvexPolygon& first, const ConvexPolygon& second);
}
}