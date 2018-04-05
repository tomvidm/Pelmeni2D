#pragma once

#include "utility/Map.hpp"
#include "graphics/Texture.hpp"
#include "graphics/FrameSequence.hpp"
namespace p2d { namespace graphics {
    class SpritePackage {
    public:

    private:
        Texture texture;
        utility::Map<FrameSequence::id, FrameSequence> frameSequenceMap;
    }; // class SpritePackage
}
}