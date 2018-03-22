#pragma once

#include "SFML/Graphics.hpp"

#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
    using ResourceId = std::string;

    class AnimationLoader {
    public:
        FrameSequence loadResource(const ResourceId& id);
    }; // class TextureLoader
} // namespace graphics
} // namespace p2d