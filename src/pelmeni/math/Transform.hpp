#pragma once

#include "math/vector.hpp"

namespace p2d { namespace math {
    class Transform {
    public:
        Transform(float m00, float m01, float m02,
                  float m10, float m11, float m12,
                  float m20, float m21, float m22);

        Vector2f transformVector(const Vector2f& vec) const;

        static Transform Rotation(const float& theta);
        static Transform Scale(const float& sx, const float& sy);
        static Transform Translate(const float& dx, const float& dy);
        static Transform Translate(const Vector2f& dr);

        friend Transform operator * (const Transform& lhs, const Transform& rhs);

        void print() const;
    protected:
        float mat[9];
    }; // class Transform

    Transform operator * (const Transform& lhs, const Transform& rhs);
} // namespace math
} // namespace p2d
