#pragma once

#include <memory>
#include <string>

#include "utility/Map.hpp"

#include "Blueprint.hpp"
#include "BlueprintManager.hpp"
#include "Object.hpp"
#include "ObjectLoader.hpp"

namespace p2d { namespace system {
    class ObjectManager {
        using ObjectContainer = utility::Map<Object::id, Object::ptr>;
    public:
        Object::ptr createFromBlueprint(const Object::id& uniqueId, const Blueprint::id& blueprintId);
    private:
        ObjectContainer objectContainer;
        
        ObjectLoader objectLoader;
        BlueprintManager blueprintManager;
    }; // class ObjectManager
} // namespace system
} // namespace p2d