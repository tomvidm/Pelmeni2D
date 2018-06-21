#pragma once

#include "LineSnap.hpp"

namespace p2d { namespace math {
    bool snapsToLine(const Vector2f& point, 
                     const Vector2f& p0, 
                     const Vector2f& p1, 
                     float longitudinalMargin, 
                     float widthMargin) {
        const Vector2f P = p1 - p0;
        const Vector2f V = point - p0;

        const float dotPV = dot(P, V);
        const float dotPP = dot(P, P);
        const float dotVV = dot(V, V);

        if (dotVV - (dotPV * dotPV) / dotPP < widthMargin * widthMargin) {
            const float X = dotPV / dotVV;
            if (longitudinalMargin < X && X < magnitude(P) - longitudinalMargin) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
}