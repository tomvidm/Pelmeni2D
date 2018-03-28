#pragma once

#include <string>

#include "graphics/SpritePackage.hpp"

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Blueprint>;
        Blueprint(const Blueprint::id& bpid, const graphics::SpritePackage::id& spid) 
        : blueprintId(bpid), spritePackageId(spid) {;}

        inline Blueprint::id getId() const { return blueprintId; }
        inline graphics::SpritePackage::id getSpritePackageId() const {return spritePackageId; }
    private:
        Blueprint::id blueprintId;

        graphics::SpritePackage::id spritePackageId;
    }; // class Blueprint
} // namespace system
} // namespace p2d