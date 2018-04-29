#pragma once

#include <vector>

#include "math/CatmullRom.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace math {
    class CatmullRomSpline {
    public:
        CatmullRomSpline();
        CatmullRomSpline(const std::vector<math::Vector2f>& controlPoints);
        CatmullRomSpline(const CatmullRomSpline& other);

        void setControlPoints(const std::vector<math::Vector2f>& controlPoints);
        const std::vector<math::Vector2f>& getControlPoints() const;

        math::Vector2f generatePointOnCurve(float t) const;
        math::Vector2f getStart() const;
        math::Vector2f getEnd() const;
    private:
        std::vector<math::Vector2f> m_controlPoints;
    }; // class CatmullRomSpline
} // namespace math
} // namespace p2d