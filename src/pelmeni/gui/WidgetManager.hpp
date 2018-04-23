#pragma once

#include <vector>
#include <memory>

#include "input/InputListener.hpp"
#include "gui/Widget.hpp"

namespace p2d { namespace gui {
    class WidgetManager 
    : public input::InputListener {
    public:
        void createWidget(const WidgetType& type);
        void createWidget(const WidgetType& type, std::unique_ptr<Widget>& parent);

        void updateWidgets();
        void drawWidgets(sf::RenderWindow& window) const;

        virtual void onEvent(const input::InputEvent& event);
    private:
        std::vector<std::unique_ptr<Widget>> widgets;
    }; // class WidgetManager
}
}