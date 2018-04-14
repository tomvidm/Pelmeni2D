#include "graphics/Mesh2D.hpp"

namespace p2d { namespace graphics {
        Mesh2D::Mesh2D() {
            linesToDraw.setPrimitiveType(sf::PrimitiveType::Lines);
            quadsToDraw.setPrimitiveType(sf::PrimitiveType::Quads);
        }
    
        void Mesh2D::transformMesh(const math::Transform& transform) {
            MeshVertices& vertices = meshData->getMeshVertices();
            size_t i = 0;
            for (auto& quad : meshData->getMeshQuads()) {
                const Mesh2DVertex v[] = {
                    transform.transformVector(vertices[quad.v[0]]),
                    transform.transformVector(vertices[quad.v[1]]),
                    transform.transformVector(vertices[quad.v[2]]),
                    transform.transformVector(vertices[quad.v[3]])
                };
                quadsToDraw[i++].position = v[0];
                quadsToDraw[i++].position = v[1];
                quadsToDraw[i++].position = v[2];
                quadsToDraw[i++].position = v[3];
            }
            
            i = 0;
            for (auto& edge : meshData->getMeshEdges()) {
                const Mesh2DVertex v[] = {
                    transform.transformVector(vertices[edge.v[0]]),
                    transform.transformVector(vertices[edge.v[1]])
                };
                linesToDraw[i++].position = v[0];
                linesToDraw[i++].position = v[1];
            }
        } // tranformMesh

        void Mesh2D::setMeshData(std::shared_ptr<MeshData2D> extMeshData) {
            meshData = extMeshData;
            linesToDraw.resize(2 * meshData->getNumEdges());
            quadsToDraw.resize(4 * meshData->getNumQuads());
        }

        sf::Vertex* Mesh2D::getQuadVertices(const size_t& q) {
            return &quadsToDraw[4 * q];
        }

        void Mesh2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
            target.draw(quadsToDraw);
            target.draw(linesToDraw);
        }
} // namespace graphics
} // namespace p2d