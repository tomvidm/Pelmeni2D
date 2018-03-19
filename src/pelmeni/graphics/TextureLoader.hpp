#pragma once

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    using ResourceId = std::string;

    class TextureLoader {
    public:
        sf::Texture loadResource(const ResourceId& id);
        void releaseResource(const ResourceId& id);
    }; // class TextureLoader
} // namespace graphics
} // namespace p2d