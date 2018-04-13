#include "physics/Physics.hpp"

namespace p2d { namespace physics {
    Force2 getDrag(const math::Vector2f& velocity, const float& dragConstant) {
        return -velocity * math::magnitude(velocity) * dragConstant;
    }
}
}