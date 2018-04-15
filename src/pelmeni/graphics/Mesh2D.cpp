#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
        Mesh2D::Mesh2D() {
            linesToDraw.setPrimitiveType(sf::PrimitiveType::Lines);
            quadsToDraw.setPrimitiveType(sf::PrimitiveType::Quads);
        }
    
        void Mesh2D::buildMesh() {
            MeshVertices& vertices = meshData->getMeshVertices();
            size_t i = 0;
            for (auto& quad : meshData->getMeshQuads()) {
                const Mesh2DVertex v[] = {
                    vertices[quad.v[0]],
                    vertices[quad.v[1]],
                    vertices[quad.v[2]],
                    vertices[quad.v[3]]
                };
                quadsToDraw[i++].position = v[0];
                quadsToDraw[i++].position = v[1];
                quadsToDraw[i++].position = v[2];
                quadsToDraw[i++].position = v[3];
            }
            
            i = 0;
            for (auto& edge : meshData->getMeshEdges()) {
                const Mesh2DVertex v[] = {
                    vertices[edge.v[0]],
                    vertices[edge.v[1]]
                };
                linesToDraw[i++].position = v[0];
                linesToDraw[i++].position = v[1];
            }
        } // tranformMesh

        void Mesh2D::setRenderEdges(const bool& yesno) {
            renderEdges = yesno;
        }

        void Mesh2D::setMeshData(std::shared_ptr<MeshData2D> extMeshData) {
            meshData = extMeshData;
            linesToDraw.resize(2 * meshData->getNumEdges());
            quadsToDraw.resize(4 * meshData->getNumQuads());
            buildMesh();
        }

        void Mesh2D::setQuadColor(const size_t& q, const sf::Color& color) {
            sf::Vertex* quad = getQuadVertices(q);
            quad[1].color = color;
            quad[0].color = color;
            quad[2].color = color;
            quad[3].color = color;
        }

        void Mesh2D::setQuadTextureCoordinates(const size_t& q, const QuadTextureCoordinates& texCoord) {
            sf::Vertex* quad = getQuadVertices(q);
            quad[0].texCoords = texCoord[0];
            quad[1].texCoords = texCoord[1];
            quad[2].texCoords = texCoord[2];
            quad[3].texCoords = texCoord[3];
        }

        sf::Vertex* Mesh2D::getQuadVertices(const size_t& q) {
            return &quadsToDraw[4 * q];
        }

        void Mesh2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(quadsToDraw, states);
            if (renderEdges) target.draw(linesToDraw, states);
        }
} // namespace graphics
} // namespace p2d