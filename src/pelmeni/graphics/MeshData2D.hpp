#pragma once

#include <vector>

#include "math/Vector.hpp"

namespace p2d { namespace graphics {
    struct Edge2D {
        size_t v0;
        size_t v1;
    };

    using Mesh2DVertex = math::Vector2f;
    using MeshVertices = std::vector<Mesh2DVertex>;
    using MeshEdges = std::vector<Edge2D>;
    class MeshData2D {
    public:
        MeshData2D();
        MeshData2D(const MeshVertices& mVecs, const MeshEdges& mEdges);

        void setMeshVertices(const MeshVertices& mVecs);
        void setMeshEdges(const MeshEdges& mEdges);

        MeshVertices& getMeshVertices();
        MeshEdges& getMeshEdges();

        inline size_t getNumEdges() const { return meshEdges.size(); }
    private:
        MeshVertices meshVertices;
        MeshEdges meshEdges;
    }; // class MeshData2D
} // namespace graphics
} // namespace p2d