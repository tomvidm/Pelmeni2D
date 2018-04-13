#pragma once

namespace p2d { namespace math {
    template <typename T>
    T clamp(const T& val, const T& min, const T& max) {
        return val < min ? min : (val < max ? val : max);
    } // clamp
    
    template <typename T>
    class ClampedValue {
    public:
        ClampedValue(const T& val, const T& fmin, const T& fmax) 
        : value(val), min(fmin), max(fmax) {
            value = clamp<T>(value, min, max);
        }

        inline T get() const { return value; }

        ClampedValue operator + (const T& rhs) const;
        ClampedValue operator - (const T& rhs) const;
        ClampedValue operator * (const T& rhs) const;
        ClampedValue operator / (const T& rhs) const;
    private:
        T value;
        const T min;
        const T max;
    }; // class ClampedValue

    template <typename T>
    ClampedValue<T> ClampedValue<T>::operator + (const T& rhs) const {
        return ClampedValue<T>(value + rhs, min, max);
    }

    template <typename T>
    ClampedValue<T> ClampedValue<T>::operator - (const T& rhs) const {
        return ClampedValue<T>(value - rhs, min, max);
    }

    template <typename T>
    ClampedValue<T> ClampedValue<T>::operator * (const T& rhs) const {
        return ClampedValue<T>(value * rhs, min, max);
    }

    template <typename T>
    ClampedValue<T> ClampedValue<T>::operator / (const T& rhs) const {
        return ClampedValue<T>(value / rhs, min, max);
    }
} // namespace math
} // namespace p2d