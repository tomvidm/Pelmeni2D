#pragma once

#include "math/Vector.hpp"

namespace p2d { namespace math {
    template <typename T>
    struct Quaternion {
        Quaternion();
        Quaternion(
            const T& x,
            const T& y,
            const T& z,
            const T& w
        );
        Quaternion(const Vector3<T>& vec, const T& angle);

        T x;
        T y;
        T z;
        T w;
    }; // class Quaternion

    template <typename T>
    Quaternion<T>::Quaternion()
    : x(0), y(0), z(0), w(0) {
        ;
    }

    template <typename T>
    Quaternion<T>::Quaternion(const T& x,
                              const T& y,
                              const T& z,
                              const T& w)
    : x(x), y(y), z(z), w(w) {
        ;
    }

    template <typename T>
    Quaternion<T>::Quaternion(const Vector3<T>& vec, const T& angle) {
        const T halfAngle = angle/2;
        x = cosf(halfAngle), 
        y = sinf(halfAngle) * vec.x;
        z = sinf(halfAngle) * vec.y;
        w = sinf(halfAngle) * vec.z;
    }

    template <typename T>
    Quaternion<T> operator * (const Quaternion<T>& lhs, const Quaternion<T>& rhs) {
        return Quaternion<T>(lhs.x * rhs.x - lhs.y * rhs.x - lhs.z * rhs.z - lhs.w * rhs.w,
                             lhs.x * rhs.y + lhs.y * rhs.y + lhs.z * rhs.w - lhs.w * rhs.z,
                             lhs.x * rhs.z - lhs.y * rhs.w + lhs.z * rhs.x + lhs.w * rhs.y,
                             lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y + lhs.w * rhs.x);
        }
}
}