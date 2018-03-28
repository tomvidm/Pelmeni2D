#include "ObjectLoader.hpp"
#include "graphics/SpritePackageManager.hpp"

namespace p2d { namespace system {

    Object::ptr ObjectLoader::createObject(const Object::id& uniqueId, const Blueprint::ptr blueprint) {
        graphics::SpritePackage::ptr spritePackage = spritePackageManager.getSpritePackage(blueprint->getSpritePackageId());
        return std::make_shared<Object>();
    }
} // namespace system
} // namespace p2d