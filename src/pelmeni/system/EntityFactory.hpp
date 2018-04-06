#pragma once

#include "system/Blueprint.hpp"
#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"
#include "system/EntityState.hpp"
#include "graphics/SpritePackManager.hpp"

namespace p2d { namespace system {
    class EntityFactory {
    public:
        static Entity createEntity(
            const Blueprint::id&              blueprintId,
            const EntityState&                initialState,
            BlueprintManager*                 blueprintManager,
            EntityManager*                    entityManager,
            graphics::SpritePackManager*      spritePackManager);
    }; // class EntityFactory
} // namespace system
} // namespace p2d