#pragma once

#include <memory>
#include <string>

#include "graphics/SpritePackageManager.hpp"
#include "system/Blueprint.hpp"
#include "system/Object.hpp"
namespace p2d { namespace system {
    class ObjectLoader {
    public:
        Object::ptr createObject(const Object::id& uniqueId, const Blueprint::ptr blueprint);
    private:
        graphics::SpritePackageManager spritePackageManager;
    }; // class Object
} // namespace system
} // namespace p2d