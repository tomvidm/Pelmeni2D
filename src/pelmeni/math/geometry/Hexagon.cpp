#include "Hexagon.hpp"

namespace p2d { namespace math {
        std::array<math::Vector2f, 6> RegularHexagon::getVectors(const float cirumradius) {
            return std::array<math::Vector2f, 6>{
                math::Vector2f(-1.f, 0.f) * cirumradius,
                math::Vector2f(-0.5f, sqrtf(3.f) / 2.f) * cirumradius,
                math::Vector2f(0.5f, sqrtf(3.f) / 2.f) * cirumradius,
                math::Vector2f(1.f, 0.f) * cirumradius,
                math::Vector2f(0.5f, -sqrtf(3.f) / 2.f) * cirumradius,
                math::Vector2f(-0.5f, -sqrtf(3.f) / 2.f) * cirumradius
            };
        }
}
}