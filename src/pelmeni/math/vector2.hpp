#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <math.h>

#include "SFML/System/Vector2.hpp"

namespace p2d { namespace math {
    template <typename T>
    class Vector2 {
    public:
        Vector2();
        Vector2(const T& x, const T& y);

        Vector2(const Vector2<T>& other);

        void operator += (const Vector2<T>& rhs);
        void operator *= (const T& rhs);

        Vector2 operator + (const Vector2<T>& rhs) const;
        Vector2 operator - (const Vector2<T>& rhs) const;
        Vector2 operator * (const T& rhs) const;

        float getMagnitudeSquared() const;
        float getMagnitude() const;

        T dot(const Vector2<T>& other) const;

        Vector2<int> getIntified() const;
        Vector2<float> getFloatified() const;
        Vector2<float> getNormalized() const;

        sf::Vector2f toSfVector2f() const;

        inline T getX() const { return x; }
        inline T getY() const { return y; }
        inline T& getX() { return x; }
        inline T& getY() { return y; }
        inline Vector2<T> getVectorX() const { return Vector2<T>(x, T(0)); }
        inline Vector2<T> getVectorY() const { return Vector2<T>(T(0), y); }

        T x, y;
    }; // Vector2

    template <typename T>
    Vector2<T>::Vector2() 
    : x(0), y(0) {
        ;
    } // constructor

    template <typename T>
    Vector2<T>::Vector2(const T& x, const T& y) 
    : x(x), y(y) {
        ;
    } // constructor

    template <typename T>
    Vector2<T>::Vector2(const Vector2<T>& other) 
    : x(other.y), y(other.y) {
        ;
    } // copy constructor

    template <typename T>
    void Vector2<T>::operator += (const Vector2<T>& rhs) {
        x += rhs.x;
        y += rhs.y;
    } // operatpr +=

    template <typename T>
    void Vector2<T>::operator *= (const T& rhs) {
        x *= rhs;
        y *= rhs;
    } // operator *=

    template <typename T>
    Vector2<T> Vector2<T>::operator + (const Vector2<T>& rhs) const {
        return Vector2<T>(
            x + rhs.x,
            y + rhs.y
        );
    } // operator +

    template <typename T>
    Vector2<T> Vector2<T>::operator - (const Vector2<T>& rhs) const {
        return Vector2<T>(
            x - rhs.x,
            y - rhs.y
        );
    } // operator -

    template <typename T>
    Vector2<T> Vector2<T>::operator * (const T& rhs) const {
        return Vector2<T>(
            x * rhs,
            y * rhs
        );
    } // operator *

    template <typename T>
    float Vector2<T>::getMagnitudeSquared() const {
        return static_cast<float>((x * x) + (y * y));
    } // getMagnitudeSquared

    template <typename T>
    float Vector2<T>::getMagnitude() const {
        return sqrtf(getMagnitudeSquared());
    } // getMagnitudeSquared

    template <typename T>
    T Vector2<T>::dot(const Vector2<T>& other) const {
        return (x * other.x) + (y * other.y);
    } // dot

    template <typename T>
    Vector2<int> Vector2<T>::getIntified() const {
        return Vector2<int>(static_cast<int>(x),
                              static_cast<int>(y));
    } // getFloatified

    template <typename T>
    Vector2<float> Vector2<T>::getFloatified() const {
        return Vector2<float>(static_cast<float>(x),
                              static_cast<float>(y));
    } // getFloatified

    template <typename T>
    Vector2<float> Vector2<T>::getNormalized() const {
        return Vector2<float>(getFloatified() * (1.f / getMagnitude()));
    } // getNormalized

    template <typename T>
    sf::Vector2f Vector2<T>::toSfVector2f() const {
        return sf::Vector2f(x, y);
    } // toSfVector2f
} // namespace math
} // namespace p2d

#endif