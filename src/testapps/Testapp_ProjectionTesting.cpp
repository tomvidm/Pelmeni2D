#include <cstdio>

#include "Testapp_ProjectionTesting.hpp"

namespace testapps {
    ProjectionTesting::ProjectionTesting() {
        for (size_t r = 0; r < ROWS; r++) {
            for (size_t c = 0; c < COLUMNS; c++) {
                size_t index = COLUMNS*r + c;
                const p2d::math::Vector3f rowVec(0.f, 48.f, 0.f);
                const p2d::math::Vector3f colVec(48.f, 0.f, 0.f);
                meshes[index].setMeshData(vector3List, edgeList);
                meshes[index].setPosition(static_cast<float>(r)*rowVec + static_cast<float>(c)*colVec);
                meshes[index].setScale(p2d::math::Vector3f(0.75f, 0.75f, 1.f));
            }
        }

        loop();
    }

    void ProjectionTesting::loop() {
        float dt;
        float t;

        sf::Vector2i mpos;
        sf::Clock timer;
        window.create(sf::VideoMode(640, 480), "Testapp_WireMesh");
        while (window.isOpen()) {
            mpos = sf::Mouse::getPosition(window);
            float mx = static_cast<float>(mpos.x);
            float my = static_cast<float>(mpos.y);
            p2d::math::Vector3f MPOS(mx, my, 100.f);

            dt = timer.restart().asSeconds();
            t += 1.f*dt;
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();
            for (auto& x : meshes) {
                x.roll(2.f*dt);
                x.setFacing(MPOS - x.getPosition());
                x.transform();
                window.draw(x);
            }
            window.display();
        }
    }

    const p2d::graphics::Vector3List ProjectionTesting::vector3List = {
        32.f*p2d::math::Vector3f(-0.5f, -0.5, 0.f),
        32.f*p2d::math::Vector3f(0.f, 0.f, 2.f),
        32.f*p2d::math::Vector3f(0.f, 0.5f, 0.f),
        32.f*p2d::math::Vector3f(0.5f, -0.5, 0.f),
        32.f*p2d::math::Vector3f(0.f, 0.f, -0.5f)
    };

    const p2d::graphics::EdgeList ProjectionTesting::edgeList = {
        std::make_tuple(0, 1),
        std::make_tuple(0, 2),
        std::make_tuple(0, 3),
        std::make_tuple(1, 2),
        std::make_tuple(1, 3),
        std::make_tuple(2, 3),
        std::make_tuple(4, 0),
        std::make_tuple(4, 2),
        std::make_tuple(4, 3)
    };
}