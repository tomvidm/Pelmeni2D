#pragma once

#include <memory>
#include <string>

#include "../graphics/SpritePackage.hpp"
#include "../graphics/Sprite.hpp"

namespace p2d { namespace system {
    using SpritePackagePtr = std::shared_ptr<graphics::SpritePackage>;
    using AnimationId = std::string;

    class Object {
    public:
        Object();
        void setSpritePackage(const SpritePackagePtr pkgPtr);
        void update();

        inline graphics::Sprite& getSprite() { return sprite; }

        void setAnimation(const AnimationId& id);
    private:
        graphics::Sprite sprite;;
        graphics::SpritePackagePtr spritePackagePtr;
    }; // class Object

    using ObjectId = std::string;
    using ObjectPtr = std::shared_ptr<Object>;
} // namespace system
} // namespace p2d