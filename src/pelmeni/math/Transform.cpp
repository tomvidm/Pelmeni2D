#include <math.h>
#include <cstdio>

#include "math/Transform.hpp"

namespace p2d { namespace math {
    Transform::Transform(float m00, float m01, float m02,
                         float m10, float m11, float m12,
                         float m20, float m21, float m22)
        : mat{m00, m01, m02,
              m10, m11, m12,
              m20, m21, m22} {;}

    Vector2f Transform::transformVector(const Vector2f& vec) const {
        return Vector2f(vec.x * (mat[0] + mat[1] + mat[2]), vec.y * (mat[3] + mat[4] + mat[5]));
    }

    Transform Transform::Rotation(const float& theta) {
        return Transform(
            cosf(theta), -sinf(theta), 0,
            sinf(theta), cos(theta), 0,
            0, 0, 0);
    }
    
    Transform Transform::Scale(const float& sx, const float& sy) {
        return Transform(
            sx, 0, 0,
            0, sy, 0,
            0, 0, 1);
    }

    Transform Transform::Translate(const float& dx, const float& dy) {
        return Transform(
            1, 0, dx,
            0, 1, dy,
            0, 0, 1);
    }

    Transform Transform::Translate(const Vector2f& dr) {
        return Translate(dr.x, dr.y);
    }

    Transform operator * (const Transform& lhs, const Transform& rhs) {
        return Transform(
            (rhs.mat[0] + rhs.mat[1] + rhs.mat[2]) * lhs.mat[0],
            (rhs.mat[3] + rhs.mat[4] + rhs.mat[5]) * lhs.mat[1],
            (rhs.mat[6] + rhs.mat[7] + rhs.mat[8]) * lhs.mat[2],
            (rhs.mat[0] + rhs.mat[1] + rhs.mat[2]) * lhs.mat[3],
            (rhs.mat[3] + rhs.mat[4] + rhs.mat[5]) * lhs.mat[4],
            (rhs.mat[6] + rhs.mat[7] + rhs.mat[8]) * lhs.mat[5],
            (rhs.mat[0] + rhs.mat[1] + rhs.mat[2]) * lhs.mat[6],
            (rhs.mat[3] + rhs.mat[4] + rhs.mat[5]) * lhs.mat[7],
            (rhs.mat[6] + rhs.mat[7] + rhs.mat[8]) * lhs.mat[8]);
    }

    void Transform::print() const {
        for (size_t i = 0; i < 9; i++) {
            printf("%f ", mat[i]);
            if (i % 3 == 0) {
                printf("\n");
            }
        }
    }
} // namespace math
} // namespace p2d
