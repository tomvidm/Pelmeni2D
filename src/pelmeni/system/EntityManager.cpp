#include <cstdio>

#include "system/EntityManager.hpp"

namespace p2d { namespace system {
    unsigned EntityManager::entityIdCounter = 0;

    Entity::id EntityManager::createEntity() {
        printf("Created entity with id 0x%X\n", entityIdCounter);
        system::Entity newEntity(entityIdCounter);
        
        entityContainer.insert(entityIdCounter, newEntity);
        return ++entityIdCounter;
    }

    Entity::id EntityManager::createEntity(const system::Blueprint& blueprint) {
        printf("Created entity with id 0x%X\n", entityIdCounter);
        system::Entity newEntity(entityIdCounter);

        entityContainer.insert(entityIdCounter, newEntity);
        return ++entityIdCounter;
    }

    Entity::id EntityManager::createEntity(const system::Blueprint& blueprint, const Entity::alias& al) {
        printf("Created entity with id 0x%X and alias %s\n", entityIdCounter, al.c_str());
        system::Entity newEntity(entityIdCounter, al);

        entityContainer.insert(entityIdCounter, newEntity);
        entityContainer.insertAliasMapping(al, entityIdCounter);
        return ++entityIdCounter;
    }
} // namespace system
} // namespace p2d