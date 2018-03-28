#include "ObjectManager.hpp"

namespace p2d { namespace system {
    Object::ptr ObjectManager::createFromBlueprint(const Object::id& uniqueId, const Blueprint::id& blueprintId) {
        blueprintManager.loadBlueprint(blueprintId);

        Blueprint::ptr blueprint(blueprintManager.get(blueprintId));
        Object::ptr newObject = objectLoader.createObject(uniqueId, blueprint);

        return newObject;
    };
} // namespace system
} // namespace p2d