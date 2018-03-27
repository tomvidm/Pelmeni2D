#include "ObjectLoader.hpp"
#include "graphics/SpritePackageManager.hpp"

namespace p2d { namespace system {

    std::pair<ObjectId, ObjectPtr> ObjectLoader::load(const ObjectId& id, const PresetId& presetId) {
        ObjectPtr objectPtr = std::make_shared<Object>();
        return std::make_pair(id, objectPtr);
    } // load
} // namespace system
} // namespace p2d