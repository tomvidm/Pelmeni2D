#pragma once

#include "SFML/System/Time.hpp"

namespace p2d { namespace math {
    template <typename T>
    class LinearInterpolation {
    public:
        LinearInterpolation(const T& t0, const T& t1, const sf::Time& T);

        T& getInterpolated(const sf::Time& dt);
    }; // class LinearInterpolation

    template <typename T>
    LinearInterpolation::LinearInterpolation(const T& t0, const T& t1, const sf::Time& T)
    : t0(t0), t1(t1), dt(T) {;}

    T& LinearInterpolation::getInterpolated(const sf::Time& dt) {
        return (t1 - t0) * (elapsedTime/dt);
    }
}
}