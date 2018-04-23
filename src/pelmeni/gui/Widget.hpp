#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "input/InputListener.hpp"
#include "system/Transformable2.hpp"
#include "utility/Rect.hpp"

namespace p2d { namespace gui {
    struct WidgetStyle {
        sf::Color color = sf::Color::White;
    }; // struct WidgetStyle

    enum WidgetState {
        Idle,
        IsDragged,
        Active
    }; // enum WidgetState

    class Widget 
    : public sf::Drawable, 
      public system::Transformable2,
      public input::InputListener {
    public:
        Widget();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();
        virtual void onEvent(const input::InputEvent& event);
        virtual void onMouseMoveEvent(const input::InputEvent& event);
        virtual void onMouseButtonEvent(const input::InputEvent& event);
    private:
        bool inFocus = false;
        bool isDragged = false;
        WidgetState widgetState;
        Widget* parentWidget = nullptr;
        std::vector<std::unique_ptr<Widget>> widgets;

        sf::RectangleShape rectangle;
        utility::Rect<float> boundingRect;
    }; // class Widget
} // namespace gui
} // namespace p2d