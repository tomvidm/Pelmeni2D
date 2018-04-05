#pragma once

#include "system/EngineDefs.hpp"

#include <string>

#include "utility/Map.hpp"
#include "graphics/Texture.hpp"
#include "graphics/FrameSequence.hpp"

namespace p2d { namespace graphics {
    class SpritePack {
    public:
        using id = std::string;
        using alias = std::string;
        using shared = std::shared_ptr<SpritePack>;

        Texture texture;
        utility::Map<FrameSequence::id, FrameSequence> frameSequenceMap;
    }; // class SpritePacka
}
}