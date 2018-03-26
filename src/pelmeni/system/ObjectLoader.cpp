#include "selene.h"

#include "ObjectLoader.hpp"
#include "../graphics/PackageManager.hpp"

namespace p2d { namespace system {

    std::pair<ObjectId, ObjectPtr> ObjectLoader::load(const ObjectId& id, const PresetId& presetId) {
         
        sel::State state;
        state.Load("../resources/presets/" + presetId + ".lua");
        graphics::PackageId packageId = state["object"]["sprite_package"];
        
        ObjectPtr objectPtr = std::make_shared<Object>();
        PackagePtr packagePtr = packageManager.loadPackage(packageId);
        objectPtr->setPackage(packagePtr);

        return std::make_pair(id, objectPtr);
    } // load
} // namespace system
} // namespace p2d