#pragma once

#include <math.h>

namespace p2d { namespace math {
    class Radian {
    public:
        Radian();
        Radian(const Radian& other);
        Radian(const float& frads);

        float toAngle() const;
        float toRadians() const;

        void operator += (const Radian& rhs);
    protected:
        float rads;
    }; // class Radian

    bool operator == (const Radian& lhs, const Radian& rhs);

    Radian operator + (const Radian& lhs, const Radian& rhs);
    Radian operator - (const Radian& lhs, const Radian& rhs);
    Radian operator * (const Radian& lhs, const float rhs);

    Radian fromAngle(const float& angle);
    Radian fromRadians(const float& rads);
} // namespace math
} // namespace p2d
