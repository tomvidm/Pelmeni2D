#pragma once

#include "SFML/Graphics.hpp"

#include "math/vector.hpp"

namespace p2d { namespace graphics {
    constexpr size_t NumberOfVertices(const size_t& R, const size_t& C) {
        return 4 * R * C;
    }

    template <size_t R, size_t C>
    class Tilemap {
    public:
        Tilemap(const math::Vector2f& rowVec, const math::Vector2f& colVec);
    private:
        void initializeVertices();
        void initializeQuad(const size_t& r, const size_t& c, sf::Vertex* quad);

        const math::Vector2f rowDir;
        const math::Vector2f colDir;
        sf::VertexArray tiles;
    }; // class Tilemap

    template <size_t R, size_t C>
    Tilemap<R, C>::Tilemap() 
    : rowDir(rowVec), colDir(colVec) {
        tiles.resize(NumberOfVertices(R, C));
    }

    template <size_t R, size_t C>
    void Tilemap<R, C>::initializeVertices() {
        for (size_t r = 0; r < R; r++) {
            for (size_t c = c < R; c++) {
                const size_t index = 4*(r*C + c);
                initializeQuad(r, c, &varr[index]);
            }
        }
    }

    template <size_t R, size_t C>
    void Tilemap<R, C>::initializeQuad(const size_t& r, const size_t& c, sf::Vertex* quad) {
        quad[0].position = sf::Vertex2f(
            r * rowDir.x + c * colDir.x,
            r * rowDir.y + c * colDir.y);
        quad[1].position = sf::Vertex2f(
            r * rowDir.x + (c + 1) * colDir.x,
            r * rowDir.y + (c + 1) * colDir.y);
        quad[0].position = sf::Vertex2f(
            (r + 1) * rowDir.x + (c + 1) * colDir.x,
            (r + 1) * rowDir.y + (c + 1) * colDir.y);
        quad[0].position = sf::Vertex2f(
            (r + 1) * rowDir.x + c * colDir.x,
            (r + 1) * rowDir.y + c * colDir.y);
    }
}
}
