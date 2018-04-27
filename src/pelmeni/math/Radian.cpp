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

    Radian operator * (const Radian& lhs, const float rhs) {
        return fromRadians(lhs.toRadians() * fromAngle(rhs).toRadians());
    }

    Radian fromAngle(const float& angle) {
        return Radian(static_cast<float>(M_PI) * angle / 180.f);
    }

    Radian fromRadians(const float& rads) {
        return Radian(rads);
    }

    void Radian::operator += (const Radian& rhs) {
        rads += rhs.toRadians();
    }
}
}