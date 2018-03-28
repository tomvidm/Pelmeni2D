#pragma once

#include <memory>
#include <string>

#include "system/Blueprint.hpp"
#include "graphics//SpritePackage.hpp"

namespace p2d { namespace system {
    class Object {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Object>;

        Object();
        Object(const graphics::SpritePackage::ptr spritePackagePtr);

        inline Object::id getId() const { return objectId; }
    private:
        Object::id objectId;

        graphics::SpritePackage::ptr spritePackage;

    }; // class Object
} // namespace system
} // namespace p2d