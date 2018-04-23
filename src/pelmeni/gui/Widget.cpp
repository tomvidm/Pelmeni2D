#include "Widget.hpp"

namespace p2d { namespace gui {
    Widget::Widget() 
    : style(WidgetStyle::Default),
      options(WidgetOptions::Default) {
        rectangle.setFillColor(style.fillColor);
        rectangle.setSize(math::Vector2f(300.f, 200.f));
    }

    void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= math::toSfmlTransform(getLocalTransform());
        target.draw(rectangle, states);
        for (auto& wgt : widgets) {
            wgt->draw(target, states);
        } // for
    } // draw

    void Widget::update() {
        boundingRect.origin = getPosition();
        boundingRect.size = rectangle.getSize();
    }

    void Widget::onEvent(const input::InputEvent& event) {
        if (event.eventType == input::InputEventType::MOUSEBUTTON) {
            onMouseButtonEvent(event);
        }
        if (event.eventType == input::InputEventType::MOUSEMOVE) {
            onMouseMoveEvent(event);
        }
        for (auto& child : widgets) {
            child->onEvent(event);
        }
    }

    void Widget::onMouseMoveEvent(const input::InputEvent& event) {
        math::Vector2f mousePos = input::getMousePosition(*event.window);
        if (options.isMoveable && isDragged) {
            setPosition(mousePos - initialDragPosition);
        }
        if (boundingRect.contains(mousePos)) {
            inFocus = true;
        } else {
            inFocus = false;
        }
    }

    void Widget::onMouseButtonEvent(const input::InputEvent& event) {
        if (event.mouseButtonEvent.eventType == input::MouseButtonEventType::PRESS) {
            if (event.mouseButtonEvent.button == input::MouseButton::LEFT) {
                const sf::Vector2f mousePosition = input::getMousePosition(*event.window);
                if (boundingRect.contains(mousePosition)) {
                    initialDragPosition = mousePosition - getPosition();
                    isDragged = true;
                }
            }
        } else if (event.mouseButtonEvent.eventType == input::MouseButtonEventType::RELEASE) {
            if (event.mouseButtonEvent.button == input::MouseButton::LEFT) {
                isDragged = false;
            }
        }
    }

} // namespace gui
} // namespace p2d