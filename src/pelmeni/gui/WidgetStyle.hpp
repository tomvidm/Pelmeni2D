#pragma once

#include "SFML/Graphics.hpp"

namespace p2d { namespace gui {
    struct WidgetStyle {
        sf::Color   fillColor;
        sf::Color   outlineColor;
        float       outlineThickness;

        static const WidgetStyle Default;
    }; // struct WidgetStyle
} // namespace gui
} // namespace p2d