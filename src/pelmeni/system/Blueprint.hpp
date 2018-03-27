#pragma once

#include <string>

#include "graphics/SpritePackage.hpp"

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        Blueprint(const Blueprint::id& bpid) 
        : blueprintId(bpid) {;}

        inline id getId() const { return blueprintId; }
    private:
        Blueprint::id blueprintId;

        //graphics::SpritePackage::id spritePackageId;
    }; // class Blueprint
} // namespace system
} // namespace p2d