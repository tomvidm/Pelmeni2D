#pragma once

#include <memory>
#include <string>

#include "system/Blueprint.hpp"
#include "graphics/Sprite.hpp"
#include "graphics/SpritePackage.hpp"

namespace p2d { namespace system {
    class Object {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Object>;

        Object();
        Object(graphics::SpritePackage::ptr spritePackage);

        inline Object::id getId() const { return objectId; }
        inline graphics::Sprite getSprite() const { return sprite; }

        void update();
    private:
        Object::id objectId;
        graphics::Sprite sprite;

    }; // class Object
} // namespace system
} // namespace p2d