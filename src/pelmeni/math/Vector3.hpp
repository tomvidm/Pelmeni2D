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

        Vector3 operator = (const Vector3<T>& rhs) {
            this->x = rhs.x;
            this->y = rhs.y;
            this->z = rhs.z;
            return *this;
        }

        static constexpr Vector3 UnitX = Vector3(1.f, 0.f, 0.f);
        static constexpr Vector3 UnitY = Vector3(0.f, 1.f, 0.f);
        static constexpr Vector3 UnitZ = Vector3(0.f, 0.f, 1.f);

        T x;
        T y;
        T z;
    }; // class Vector3

    template <typename T>
    Vector3<T>::Vector3() 
    : x(0), y(0), z(0) {;}

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
    Vector3<float> normalized(const Vector3<float>& vec) {
        return vec * (1.f / magnitude(vec));
    }

    // Vector arithmetic

    template <typename T>
    Vector3<T> operator + (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    template <typename T>
    void operator += (Vector3<T>& lhs, const Vector3<T>& rhs) {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
    }

    template <typename T>
    Vector3<T> operator - (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    template <typename T>
    Vector3<T> operator - (const Vector3<T>& vec) {
        return Vector3<T>(-vec.x, -vec.y, -vec.z);
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

    // Cross product
    template <typename T>
    Vector3<T> cross(const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return Vector3<T>(
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x);
    }

    // Compare operator
    template <typename T>
    T operator == (const Vector3<T>& lhs, const Vector3<T>& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
    }
}
}