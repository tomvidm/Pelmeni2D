#pragma once

#include "math/Vector.hpp"
#include "math/Transform.hpp"
#include "../utility/Rect.hpp"

namespace p2d { namespace system {
    class Viewport {
    public:
        math::Transform getTransform() const;
    private:
        utility::Rect<float> captureRect;
        utility::Rect<float> viewportRect;
    };
}
}