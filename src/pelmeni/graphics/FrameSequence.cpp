#include "FrameSequence.hpp"

namespace p2d { namespace graphics {
        Frame& FrameSequence::operator [] (const unsigned& index) {
            return sequence.at(index);
        }
} // namespace graphics
} // namespace p2d