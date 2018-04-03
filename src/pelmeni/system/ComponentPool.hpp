#pragma once

#include <memory>

#include "utility/Pool.hpp"

namespace p2d { namespace system {
    template <typename C, unsigned N>
    class ComponentPool {
    public:
        C::id insertComponent(C&& component);
        void removeComponent(const C::id& componentId);
    private:
        utility::Pool<C, N> componentPool;
    }; // class Node

    template <typename C, unsigned N>
    C::id ComponentPool::insertComponent(C&& component) {
        C::id componentId = componentPool.push(std::move(component));
        return componentId;
    }

    template <typename C, unsigned N>
    void ComponentPool::removeComponent(const C::id& componentId) {
        componentPool.remove(componentId);
    }
} // namespace system
} // namespace p2d