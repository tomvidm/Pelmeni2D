#pragma once

#include <vector>
#include <array>

#include "math/CatmullRom.hpp"

namespace p2d { namespace math {
    template <typename T>
    class CatmullRomInterpolator {
    public:
        CatmullRomInterpolator();
        CatmullRomInterpolator(const std::vector<T>& controlPoints, const size_t segment);

        T getInterpolated(const float t);

        void setControlPoints(const std::vector<T>& controlPoints, const size_t segment);
    private:
        std::vector<T> m_controlPoints;
    }; // class CatmullRomInterpolator

    template <typename T>
    CatmullRomInterpolator<T>::CatmullRomInterpolator() {
        m_controlPoints.resize(4);
    }

    template <typename T>
    CatmullRomInterpolator<T>::CatmullRomInterpolator(const std::vector<T>& controlPoints, const size_t segment) {
        m_controlPoints.resize(4);
        setControlPoints(controlPoints, segment);
    }

    template <typename T>
    void CatmullRomInterpolator<T>::setControlPoints(const std::vector<T>& controlPoints, const size_t segment) {
        if (segment == 0) {
            m_controlPoints[0] = controlPoints[segment];
        } else {
            m_controlPoints[0] = controlPoints[segment - 1];
        }

        m_controlPoints[1] = controlPoints[segment];
        m_controlPoints[2] = controlPoints[segment + 1];

        if (segment == controlPoints.size() - 3) {
            m_controlPoints[3] = controlPoints[segment + 1];
        } else {
            m_controlPoints[3] = controlPoints[segment + 2];
        }
    }

    template <typename T>
    T CatmullRomInterpolator<T>::getInterpolated(const float t) {
        return cubicCatmullRom(m_controlPoints, t, 1);
    }
} // namespace math
} // namespace p2