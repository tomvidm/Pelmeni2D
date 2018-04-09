#pragma once

#include <utility>
#include <math.h>

namespace p2d { namespace math {
    template <typename T>
    struct Vector4 {
        Vector4();
        Vector4(const T& _x, const T& _y, const T& _z, const T& _w);
        Vector4(const Vector3& rhs);

        Vector4 operator = (const Vector3<T>& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            this->z = rhs.z;
            this->w = rhs.w;
            return *this;
        }

        T x;
        T y;
        T z;
        T w;
    }; // class Vector4

    template <typename T>
    Vector4<T>::Vector4()
    : x(0), y(0), z(0), w(0) {;}

    template <typename T>
    Vector4<T>::Vector4(const T& _x, const T& _y, const T& _z, const T& _w)
    : x(_x), y(_y), z(_z), w(_w) {;}

    template <typename T>
    Vector4::Vector4(const Vector3& rhs) :
    x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {;}
}
}