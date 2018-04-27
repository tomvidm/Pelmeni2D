#include "math/BezierCurve.hpp"

namespace p2d { namespace math {
    BezierCurve::BezierCurve(const std::vector<math::Vector2f>& controlPoints)
    : m_controlPoints(controlPoints) {
        ;
    }

    BezierCurve BezierCurve::derivative() const {
        std::vector<math::Vector2f> controlPoints = getControlPoints();
        for (size_t i = 0; i < degree(); i++) {
            controlPoints[i] = static_cast<float>(degree()) * (controlPoints[i + 1] - controlPoints[i]);
        }
        controlPoints.pop_back();
        return BezierCurve(controlPoints);
    }

    const std::vector<math::Vector2f>& BezierCurve::getControlPoints() const {
        return m_controlPoints;
    }

    math::Vector2f BezierCurve::generatePointOnCurve(float t) const {
        return bezier(m_controlPoints, degree() + 1, t);
    }

    unsigned BezierCurve::degree() const {
        return m_controlPoints.size() - 1;
    }
} // namespace math
} // namespace p2d