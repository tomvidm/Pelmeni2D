#pragma once

#include "GeometrySelection.hpp"

namespace p2d { namespace math {
    bool snapsToLine(const Vector2f& queryPoint, 
                     const Vector2f& p0, 
                     const Vector2f& p1, 
                     const float longitudinalMargin, 
                     const float widthMargin) {
        const Vector2f P = p1 - p0;
        const Vector2f V = queryPoint - p0;

        const float dotPV = dot(P, V);

        if (dotPV < 0.f) {
            return false;
        }

        const float dotPP = dot(P, P);
        const float dotVV = dot(V, V);

        if (dotVV - (dotPV * dotPV) / dotPP < widthMargin * widthMargin) {
            const float X = dotPV / sqrt(dotPP);
            if (longitudinalMargin < X && X < magnitude(P) - longitudinalMargin) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool snapsToPoint(const Vector2f& queryPoint,
                      const Vector2f& point,
                      const float threshold) {
        return magnitudeSquared(queryPoint - point) < threshold * threshold;
    }

    bool snapsToRing(const Vector2f& queryPoint,
                     const Vector2f& center,
                     const float ringRadius,
                     const float ringThreshold) {
        float innerRadius = ringRadius - ringThreshold;
        float outerRadius = ringRadius + ringThreshold;
        float distanceToCenterSquared = magnitudeSquared(queryPoint - center);
        if (distanceToCenterSquared > innerRadius * innerRadius &&
            distanceToCenterSquared < outerRadius * outerRadius) {
            return true;
        } else {
            return false;
        }
    }
}
}