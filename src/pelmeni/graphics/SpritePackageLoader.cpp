#include <iostream>

#include "SpritePackageLoader.hpp"

namespace p2d { namespace graphics {
    std::pair<SpritePackageId, SpritePackagePtr> SpritePackageLoader::load(const SpritePackageId& id) {
        SpritePackagePtr pkg = std::make_shared<SpritePackage>();
        return std::pair<SpritePackageId, SpritePackagePtr>(id, pkg);
    } // loadResource
} // namespace graphics
} // namespace p2d