#include "system/Transformable3.hpp"

namespace p2d { namespace system {
    math::Transform3 Transformable3::getTransform3() const {
        return math::Transform3::Translation(getPosition()) *
               math::Transform3::RotationAboutX(rotationX) * 
               math::Transform3::RotationAboutZ(rotationZ) *
               math::Transform3::RotationAboutY(rotationY);

               
               
    }

    void Transformable3::transform(const math::Transform3& transform) {
        ;
    }

    void Transformable3::setRotation(const float& x, const float& y, const float& z) {
        rotationX = x;
        rotationY = y;
        rotationZ = z;
    }
}
}