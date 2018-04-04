#pragma once

#include <string>

#include "graphics/SpritePackage.hpp"

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Blueprint>;
        using file = std::string;

        inline Blueprint::id getId() const { return blueprintId; }
        inline graphics::SpritePackage::id getSpritePackageId() const {return spritePackageId; }

        inline bool hasTransform() const { return _hasTransform; }
    private:
        Blueprint::id blueprintId;

        bool _hasTransform;

        graphics::SpritePackage::id spritePackageId;
    }; // class Blueprint
} // namespace system
} // namespace p2d