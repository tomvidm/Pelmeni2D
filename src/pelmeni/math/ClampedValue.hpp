#pragma once

namespace p2d { namespace math {
    template <typename T>
    T clamp(const T& val, const T& min, const T& max) {
        return val < min ? min : (val < max ? val : max);
    } // clamp
    
    template <typename T>
    struct ClampedValue {
        T value;
    }; // class ClampedValue

    template <typename T>
    ClampedValue<T> operator + (const ClampedValue<T>& lhs, const T& rhs) {
        return ClampedValue{clamp(lhs.value + rhs)};
    } // operator +

} // namespace math
} // namespace p2d