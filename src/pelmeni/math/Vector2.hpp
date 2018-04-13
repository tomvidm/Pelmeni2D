#pragma once

#include <utility>
#include <math.h>

#include "SFML/System/Vector2.hpp"

#include "math/Radian.hpp"

namespace p2d { namespace math {
    using sf::Vector2;
    
    template <typename T>
    Vector2<T> projectToX(const Vector2<T>& vec) {
        return Vector2<T>(vec.x, 0);
    }

    template <typename T>
    Vector2<T> projectToY(const Vector2<T>& vec) {
        return Vector2<T>(0, vec.y);
    }

    template <typename T>
    Vector2<T> project(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return rhs * (dot(lhs, rhs)/dot(rhs, rhs));
    }

    template <typename T>
    float magnitudeSquared(const Vector2<T>& vec) {
        return static_cast<float>(vec.x * vec.x + vec.y * vec.y);
    }

    template <typename T>
    float magnitude(const Vector2<T>& vec) {
        return sqrtf(magnitudeSquared(vec));
    }

    template <typename T>
    float cross(const Vector2<T>& v0, const Vector2<T>& v1) {
        return v0.x * v1.y - v0.y * v1.x;
    }

    template <typename T>
    float angleBetween(const Vector2<T>& a, const Vector2<T>& b) {
        return atan2f(b.y - a.y, b.x - a.x);
    }

    template <typename T>
    Vector2<float> getUnitVector(const math::Radian& rads) {
        return Vector2<float>(cosf(rads.toRadians()), sinf(rads.toRadians()));
    }

    template <typename T>
    Vector2<float> normalize(const Vector2<T>& vec) {
        return vec * (1.f / magnitude(vec));
    }

    template <typename T>
    T dot(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    // Compute cosine of angle between lhs and rhs
    template <typename T>
    float cosTheta(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        return dot(lhs, rhs) / (magnitude(lhs) * magnitude(rhs));
    }
} // namespace math
} // namespace p2d
