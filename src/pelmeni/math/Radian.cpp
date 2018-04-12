#include "math/Radian.hpp"

namespace p2d { namespace math {
    Radian::Radian()
    : rads(0) {;}

    Radian::Radian(const float& frads)
    : rads(frads) {;}

    float Radian::toAngle() const {
        return 180.f * rads / static_cast<float>(M_PI);
    }

    float Radian::toRadians() const {
        return rads;
    }

    Radian fromAngle(const float& angle) {
        return Radian(static_cast<float>(M_PI) * angle / 180.f);
    }

    Radian fromRadians(const float& rads) {
        return Radian(rads);
    }
}
}