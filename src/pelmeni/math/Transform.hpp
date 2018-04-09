#pragma once

#include <array>

#include "math/Vector.hpp"

namespace p2d { namespace math {
    class Transform {
    public:
        Transform(float m00, float m01, float m02,
                  float m10, float m11, float m12,
                  float m20, float m21, float m22);

        Transform(const Transform& rhs);
        Transform(Transform&& rhs);

        Vector2f transformVector(const Vector2f& vec) const;
        Vector2f transformPoint(const float& x, const float& y) const;

        
        
        static Transform Rotation(const float& theta);
        static Transform Scale(const float& sx, const float& sy);
        static Transform Translate(const float& dx, const float& dy);
        static Transform Translate(const Vector2f& dr);
        static Transform Identity();

        friend Transform operator * (const Transform& lhs, const float& rhs);
        friend Transform operator * (const float& lhs, const Transform& rhs);
        friend Transform operator * (const Transform& lhs, const Transform& rhs);
        friend Vector2f operator * (const Transform& lhs, const Vector2f& rhs);

        friend float determinant(const Transform& t);
        friend Transform inverse(const Transform& t);

        friend std::string toString(const Transform& rhs);
    protected:
        std::array<float, 9> mat;
    }; // class Transform

    Transform operator * (const Transform& lhs, const float& rhs);
    Transform operator * (const float& lhs, const Transform& rhs);
    Transform operator * (const Transform& lhs, const Transform& rhs);
    Vector2f operator * (const Transform& lhs, const Vector2f& rhs);

    float determinant(const Transform& t);
    Transform inverse(const Transform& t);

    std::string toString(const Transform& rhs);
} // namespace math
} // namespace p2d

