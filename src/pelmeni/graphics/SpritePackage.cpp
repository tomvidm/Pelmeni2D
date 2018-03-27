 

#include "SpritePackage.hpp"

namespace p2d { namespace graphics {
    SpritePackage::SpritePackage() {
         ;
    }

    SpritePackage::SpritePackage(const TexturePtr texPtr, const AnimationPtrMap& animPtrMap)
    : texturePtr(texPtr), animationPtrMap(animPtrMap) {
         
    }

    FrameSequencePtr SpritePackage::getAnimation(const AnimationId& id) {
        return animationPtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d