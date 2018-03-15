#pragma once

#include <memory>

#include "SFML/Graphics.hpp"

namespace p2d { namespace system {
    class State {
    public:
        State();
        virtual void update();
    }; // class State
} // namespace system
} // namespace p2d