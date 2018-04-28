#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "math/Vector.hpp"
#include "math/Bezier.hpp"

namespace p2d { namespace math {

    class BezierCurve {
    public:
        BezierCurve(const std::vector<math::Vector2f>& controlPoints);

        BezierCurve derivative() const;
        
        const std::vector<math::Vector2f>& getControlPoints() const;
        math::Vector2f generatePointOnCurve(float t) const;
        unsigned degree() const;
        math::Vector2f getStart() const;
        math::Vector2f getEnd() const;
    private:
        std::vector<math::Vector2f> m_controlPoints;
    }; // class BezierCurve
} // namespace math
} // namespace p2d