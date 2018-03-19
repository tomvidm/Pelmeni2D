#pragma once

#include "Frame.hpp"

namespace p2d { namespace graphics {
    class FrameSequence {
    public:
        Frame& operator [] (const unsigned& index);
        Frame operator [] (const unsigned& index) const;
    private:
        std::vector<Frame> sequence;
    }; // class Frame
} // namespace graphics
} // namespace p2d