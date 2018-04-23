#pragma once

#include <vector>
#include <memory>

#include "SFML/Graphics.hpp"

#include "input/InputListener.hpp"
#include "system/Transformable2.hpp"
#include "utility/Rect.hpp"
#include "gui/WidgetStyle.hpp"
#include "gui/WidgetOptions.hpp"
namespace p2d { namespace gui {
    enum class WidgetType {
        BaseWidget
    };

    class Widget 
    : public sf::Drawable, 
      public system::Transformable2,
      public input::InputListener {
    public:
        Widget();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();
        virtual void onEvent(const input::InputEvent& event);
    private:
        virtual void onMouseMoveEvent(const input::InputEvent& event);
        virtual void onMouseButtonEvent(const input::InputEvent& event);

        bool inFocus = false;
        bool isDragged = false;

        WidgetStyle style;
        WidgetOptions options;

        Widget* parentWidget = nullptr;
        std::vector<std::unique_ptr<Widget>> widgets;

        sf::RectangleShape rectangle;
        utility::Rect<float> boundingRect;

        math::Vector2f initialDragPosition;
    }; // class Widget
} // namespace gui
} // namespace p2d