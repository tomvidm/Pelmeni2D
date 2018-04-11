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
        : value(val), min(fmin), max(fmax) {;}

        inline T get() const { return clamp<T>(value, min, max); }
    private:
        T value;
        const T min;
        const T max;
    }; // class ClampedValue
} // namespace math
} // namespace p2d