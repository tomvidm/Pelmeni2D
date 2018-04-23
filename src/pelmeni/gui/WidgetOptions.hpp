#pragma once

namespace p2d { namespace gui {
    struct WidgetOptions {
        bool isResizeable;
        bool isMoveable;

        static const WidgetOptions Default;
    }; // struct WidgetOptions
}
}