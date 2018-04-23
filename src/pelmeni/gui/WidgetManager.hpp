#pragma once

#include <vector>
#include <memory>

#include "gui/Widget.hpp"

namespace p2d { namespace gui {
    class WidgetManager {
    public:
        void createWidget(const WidgetType& type);
        void createWidget(const WidgetType& type, std::unique_ptr<Widget>& parent);
    private:
        std::vector<std::unique_ptr<Widget>> widgets;
    }; // class WidgetManager
}
}