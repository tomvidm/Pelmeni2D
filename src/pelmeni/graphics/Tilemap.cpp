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
    }

    void Tilemap::transformVertices() {
        mesh.transformMesh(getLocalTransform());
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