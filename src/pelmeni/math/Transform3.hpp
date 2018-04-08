#pragma once

#include <array>

#include "math/Vector.hpp"

namespace p2d { namespace math {
    class Transform3 {
    public:
        Transform3(float m00, float m01, float m02, float m03,
                  float m10, float m11, float m12, float m13,
                  float m20, float m21, float m22, float m23,
                  float m30, float m31, float m32, float m33);

        Transform3(const Transform3& rhs);
        Transform3(Transform3&& rhs);

        static Transform3 Identity();

        std::array<float, 16> mat;
    }; // class Transform
/* 
    Transform operator * (const Transform& lhs, const float& rhs);
    Transform operator * (const float& lhs, const Transform& rhs);
    Transform operator * (const Transform& lhs, const Transform& rhs);
    Vector3f operator * (const Transform& lhs, const Vector2f& rhs);
 */
} // namespace math
} // namespace p2d

