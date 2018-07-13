#include "Viewport.hpp"

namespace p2d { namespace system {
    math::Transform Viewport::getTransform() const {
        const float captureWidth = captureRect.getWidth();
        const float captureHeight = captureRect.getHeight();

        const float viewportWidth = viewportRect.getWidth();
        const float viewportWidth = viewportRect.getHeight();

        const float xScaling = viewportWidth / captureWidth;
        const float yScaling = viewportHeight / captureHeight;

        const math::Transform scaling = math::Transform::Scale(
            xScaling, 
            yScaling
        );

        const math::Transform translation = math::Transform::Translate(
            viewportRect.origin.x - xScaling * captureRect.origin.x,
            viewportRect.origin.y - yScaling * captureRect.origin.y
        );

        return translation * scaling;
    }
}
}