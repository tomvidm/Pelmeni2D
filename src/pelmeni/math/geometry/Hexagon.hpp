#pragma once

#include <math.h>
#include <array>

#include "math/Vector.hpp"
#include "math/Radian.hpp"

namespace p2d { namespace math {
    class RegularHexagon {
    public:
        RegularHexagon(const float circumradius) : m_circumradius(circumradius) { ; }

        inline float getInradius() const { return sqrtf(3.f) * m_circumradius / 2.f; }
        inline float getCircumradius() const { return m_circumradius; }
        inline float getCircumference() const { return 6.f * m_circumradius; }

        static std::array<math::Vector2f, 6> getVectors(const float m_cirumradius);
    private:
        float m_circumradius;
    };
}
}