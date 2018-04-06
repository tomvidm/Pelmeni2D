#include <cstdio>

#include "system/EntityFactory.hpp"

namespace p2d { namespace system {
    Entity EntityFactory::createEntity(
        const Blueprint::id&              blueprintId,
        const EntityState&                initialState,
        BlueprintManager*                 blueprintManager,
        EntityManager*                    entityManager,
        graphics::SpritePackManager*      spritePackManager) {
            printf("Creating entity from blueprint %s\n", blueprintId.c_str());
            const Blueprint blueprint = blueprintManager->get(blueprintId);
            const graphics::SpritePack::shared spritePack = spritePackManager->get(blueprint.getSpritePackAlias());
            Entity entity(spritePack, initialState);
            return entity;
        }
}
}