#include "SpritePackageManager.hpp"

namespace p2d { namespace graphics {
    SpritePackagePtr SpritePackageManager::getSpritePackage(const SpritePackageId& id) {
         
        if (!spritePackagePtrMap.contains(id)) {
            return loadSpritePackage(id);
        } else {
            return spritePackagePtrMap.get(id);
        } // if else
    } // loadPackage

    SpritePackagePtr SpritePackageManager::loadSpritePackage(const SpritePackageId& id) {
         
        std::pair<SpritePackageId, SpritePackagePtr> keyValuePair = spritePackageLoader.load(id);
        spritePackagePtrMap.insert(keyValuePair);
        return spritePackagePtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d