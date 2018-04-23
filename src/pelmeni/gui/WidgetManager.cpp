#include "gui/WidgetManager.hpp"

namespace p2d { namespace gui {
    void WidgetManager::createWidget(const WidgetType& type) {
        createWidget(type, nullptr);
    }

    void createWidget(const WidgetType& type, std::unique_ptr<Widget>& parent) {
        switch (type) {
            case WidgetType::BaseWidget:
            default:
                std::unique_ptr<Widget> newWidget = std::unique_ptr<Widget>(new Widget());
                break;
        }
    }
}
}
