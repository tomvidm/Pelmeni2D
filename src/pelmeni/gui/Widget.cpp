#include "Widget.hpp"

namespace p2d { namespace gui {
    void Widget::draw(sf::RenderTarget& target) const {
        target.draw(rectangle);
        for (auto& wgt : widgets) {
            wgt->draw(target);
        } // for
    } // draw

    void Widget::update() {
        rectangle.setPosition(position.toSfVector2f());
        rectangle.setSize(size.toSfVector2f());
    } // update
} // namespace gui
} // namespace p2d