#include "graphics/Tilemap.hpp"

namespace p2d { namespace graphics {
    void Tilemap::setTileSize(const math::Vector2f& tSize) {
        tileSize = tSize;
    }

    void Tilemap::setTilemapSize(const size_t& rows, const size_t& cols) {
        numRows = rows;
        numCols = cols;
    }

    void Tilemap::buildTilemap() {
        auto meshData = std::make_shared<MeshData2D>(
            generateMeshVertices(numRows, numCols, tileSize),
            generateMeshLines(numRows, numCols),
            generateMeshQuads(numRows, numCols)
        );
        mesh.setMeshData(meshData);
        for (size_t r = 0; r < numRows; r++) {
            for (size_t c = 0; c < numCols; c++) {
                setQuadColor(r, c, sf::Color(92, 92, 92));
            }
        }
    }

    void Tilemap::transformVertices() {
        mesh.transformMesh(getLocalTransform());
    }

    void Tilemap::setQuadColor(const size_t& row, const size_t& col, const sf::Color& color) {
        sf::Vertex* quad = getQuadVertices(row, col);
        quad[0].color = sf::Color(128, 128, 128);
        quad[1].color = sf::Color(128, 128, 128);
        quad[2].color = sf::Color(128, 128, 128);
        quad[3].color = sf::Color(128, 128, 128);
    }

    sf::Vertex* Tilemap::getQuadVertices(const size_t& row, const size_t& col) {
        const size_t quadIndex = col + numCols * row;
        return mesh.getQuadVertices(quadIndex);
    }

    void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(mesh);
    }

    graphics::MeshVertices Tilemap::generateMeshVertices(const size_t& rows, const size_t& cols, const math::Vector2f& tileSize) {
        MeshVertices vertices;
        vertices.resize((rows + 1) * (cols + 1));
        for (size_t r = 0; r <= rows; r++) {
            for (size_t c = 0; c <= cols; c++) {
                const float x = tileSize.x * c;
                const float y = tileSize.y * r;
                vertices[r * (cols + 1) + c] = math::Vector2f(x, y);
            }
        }
        return vertices;
    }

    graphics::MeshEdges Tilemap::generateMeshLines(const size_t& rows, const size_t& cols) {
        MeshEdges lines;
        lines.reserve(rows + cols + 2);
        const size_t C = cols + 1;
        for (size_t r = 0; r <= rows; r++) {
            lines.push_back(graphics::Edge2D{r * C, C * (r + 1) - 1});
        }
        for (size_t c = 0; c <= cols; c++) {
            lines.push_back(graphics::Edge2D{c, C * rows + c});
        }
        return lines;
    }

    graphics::MeshQuads Tilemap::generateMeshQuads(const size_t& rows, const size_t& cols) {
        MeshQuads quads;
        quads.reserve(rows * cols);
        const size_t C = cols + 1;
        for (size_t r = 0; r < rows; r++) {
            for (size_t c = 0; c < cols; c++) {
                quads.push_back(graphics::Quad2D{
                    r * C + c,
                    r * C + c + 1,
                    (r + 1) * C + c + 1,
                    (r + 1) * C + c
                });
            }
        }
        return quads;
    }
}
}