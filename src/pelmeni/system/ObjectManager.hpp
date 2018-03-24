#pragma once

#include <memory>
#include <string>

#include "Object.hpp"
#include "ObjectLoader.hpp"
#include "../graphics/Sprite.hpp"
#include "../utility/Map.hpp"

namespace p2d { namespace system {
    using ObjectPtr = std::shared_ptr<Object>;
    using ObjectPtrMap = utility::Map<ObjectId, ObjectPtr>;
    using PresetId = std::string;

    class ObjectManager {
    public:
        ObjectPtr getObject(const ObjectId& id);
        void loadObject(const ObjectId& id, const PresetId& presetId);
    private:
        ObjectPtrMap objectPtrMap;
        ObjectLoader objectLoader;
    }; // class Object
} // namespace system
} // namespace p2d