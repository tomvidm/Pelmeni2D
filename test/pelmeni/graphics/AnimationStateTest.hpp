#include "gtest/gtest.h"

#include "graphics/Frame.hpp"
#include "graphics/FrameSequence.hpp"
#include "graphics/AnimationState.hpp"

class AnimationStateTest : public ::testing::Test {
public:
    void SetUp();

    p2d::graphics::AnimationState as;
    p2d::graphics::FrameSequencePtr fseq;
}; // class AnimationStateTest