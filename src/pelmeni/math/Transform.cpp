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

    void Transform::transformVertexArray(const sf::VertexArray& varr) const {
        for (size_t i = 0; i < varr.size(); i++) {
            transformVector(varr[i]);
        }
    }

    Vector2f Transform::transformPoint(const float& x, const float& y) const {
        return Vector2f(mat[0]*x + mat[1]*y + mat[2],
                        mat[3]*x + mat[4]*y + mat[5]);
    }

    Vector3f Transform::transformPoint(const float& x, const float& y, const float& z) const {
        return Vector3f(mat[0]*x + mat[1]*y + mat[2]*z,
                        mat[3]*x + mat[4]*y + mat[5]*z,
                        mat[6]*x + mat[7]*y + mat[8]*z);
    }

    Vector2f Transform::transformVector(const Vector2f& vec) const {
        return Vector2f(transformPoint(vec.x, vec.y));
    }

    Vector3f Transform::transformVector(const Vector3f& vec) const {
        return Vector3f(transformPoint(vec.x, vec.y, vec.z));
    }

    Transform Transform::operator = (const Transform& rhs) {
        mat = rhs.mat;
        return *this;
    }

    Transform Transform::Rotation(const float& theta) {
        const float sine = sinf(theta);
        const float cosine = cosf(theta);
        return Transform(
            cosine, -sine, 0,
            sine, cosine, 0,
            0, 0, 1);
    }
    
    Transform Transform::Scale(const Vector2f& vec) {
        return Scale(vec.x, vec.y);
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

    float determinant(const Transform& t) {
        return t.mat[0]*(t.mat[4]*t.mat[8] - t.mat[5]*t.mat[7]) -
               t.mat[1]*(t.mat[3]*t.mat[8] + t.mat[5]*t.mat[6]) +
               t.mat[2]*(t.mat[3]*t.mat[7] - t.mat[4]*t.mat[6]);
    }

    Transform composition(const Transform& lhs, const Transform& rhs) {
        Vector3f c0(rhs.mat[0], rhs.mat[3], rhs.mat[6]);
        Vector3f c1(rhs.mat[1], rhs.mat[4], rhs.mat[7]);
        Vector3f c2(rhs.mat[2], rhs.mat[5], rhs.mat[8]);
        c0 = lhs.transformVector(c0);
        c1 = lhs.transformVector(c1);
        c2 = lhs.transformVector(c2);
        return Transform(
            c0.x, c1.x, c2.x,
            c0.y, c1.y, c2.y,
            c0.z, c1.z, c2.z);
    }

    Transform inverse(const Transform& t) {
        return determinant(t) * Transform(
            t.mat[4]*t.mat[8] - t.mat[5]*t.mat[7],
            t.mat[2]*t.mat[7] - t.mat[1]*t.mat[8],
            t.mat[1]*t.mat[5] - t.mat[2]*t.mat[4],
            t.mat[5]*t.mat[6] - t.mat[3]*t.mat[8],
            t.mat[0]*t.mat[8] - t.mat[2]*t.mat[6],
            t.mat[2]*t.mat[3] - t.mat[0]*t.mat[5],
            t.mat[3]*t.mat[7] - t.mat[4]*t.mat[6],
            t.mat[1]*t.mat[6] - t.mat[0]*t.mat[7],
            t.mat[0]*t.mat[4] - t.mat[1]*t.mat[3]);
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
        return composition(lhs, rhs);
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
