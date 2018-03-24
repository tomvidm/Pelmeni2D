#include "selene.h"

#include "ObjectLoader.hpp"
#include "../graphics/PackageManager.hpp"

namespace p2d { namespace system {

    std::pair<ObjectId, ObjectPtr> ObjectLoader::load(const ObjectId& id, const PresetId& presetId) {
        std::cout << "ObjectLoader::load(" << id << ", " << presetId << ")\n";
        sel::State state;
        state.Load("../resources/objects/" + presetId + ".lua");
        graphics::PackageId packageId = state["object"]["sprite_package"];

        ObjectPtr objectPtr = std::make_shared<Object>();
        objectPtr->setPackage(packageManager.loadPackage(packageId));
        return std::make_pair(id, objectPtr);
    } // load
} // namespace system
} // namespace p2d