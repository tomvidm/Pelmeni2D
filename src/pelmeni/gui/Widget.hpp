#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "../math/math.hpp"

namespace p2d { namespace gui {
    struct WidgetStyle {
        sf::Color color = sf::Color::White;
    }; // struct WidgetStyle

    class Widget : public sf::Drawable, public sf::Transformable {
    public:
        virtual void draw(sf::RenderTarget& target) const;
        virtual void update();
    private:
        WidgetStyle widgetStyle;

        math::Vector2f position;
        math::Vector2f size;

        Widget* parentWidget = nullptr;
        std::vector<std::unique_ptr<Widget>> widgets;

        sf::RectangleShape rectangle;
    }; // class Widget
} // namespace gui
} // namespace p2d