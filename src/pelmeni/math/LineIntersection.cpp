#include "math/LineIntersection.hpp"

namespace p2d { namespace math {
    bool linesIntersect(const Vector2f& u0,
                        const Vector2f& u1,
                        const Vector2f& v0,
                        const Vector2f& v1) {
        Vector2f du = u1 - u0;
        Vector2f dv = v1 - v0;
        Vector2f diff = u0 - v0;

        float cross_du_diff = cross(du, diff);
        float cross_dv_diff = cross(dv, diff);
        float cross_du_dv = cross(du, dv);

        float tu = cross_du_diff / cross_du_dv;
        float tv = cross_dv_diff / cross_du_dv;

        if (0.f < tu && tu < 1.f &&
            0.f < tv && tv < 1.f) {
            return true;
        } else {
            return false;
        }
    }
}
}