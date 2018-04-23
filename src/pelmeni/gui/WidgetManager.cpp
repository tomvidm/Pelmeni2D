#include <algorithm>

#include "input/Mouse.hpp"
#include "gui/WidgetManager.hpp"

namespace p2d { namespace gui {
    void WidgetManager::createWidget(const WidgetType& type) {
        switch (type) {
            case WidgetType::BaseWidget:
            default:
                std::unique_ptr<Widget> newWidget = std::unique_ptr<Widget>(new Widget());
                widgets.push_back(std::move(newWidget));
                break;
        }
    }

    void WidgetManager::createWidget(const WidgetType& type, std::unique_ptr<Widget>& parent) {
        ;
    }

    void WidgetManager::updateWidgets() {
        for (auto& widget : widgets) {
            widget->update();
        }
    }

    void WidgetManager::drawWidgets(sf::RenderWindow& window) const {
        for (auto& widget : widgets) {
            window.draw(*widget);
        }
    }

    void WidgetManager::onEvent(const input::InputEvent& event) {
        const math::Vector2f mpos = input::getMousePosition(*event.window);
        for (auto& widget : widgets) {
            if (widget->getBoundingRect().contains(mpos)) {
                widget->onEvent(event);
                break;
            }
        }
    }
}
}
