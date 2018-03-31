#include <cstdio>

#include "Entity.hpp"

namespace p2d { namespace system {
    Entity::Entity(const Entity::id& newId)
    : entityId(newId) {
        ;
    }

    Entity::Entity(const Entity::id& newId, const Entity::alias& newAlias)
    : entityId(newId), entityAlias(newAlias) {
        ;
    }

    Entity::Entity(const Entity& copy)
    : entityId(copy.getId()), entityAlias(copy.getAlias()) {
        ;
    }

    Entity::Entity(Entity&& other) 
    : entityId(std::move(other.entityId)), entityAlias(std::move(other.entityAlias)) {
        ;
    }

    void Entity::update() {
        ;
    }
} // namespace system
} // namespace p2d