#include "experimental/TilemapWIP.hpp"

namespace p2d { namespace experimental {
    void TilemapWIP::onEvent(const input::InputEvent& event) {
        
    }

    void TilemapWIP::draw(sf::RenderTarget& target, sf::RenderStates states) {
        states.transform *= toSfmlTransform(getLocalTransform());
        states.texture = &tilemapTexture.getTexture();
        target.draw(mesh, states);
    }
}
}