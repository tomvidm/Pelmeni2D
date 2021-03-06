#pragma once

#include <memory>
#include <string>
#include <cstdio>

#include "SFML/Graphics.hpp"

namespace p2d { namespace graphics {
    class Texture {
    public:
        using id = std::string;
        using file = std::string;
        using shared = std::shared_ptr<Texture>;

        Texture() {
            ;
        }

        Texture(const std::string texturePath) {
            sfmlTexturePtr = std::make_shared<sf::Texture>();
            if (!sfmlTexturePtr->loadFromFile("../resources/" + texturePath)) {
                printf("Texture: Error loading file %s\n", texturePath.c_str());
            }
            sfmlTexturePtr->setSmooth(false);
        }

        Texture(Texture&& rhs) {
            sfmlTexturePtr = std::move(rhs.sfmlTexturePtr);
        }

        Texture(const Texture& rhs) {
            sfmlTexturePtr = rhs.sfmlTexturePtr;
        }

        Texture& operator = (const Texture& rhs) {
            sfmlTexturePtr = rhs.sfmlTexturePtr;
            return *this;
        }

        inline sf::Texture& getTexture() const { return *sfmlTexturePtr; }
    protected:
        std::shared_ptr<sf::Texture> sfmlTexturePtr;
    }; // class Texture
} // namespace graphics
} // namespace p2d