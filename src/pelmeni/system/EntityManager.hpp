#pragma once

#include "system/EngineDefs.hpp"

#include "math/Transform3.hpp"

#include "system/Blueprint.hpp"
#include "system/Entity.hpp"
#include "system/EntityContainer.hpp"
#include "system/ComponentPool.hpp"

namespace p2d { namespace system {
    class EntityManager {
    public:
        Entity::id insertEntity(const Entity& entity);
        inline std::vector<Entity>& getEntityContainer() { return entityContainer; }
        inline const std::vector<Entity>& getEntityContainer() const { return entityContainer; }
    private:
        std::vector<Entity> entityContainer;
    }; // class EntityContainer
} // namespace system
} // namespace p2d