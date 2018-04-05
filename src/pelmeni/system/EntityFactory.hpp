#pragma once

#include "system/Blueprint.hpp"
#include "system/BlueprintManager.hpp"
#include "system/EntityManager.hpp"
#include "graphics/SpritePackManager.hpp"
#include "graphics/TextureManager.hpp"

namespace p2d { namespace system {
    class EntityFactory {
    public:
        static Entity&& createEntity(
            const Blueprint::id&    blueprintId,
            BlueprintManager*       blueprintManager,
            EntityManager*          entityManager,
            SpritePackManager*      spritePackManager,
            TextureManager*         textureManager);
    }; // class EntityFactory
}
}