#pragma once

#include <memory>
#include <string>

#include "../graphics/Package.hpp"
#include "../graphics/Sprite.hpp"

namespace p2d { namespace system {
    using PackagePtr = std::shared_ptr<graphics::Package>;

    class Object {
    public:
        Object();
        void setPackage(const PackagePtr pkgPtr);

        inline graphics::Sprite& getSprite() { return sprite; }
    private:
        graphics::Sprite sprite;;
        graphics::PackagePtr packagePtr;
    }; // class Object

    using ObjectId = std::string;
    using ObjectPtr = std::shared_ptr<Object>;
} // namespace system
} // namespace p2d