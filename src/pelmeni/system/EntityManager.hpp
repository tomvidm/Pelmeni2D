#pragma once

#include "system/Blueprint.hpp"
#include "system/Entity.hpp"
#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    class EntityManager {
    public:
        Entity::id createEntity();
        Entity::id createEntity(const system::Blueprint& blueprint);
        Entity::id createEntity(const system::Blueprint& blueprint, const Entity::alias& al);
    private:
        system::EntityContainer entityContainer;

        static unsigned entityIdCounter;
    }; // class EntityContainer
} // namespace system
} // namespace p2d