#include <math.h>
#include <cstdio>

#include "math/Transform.hpp"
#include "math/Transform3.hpp"

namespace p2d { namespace math {
    Transform3::Transform3(float m00, float m01, float m02, float m03,
                           float m10, float m11, float m12, float m13,
                           float m20, float m21, float m22, float m23,
                           float m30, float m31, float m32, float m33)
        : mat{m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33} {;}

    Transform3::Transform3(const Transform3& rhs) 
    : mat(rhs.mat) {;}

    Transform3::Transform3(Transform3&& rhs)
    : mat(std::move(rhs.mat)) {;}

    Vector3f Transform3::transformPoint(const float& x, const float& y, const float& z) const {
        return Vector3f(
            mat[0]*x + mat[1]*y + mat[2]*z + mat[3],
            mat[4]*x + mat[5]*y + mat[6]*z + mat[7],
            mat[8]*x + mat[9]*y + mat[10]*z + mat[11]);
    }

    Vector3f Transform3::transformVector(const Vector3f& vec) const {
        return transformPoint(vec.x, vec.y, vec.z);
    }

    float determinant(const Transform3& t) {
        return  t.mat[0] * determinant(Transform(
                    t.mat[5], t.mat[6], t.mat[7],
                    t.mat[9], t.mat[10], t.mat[11],
                    t.mat[13], t.mat[14], t.mat[15])) -
                t.mat[1] * determinant(Transform(
                    t.mat[4], t.mat[6], t.mat[7],
                    t.mat[8], t.mat[10], t.mat[11],
                    t.mat[12], t.mat[14], t.mat[15])) +
                t.mat[2] * determinant(Transform(
                    t.mat[4], t.mat[5], t.mat[7],
                    t.mat[8], t.mat[9], t.mat[11],
                    t.mat[12], t.mat[13], t.mat[15])) -
                t.mat[3] * determinant(Transform(
                    t.mat[4], t.mat[5], t.mat[6],
                    t.mat[8], t.mat[9], t.mat[10],
                    t.mat[12], t.mat[13], t.mat[14]));
    }

    Transform3 Transform3::Translation(const float& dx, const float& dy, const float& dz) {
        return Transform3(
            1, 0, 0, dx,
            0, 1, 0, dy,
            0, 0, 1, dz,
            0, 0, 0, 1);
    }

    Transform3 Transform3::Scaling(const float& sx, const float& sy, const float& sz) {
        return Transform3(
            sx, 0, 0, 0,
            0, sy, 0, 0,
            0, 0, sz, 0,
            0, 0, 0, 1);
    }

    Transform3 Transform3::RotationAboutX(const float& theta) {
        return Transform3(
            1, 0, 0, 0,
            0, cosf(theta), sinf(-theta), 0,
            0, sinf(theta), cosf(theta), 0,
            0, 0, 0, 1);
    }

    Transform3 Transform3::RotationAboutY(const float& theta) {
        return Transform3(
            cosf(theta), 0, sinf(theta), 0,
            0, 1, 0, 0,
            -sinf(theta), 0, cosf(theta), 0,
            0, 0, 0, 1);
    }

    Transform3 Transform3::RotationAboutZ(const float& theta) {
        return Transform3(
            cosf(theta), -sinf(theta), 0, 0,
            sinf(theta), cosf(theta), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }

    Transform3 Transform3::Identity() {
        return Transform3(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }
} // namespace math
} // namespace p2d
