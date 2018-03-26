 

#include "Package.hpp"

namespace p2d { namespace graphics {
    Package::Package() {
         ;
    }

    Package::Package(const TexturePtr texPtr, const AnimationPtrMap& animPtrMap)
    : texturePtr(texPtr), animationPtrMap(animPtrMap) {
         
    }

    FrameSequencePtr Package::getAnimation(const AnimationId& id) {
        return animationPtrMap.get(id);
    }
} // namespace graphics
} // namespace p2d