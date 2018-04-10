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
}
}