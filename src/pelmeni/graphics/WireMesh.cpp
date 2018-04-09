#include "graphics/WireMesh.hpp"

namespace p2d { namespace graphics {
    WireMesh::WireMesh(const Vector3List& vectorList, const EdgeList& edgeList)
    : _vectorList(vectorList), _edgeList(edgeList) {
        initMesh();
    }

    void WireMesh::initMesh() {
        vertices.resize(2*_edgeList.size());
        vertices.setPrimitiveType(sf::PrimitiveType::Lines);
    }

    void WireMesh::transformAndProjectToXY() {
        for (size_t i = 0; i < _edgeList.size(); i++) {
            // Get index for vector
            const size_t index0 = std::get<0>(_edgeList[i]);
            const size_t index1 = std::get<1>(_edgeList[i]);
            // Transform and store vector3
            const math::Vector3f vector0 = getTransform3().transformVector(_vectorList[index0]);
            const math::Vector3f vector1 = getTransform3().transformVector(_vectorList[index1]);
            // Project vector3 to vector2
            const math::Vector2f projected0 = math::projectToXY(vector0);
            const math::Vector2f projected1 = math::projectToXY(vector1);
            // Set position of vertex to projected vector2
            vertices[2*i].position = projected0;
            vertices[2*i + 1].position = projected1;
        }
    }

    void WireMesh::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(vertices);
    }
} // namespace graphics
} // namespcae p2d