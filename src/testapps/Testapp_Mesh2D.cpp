#include "Testapp_Mesh2D.hpp"

namespace testapps {
    ::p2d::math::Vector2f getMousePosition(sf::RenderWindow& window) {
        const sf::Vector2i mpos = sf::Mouse::getPosition(window);
        return ::p2d::math::Vector2f(
            static_cast<float>(mpos.x),
            static_cast<float>(mpos.y)
            );
    }

    int Testapp_Mesh2D() {
        using namespace p2d;
        const graphics::Mesh2D::MeshVectors mv = {
            32.f*math::Vector2f(-1.f, 0.f),
            32.f*math::Vector2f(0.f, 1.f),
            32.f*math::Vector2f(0.f, -1.f),
            32.f*math::Vector2f(3.f, 0.f)
        };
        const graphics::Mesh2D::MeshEdges me = {
            std::make_tuple(0, 1),
            std::make_tuple(1, 3),
            std::make_tuple(3, 2),
            std::make_tuple(2, 0)
        };

        graphics::Mesh2D m0(mv, me);
        physics::Body2D body;
        body.setScale(math::Vector2f(0.5f, 0.5f));
        body.setRotation(math::fromAngle(45.f));

        sf::RenderWindow window(sf::VideoMode(640, 480), "Testapp_WireMesh");
        sf::Vector2f mpos;

        float t;
        float dt;
        sf::Clock timer;
        while (window.isOpen()) {
            mpos = getMousePosition(window);
            dt = timer.restart().asSeconds();
            t += dt;
            body.applyForce((mpos - body.getPosition()) * 0.1f, dt);
            body.applyTime(dt);
            m0.transform(body.getTransform());
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            window.draw(m0);
            window.display();
        }

        return 0;
    }
}