#pragma once

#include <memory>
#include <string>

#include "utility/Map.hpp"

#include "Blueprint.hpp"
#include "BlueprintManager.hpp"
#include "Object.hpp"
#include "graphics/SpritePackageManager.hpp"

#include "debugging/Logging.hpp"

namespace p2d { namespace system {
    class ObjectManager {
        using ObjectContainer = utility::Map<Object::id, Object::ptr>;
    public:
        Object::ptr createFromBlueprint(const Object::id& uniqueId, const Blueprint::id& blueprintId);
        Object::ptr createObject(const Object::id& uniqueId, const Blueprint::ptr blueprint);
    private:
        ObjectContainer objectContainer;
        
        BlueprintManager blueprintManager;
        graphics::SpritePackageManager spritePackageManager;
    }; // class ObjectManager
} // namespace system
} // namespace p2d