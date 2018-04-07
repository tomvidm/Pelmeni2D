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

    Transform::Transform(const Transform& rhs) 
    : mat(rhs.mat) {;}

    Transform::Transform(Transform&& rhs)
    : mat(std::move(rhs.mat)) {;}

    Vector2f Transform::transformVector(const Vector2f& vec) const {
        return Vector2f(vec.x * (mat[0] + mat[1] + mat[2]), vec.y * (mat[3] + mat[4] + mat[5]));
    }

    Vector2f Transform::transformPoint(const float& x, const float& y) const {
        return Vector2f(x * (mat[0] + mat[1] + mat[2]), y * (mat[3] + mat[4] + mat[5]));
    }

    Transform Transform::Rotation(const float& theta) {
        return Transform(
            cosf(theta), -sinf(theta), 0,
            sinf(theta), cos(theta), 0,
            0, 0, 1);
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

    Transform Transform::Identity() {
        return Transform(
            1, 0, 0,
            0, 1, 0,
            0, 0, 1);
    }

    float Transform::determinant() const {
        return mat[0]*(mat[4]*mat[8] - mat[5]*mat[7]) -
               mat[1]*(mat[3]*mat[8] + mat[5]*mat[6]) +
               mat[2]*(mat[3]*mat[7] - mat[4]*mat[6]);
    }

    Transform Transform::inverse() const {
        return determinant() * Transform(
            mat[4]*mat[8] - mat[5]*mat[7],
            mat[2]*mat[7] - mat[1]*mat[8],
            mat[1]*mat[5] - mat[2]*mat[4],
            mat[5]*mat[6] - mat[3]*mat[8],
            mat[0]*mat[8] - mat[2]*mat[6],
            mat[2]*mat[3] - mat[0]*mat[5],
            mat[3]*mat[7] - mat[4]*mat[6],
            mat[1]*mat[6] - mat[0]*mat[7],
            mat[0]*mat[4] - mat[1]*mat[3]);
    }

    Transform operator * (const Transform& lhs, const float& rhs) {
        Transform temp(lhs);
        for (auto& x : temp.mat) {
            x *= rhs;
        }
        return temp;
    }

    Transform operator * (const float& lhs, const Transform& rhs) {
        return rhs * lhs;
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

    Vector2f operator * (const Transform& lhs, const Vector2f& rhs) {
        return lhs.transformVector(rhs);
    }

    std::string toString(const Transform& rhs) {
        return std::to_string(rhs.mat[0]) + ", " + std::to_string(rhs.mat[1]) + ", " + std::to_string(rhs.mat[2]) + "\n" +
               std::to_string(rhs.mat[3]) + ", " + std::to_string(rhs.mat[4]) + ", " + std::to_string(rhs.mat[5]) + "\n" +
               std::to_string(rhs.mat[6]) + ", " + std::to_string(rhs.mat[7]) + ", " + std::to_string(rhs.mat[8]) + "\n";
    }
} // namespace math
} // namespace p2d
