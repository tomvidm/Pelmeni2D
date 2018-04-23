#pragma once

#include "gui/WidgetStyle.hpp"

namespace p2d { namespace gui {
    const WidgetStyle WidgetStyle::Default = WidgetStyle{
        sf::Color(128, 128, 128, 128),
        sf::Color(255, 128, 128, 255),
        1.f
    };
} // namespace gui
} // namespace p2d