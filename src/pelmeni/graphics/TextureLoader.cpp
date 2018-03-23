#include "TextureLoader.hpp"

namespace p2d { namespace graphics {
    using ResourceId = std::string;
    
    sf::Texture TextureLoader::loadResource(const ResourceId& id) {
        const std::string directory = "../resources/textures/";
        const std::string filename = directory + id + ".png";

        sf::Texture texture;
        texture.loadFromFile(filename);
        return texture;
    }
} // namespace graphics
} // namespace p2d