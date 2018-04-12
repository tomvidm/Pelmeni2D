#pragma once

#include <math.h>

namespace p2d { namespace math {
    class Radian {
    public:
        Radian();
        Radian(const float& frads);

        float toAngle() const;
        float toRadians() const;
    private:
        float rads;
    }; // class Radian

    Radian fromAngle(const float& angle);
    Radian fromRadians(const float& rads);
} // namespace math
} // namespace p2d