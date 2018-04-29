#include "math/CatmullRomSpline.hpp"

namespace p2d { namespace math {
    CatmullRomSpline::CatmullRomSpline() {
        ;
    }

    CatmullRomSpline::CatmullRomSpline(const std::vector<math::Vector2f>& controlPoints)
    : m_controlPoints(controlPoints) {
        ;
    }

    CatmullRomSpline::CatmullRomSpline(const CatmullRomSpline& other)
    : m_controlPoints(other.getControlPoints()) {
        ;
    }

    void CatmullRomSpline::setControlPoints(const std::vector<math::Vector2f>& controlPoints) {
        m_controlPoints = controlPoints;
    }

    const std::vector<math::Vector2f>& CatmullRomSpline::getControlPoints() const {
        return m_controlPoints;
    }

    math::Vector2f CatmullRomSpline::generatePointOnCurve(float t) const {
        return cubicCatmullRom<math::Vector2f>(getControlPoints(), t, 0);
    }

    math::Vector2f CatmullRomSpline::getStart() const {
        return m_controlPoints.front();
    }

    math::Vector2f CatmullRomSpline::getEnd() const {
        return m_controlPoints.back();
    }
} // namespace math
} // namespace p2d