#pragma once

#include <memory>
#include <string>

#include "Object.hpp"
#include "graphics/SpritePackageManager.hpp"
#include "graphics/Sprite.hpp"

namespace p2d { namespace system {
    using PresetId = std::string;

    class ObjectLoader {
    public:
        std::pair<ObjectId, ObjectPtr> load(const ObjectId& id, const PresetId& presetId);
    private:
        graphics::SpritePackageManager spritePackageManager;
    }; // class Object
} // namespace system
} // namespace p2d