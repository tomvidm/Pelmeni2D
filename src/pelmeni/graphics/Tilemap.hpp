#pragma once

#include "SFML/Graphics.hpp"

#include "graphics/Mesh2D.hpp"
#include "graphics/MeshData2D.hpp"
#include "system/Transformable2.hpp"
#include "math/Vector.hpp"

namespace p2d { namespace graphics {
    class Tilemap : public sf::Drawable, public system::Transformable2 {
    public:
        void setTileSize(const math::Vector2f& tSize);
        void setTilemapSize(const size_t& rows, const size_t& cols);
        void buildTilemap();
        void transformVertices();

        sf::Vertex* getQuadVertices(const size_t& row, const size_t& col);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        math::Vector2f tileSize;
        size_t numRows;
        size_t numCols;
        static graphics::MeshVertices generateMeshVertices(const size_t& rows, const size_t& cols, const math::Vector2f& tileSize);
        static graphics::MeshEdges generateMeshLines(const size_t& rows, const size_t& cols);
        static graphics::MeshQuads generateMeshQuads(const size_t& rows, const size_t& cols);

        graphics::Mesh2D mesh;
    }; // class Tilemap
}
}