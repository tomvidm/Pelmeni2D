#pragma once

#include <vector>
#include <array>

#include "math/CatmullRom.hpp"

namespace p2d { namespace math {
    template <typename T>
    class CatmullRomInterpolator {
    public:
        CatmullRomInterpolator(const std::vector<T>& controlPoints, const size_t segment);

        T getInterpolated(const float t);

        void setControlPoints(const std::vector<T>& controlPoints, const size_t segment);
    private:
        std::vector<T, 4> m_controlPoints;
    }; // class CatmullRomInterpolator

    template <typename T>
    CatmullRomInterpolator::CatmullRomInterpolator(const std::vector<T>& controlPoints, const size_t segment) {
        setControlPoints(controlPoints, segment);
    }

    template <typename T>
    CatmullRomInterpolator::setControlPoints(const std::vector<T>& controlPoints, const size_t segment) {
        m_controlPoints.resize(4);
        m_controlPoints[0] = controlPoints[segment - 1];
        m_controlPoints[0] = controlPoints[segment];
        m_controlPoints[0] = controlPoints[segment + 1];
        m_controlPoints[0] = controlPoints[segment + 2];
    }

    template <typename T>
    T getInterpolated(const float t) {
        return cubicCatmullRom(m_controlPoints, t, 0);
    }
} // namespace math
} // namespace p2