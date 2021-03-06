#pragma once

#include <limits>

#include "math/math.hpp"

#include "SFML/Graphics/Rect.hpp"

namespace p2d { namespace utility {
    using p2d::math::Vector2;

    template <typename T>
    class Rect {
    public:
        Rect();
        Rect(const std::vector<Vector2<T>>& vectorArray);
        Rect(const Vector2<T>& pos, const Vector2<T>& siz);
        Rect(const float& x, const float& y, 
             const float& w, const float& h);

        bool contains(const Vector2<T>& point) const;

        void resize(const float& factor);
        void operator += (const Vector2<T>& rhs);
        void operator *= (const float& factor);

        inline T getWidth() const { return size.x; }
        inline T getHeight() const { return size.y; }
        inline Vector2<T> getSize() const { return size; }
        inline Vector2<T> getCenter() const { return origin + size * 0.5f; }

        Rect<T> operator + (const Vector2<T>& rhs) const;
        Rect<T> operator * (const float& factor) const;

        Vector2<T> origin;
        Vector2<T> size;
    }; // Rect

    template <typename T>
    Rect<T>::Rect(const std::vector<Vector2<T>>& vectorArray) {
        float min_x = std::numeric_limits<T>::max();
        float max_x = std::numeric_limits<T>::lowest();;
        float min_y = std::numeric_limits<T>::max();;
        float max_y = std::numeric_limits<T>::lowest();;
        for (auto& v : vectorArray) {
            if (v.x < min_x) min_x = v.x;
            if (v.x > max_x) max_x = v.x;
            if (v.y < min_y) min_y = v.y;
            if (v.y > max_y) max_y = v.y;
        }
    }

    template <typename T>
    Rect<T>::Rect(const Vector2<T>& pos, const Vector2<T>& siz) 
    : origin(pos), size(siz) {
        ;
    } // constructor

    template <typename T>
    Rect<T>::Rect(const float& x, const float& y, 
             const float& w, const float& h)
    : origin(Vector2<float>(x, y)),
      size(Vector2<float>(w, h)) {
        ;
    } // constructor

    template <typename T>
    Rect<T>::Rect()
    : origin(Vector2<T>()), size(Vector2<T>()) {
        ;
    } // constructor

    template <typename T>
    bool Rect<T>::contains(const Vector2<T>& point) const {
        return !((point.x <= origin.x) ||
                 (point.y <= origin.y) ||
                 (point.x > origin.x + size.x) ||
                 (point.y > origin.y + size.y));
    } // contains

    template <typename T>
    void Rect<T>::resize(const float& factor) {
        size *= factor;
    } // resize

    template <typename T>
    void Rect<T>::operator += (const Vector2<T>& rhs) {
        origin += rhs;
    } // resize

    template <typename T>
    void Rect<T>::operator *= (const float& factor) {
        size *= factor;
    } // operator *

    template <typename T>
    Rect<T> Rect<T>::operator + (const Vector2<T>& rhs) const {
        Rect<T> copy = *this;
        copy += rhs;
        return copy;
    } // resize

    template <typename T>
    Rect<T> Rect<T>::operator * (const float& factor) const {
        Rect<T> copy = *this;
        copy *= factor;
        return copy;
    } // operator *
} // namespace utility
} // namespace p2d