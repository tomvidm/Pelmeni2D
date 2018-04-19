#include "experimental/TilemapWIP.hpp"

namespace p2d { namespace experimental {
    void TilemapWIP::onEvent(const input::InputEvent& event) {
        if (event.eventType == input::InputEventType::MOUSEBUTTON) {
            onMouseButtonEvent(event);
        }
    }

    void TilemapWIP::onMouseButtonEvent(const input::InputEvent& event) {
        if (event.mouseButtonEvent.eventType == input::MouseButtonEventType::CLICK) {
            const math::Vector2i mpos_pixel = sf::Mouse::getPosition(*event.window);
            const math::Vector2f mpos_screen = event.window->mapPixelToCoords(mpos_pixel);
            const graphics::TileCoordinate tile = vectorToTileCoordinate(mpos_screen);
        }
    }

    void TilemapWIP::draw(sf::RenderTarget& target, sf::RenderStates states) {
        states.transform *= toSfmlTransform(getLocalTransform());
        states.texture = &tilemapTexture.getTexture();
        target.draw(mesh, states);
    }
}
}