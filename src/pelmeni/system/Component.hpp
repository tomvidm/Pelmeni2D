#pragma once

#include <memory>

namespace p2d { namespace system {
    class Component {
    public:
        using id = unsigned;

        enum type {
            Generic,
            Transform,
            Texture,
            Animation
        };

        virtual void update() = 0;

    private:
        Component::id compId;
        Component::type compType;
    }; // class Node
} // namespace system
} // namespace p2d