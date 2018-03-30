#include "ObjectManager.hpp"

namespace p2d { namespace system {
    Object::ptr ObjectManager::createFromBlueprint(const Object::id& uniqueId, const Blueprint::id& blueprintId) {
        blueprintManager.loadBlueprint(blueprintId);

        Blueprint::ptr blueprint(blueprintManager.get(blueprintId));
        Object::ptr newObject = createObject(uniqueId, blueprint);

        return newObject;
    };

    Object::ptr ObjectManager::createObject(const Object::id& uniqueId, const Blueprint::ptr blueprint) {
        graphics::SpritePackage::ptr spritePackage = spritePackageManager.getSpritePackage(blueprint->getSpritePackageId());
        return std::make_shared<Object>(spritePackage);
    }
} // namespace system
} // namespace p2d