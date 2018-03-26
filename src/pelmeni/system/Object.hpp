#pragma once

#include <memory>
#include <string>

#include "../graphics/Package.hpp"
#include "../graphics/Sprite.hpp"

namespace p2d { namespace system {
    using PackagePtr = std::shared_ptr<graphics::Package>;
    using AnimationId = std::string;

    class Object {
    public:
        Object();
        void setPackage(const PackagePtr pkgPtr);
        void update();

        inline graphics::Sprite& getSprite() { return sprite; }

        void setAnimation(const AnimationId& id);
    private:
        graphics::Sprite sprite;;
        graphics::PackagePtr packagePtr;
    }; // class Object

    using ObjectId = std::string;
    using ObjectPtr = std::shared_ptr<Object>;
} // namespace system
} // namespace p2d