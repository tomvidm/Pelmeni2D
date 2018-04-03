#pragma once

#include <memory>

namespace p2d { namespace system {
    class Component {
    public:
        using id = unsigned;

        enum type {
            none,
            transform,
            sprite
        };

        Component() : compType(type::none) {;}
        Component(const Component::type& cType)  : compType(cType) {;}

        virtual void update() = 0;

    protected:
        const Component::type compType;
    }; // class Node
} // namespace system
} // namespace p2d