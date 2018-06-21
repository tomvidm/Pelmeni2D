#pragma once

#include <math.h>

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

namespace p2d { namespace math {
    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;
    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;
    typedef Vector4<float> Vector4f;

    template <typename T>
    Vector2<T> projectToXY(const Vector3<T>& vec) {
        return Vector2<T>(vec.x, vec.y);
    }
} // namespace math
} // namespace p2d