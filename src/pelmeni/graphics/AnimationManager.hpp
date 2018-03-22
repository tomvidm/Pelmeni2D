#pragma once

#include "SFML/Graphics.hpp"

#include "AnimationLoader.hpp"
#include "FrameSequence.hpp"
#include "../utility/ResourceManager.hpp"

namespace p2d { namespace graphics {
    using AnimationManager = utility::ResourceManager<FrameSequence, AnimationLoader>;
} // namespace graphics
} // namespace p2d