#pragma once

#include "SFML/System/Time.hpp"

#include "math/ClampedValue.hpp"

namespace p2d { namespace math {
    template <typename T>
    class LinearInterpolation {
    public:
        LinearInterpolation(const T& t0, const T& t1);

        T getInterpolated(const float& r) const;
    private:
        T startState;
        T endState;
    }; // class LinearInterpolation

    template <typename T>
    LinearInterpolation<T>::LinearInterpolation(const T& t0, const T& t1)
    : startState(t0), endState(t1) {;}

    template <typename T>
    T LinearInterpolation<T>::getInterpolated(const float& r) const {
        return (endState - startState) * clamp<float>(r, 0.f, 1.f);
    }
}
}