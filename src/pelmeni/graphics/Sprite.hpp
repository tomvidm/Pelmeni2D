#pragma once

#include "SFML/Graphics.hpp"

#include "AnimationState.hpp"
#include "PackageManager.hpp"

namespace p2d { namespace graphics {
    class Sprite : public sf::Sprite {
    public:
        void update();
        //void setSpriteTexture(const ResourceId& id);
        //void setAnimation(const ResourceId& id);

        void usePackage(const PackageId& id);
    private:
        AnimationState animationState;
        PackagePtr packagePtr;

        static PackageManager packageManager;
    }; // class Sprite
} // namespace graphics
} // namespace p2d