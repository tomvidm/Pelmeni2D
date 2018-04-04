#pragma once

#include <memory>

#include "utility/Pool.hpp"

namespace p2d { namespace system {
    template <typename C, unsigned N>
    class ComponentPool {
    public:
        typename C::id insertComponent(const C& component);
        typename C::id insertComponent(C&& component);
        void removeComponent(const typename C::id& componentId);
    private:
        utility::Pool<C, N> componentPool;
    }; // class ComponentPool

    template <typename C, unsigned N>
    typename C::id ComponentPool<C, N>::insertComponent(const C& component) {
        typename C::id componentId = componentPool.push(std::move(component));
        return componentId;
    }

    template <typename C, unsigned N>
    typename C::id ComponentPool<C, N>::insertComponent(C&& component) {
        typename C::id componentId = componentPool.push(std::move(component));
        return componentId;
    }

    template <typename C, unsigned N>
    void ComponentPool<C, N>::removeComponent(const typename C::id& componentId) {
        componentPool.remove(componentId);
    }
} // namespace system
} // namespace p2d