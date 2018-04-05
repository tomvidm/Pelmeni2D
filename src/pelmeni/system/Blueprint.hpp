#pragma once

#include <memory>
#include <string>

#include "graphics/SpritePack.hpp"

namespace p2d { namespace system {
    class Blueprint {
    public:
        using id = std::string;
        using ptr = std::shared_ptr<Blueprint>;
        using file = std::string;

        Blueprint(
            const graphics::SpritePack::alias& spritePackAlias)
        : _spritePackAlias(spritePackAlias) {
            ;
        }

        inline graphics::SpritePack::alias getSpritePackAlias() const { return _spritePackAlias; }
    private:
        graphics::SpritePack::id _spritePackAlias;
    }; // class Blueprint
} // namespace system
} // namespace p2d