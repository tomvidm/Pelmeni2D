#include "AnimationStateTest.hpp"

void AnimationStateTest::SetUp() {
    for (size_t i = 0; i < 10; i++) {
        fseq.addFrame(p2d::graphics::Frame(sf::milliseconds(16), sf::Rect<int>(sf::Vector2i(), sf::Vector2i())));
    } // add frames to fs (frameSequence)

    as.setFrameSequence(fseq);
}

TEST_F(AnimationStateTest, works) {
    EXPECT_FALSE(as.update());
    sf::sleep(sf::milliseconds(50));
    EXPECT_TRUE(as.update());
}