#include <tuple>

#include "SFML/Graphics.hpp"

#include "math/Vector.hpp"
#include "math/Transform3.hpp"
#include "system/Transformable3.hpp"

namespace p2d { namespace graphics {
    using Vector3List = std::vector<math::Vector3f>;
    using Vector2List = std::vector<math::Vector2f>;
    using EdgeList = std::vector<std::tuple<size_t, size_t>>;

    class WireMesh : public sf::Drawable, public p2d::system::Transformable3 {
    public:
        WireMesh(const Vector3List& vectorList, const EdgeList& edgeList);

        void initMesh();
        void transformAndProjectToXY();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        Vector3List _vectorList;
        Vector2List _projectedList;
        EdgeList _edgeList;

        sf::VertexArray vertices;
    }; // class WireMesh
} // namespace graphics
} // namespcae p2d