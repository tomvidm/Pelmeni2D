#pragma once

#include "SFML/Graphics.hpp"

#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"

#include "graphics/Frame.hpp"
#include "graphics/FrameSequence.hpp"

#include "utility/Map.hpp"

namespace p2d { namespace graphics {
    using FrameSequenceMap = utility::Map<FrameSequence::id, FrameSequence::ptr>;
    
    class FrameSequenceLoader {
    public:
        FrameSequence::ptr generateFrameSequence(const FrameSequence::id& fSequenceId, rapidjson::Value& jsonEntry);
    }; // class AnimationLoader
} // namespace graphics
} // namespace p2d