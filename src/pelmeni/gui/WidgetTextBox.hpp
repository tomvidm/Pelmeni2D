#pragma once

#include <vector>
#include <memory>

#include "gui/Widget.hpp"
namespace p2d { namespace gui {
    struct TextStyle {
        unsigned int size;
    }; // struct TextStyle

    class TextBox 
    : public Widget {
    public:
        TextBox();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();
        virtual void onEvent(const input::InputEvent& event);
        virtual void onMouseMoveEvent(const input::InputEvent& event);
        virtual void onMouseButtonEvent(const input::InputEvent& event);
    private:
        TextStyle textStyle;
        std::string text;
    }; // class Widget
} // namespace gui
} // namespace p2d