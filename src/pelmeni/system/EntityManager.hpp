#pragma once

#include "system/Blueprint.hpp"
#include "system/Entity.hpp"
#include "system/EntityContainer.hpp"

namespace p2d { namespace system {
    class EntityManager {
    public:
        Entity::id createEntity();
    private:
        system::EntityContainer entityContainer;
    }; // class EntityContainer
} // namespace system
} // namespace p2d