#include "math/BezierCurve.hpp"

namespace p2d { namespace math {
    BezierCurve::BezierCurve() {
        ;
    }

    BezierCurve::BezierCurve(const std::vector<math::Vector2f>& controlPoints)
    : m_controlPoints(controlPoints) {
        ;
    }

    BezierCurve::BezierCurve(const BezierCurve& other)
    : m_controlPoints(other.getControlPoints()) {
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
        if (m_controlPoints.empty()) {
            return math::Vector2f();
        } else {
            return bezier(m_controlPoints, degree() + 1, t);
        }
    }

    unsigned BezierCurve::degree() const {
        return m_controlPoints.size() - 1;
    }

    math::Vector2f BezierCurve::getStart() const {
        return m_controlPoints.front();
    }

    math::Vector2f BezierCurve::getEnd() const {
        return m_controlPoints.back();
    }

    void BezierCurve::setControlPoints(const std::vector<math::Vector2f>& controlPoints) {
        m_controlPoints = controlPoints;
    }
} // namespace math
} // namespace p2d