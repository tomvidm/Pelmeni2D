#pragma once

#include "Frame.hpp"

namespace p2d { namespace graphics {
    class FrameSequence {
    public:
        void addFrame(const Frame& frame);
        Frame& operator [] (const unsigned& index);
    private:
        std::vector<Frame> sequence;
    }; // class Frame
} // namespace graphics
} // namespace p2d