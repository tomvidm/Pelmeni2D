#include <math.h>
#include <cstdio>

#include "math/Transform3.hpp"

namespace p2d { namespace math {
    Transform3::Transform3(float m00, float m01, float m02, float m03,
                         float m10, float m11, float m12, float m13,
                         float m20, float m21, float m22, float m23,
                         float m30, float m31, float m32, float m33)
        : mat{m00, m01, m02, m03,
              m10, m11, m12, m13,
              m20, m21, m22, m23,
              m30, m31, m32, m33} {;}

    Transform3::Transform3(const Transform3& rhs) 
    : mat(rhs.mat) {;}

    Transform3::Transform3(Transform3&& rhs)
    : mat(std::move(rhs.mat)) {;}


    Transform3 Transform3::Identity() {
        return Transform3(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }
} // namespace math
} // namespace p2d
