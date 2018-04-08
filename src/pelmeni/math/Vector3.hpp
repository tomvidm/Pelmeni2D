#pragma once

#include <utility>
#include <math.h>

namespace p2d { namespace math {
    template <typename T>
    struct Vector3 {
        Vector3();
        Vector3(const T& _x, const T& _y, const T& _z);
        Vector3(const Vector3& rhs);
        Vector3(Vector3&& rhs);

        T x;
        T y;
        T z;
    }; // class Vector3

    template <typename T>
    Vector3<T>::Vector3() 
    : x(0), y(0), x(0) {;}

    template <typename T>
    Vector3<T>::Vector3(const T& _x, const T& _y, const T& _z) 
    : x(_x), y(_y), z(_z) {;}

    template <typename T>
    Vector3<T>::Vector3(const Vector3& rhs)
    : x(rhs.x), y(rhs.y), z(rhs.z) {;}

    template <typename T>
    Vector3<T>::Vector3(Vector3&& rhs)
    : x(std::move(rhs.x)), y(std::move(rhs.y)), z(std::move(rhs.z)) {;}

    template <typename T>
    Vector3<T> projectToX(const Vector3<T>& vec) {
        return Vector3<T>(vec.x, 0, 0);
    } // projectToX

    template <typename T>
    Vector3<T> projectToY(const Vector3<T>& vec) {
        return Vector3<T>(0, vec.y, 0);
    } // projectToY

    template <typename T>
    Vector3<T> projectToZ(const Vector3<T>& vec) {
        return Vector3<T>(0, 0, vec.z);
    } // projectToZ

    // Scalar multiplication

    template <typename T>
    Vector3<T> operator * (const Vector3<T>& lhs, const T& rhs) {
        return Vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }

    template <typename T>
    Vector3<T> operator * (const T& lhs, const Vector3<T>& rhs) {
        return rhs * lhs;
    }

    // Magnitude and so on

    template <typename T>
    float magnitudeSquared(const Vector3<T>& vec) {
        return static_cast<float>(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    } // magnitudeSquared

    template <typename T>
    float magnitude(const Vector3<T>& vec) {
        return sqrtf(magnitudeSquared(vec));
    } // magnitude

    template <typename T>
    Vector3<float> normalize(const Vector3<float>& vec) {
        return vec * (1.f / magnitude(vec));
    }

    // Vector arithmetic

    template <typename T>
    Vector3<T> operator + (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    template <typename T>
    Vector3<T> operator - (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    // Dot product

    template <typename T>
    T dot(const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template <typename T>
    T operator * (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return dot(lhs, rhs);
    }

    // Compare operator
    template <typename T>
    T operator == (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
}
}