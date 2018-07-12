#pragma once

#include <vector>
#include <memory>

#include "math/Vector.hpp"

namespace p2d { namespace graphics {
    struct EdgeIndices {
        size_t v[2];
    };

    struct QuadIndices {
        size_t v[4];
    };

    using Mesh2DVertex = math::Vector2f;
    using MeshVertices = std::vector<Mesh2DVertex>;
    using MeshEdges = std::vector<EdgeIndices>;
    using MeshQuads = std::vector<QuadIndices>;

    struct EdgeVertices {
        Mesh2DVertex v[2];
    };

    class MeshData2D {
    public:
        using shared = std::shared_ptr<MeshData2D>;
    public:
        MeshData2D();
        MeshData2D(const MeshVertices& mVecs, const MeshEdges& mEdges, const MeshQuads& mQuads);

        void setMeshVertices(const MeshVertices& mVecs);
        void setMeshEdges(const MeshEdges& mEdges);
        void setMeshQuads(const MeshQuads& mQuads);

        MeshVertices& getMeshVertices();
        MeshEdges& getMeshEdges();
        MeshQuads& getMeshQuads();

        EdgeVertices getVerticesForEdge(const size_t e) const;
        //QuadVertices getVerticesForQuad(const size_t q) const;

        inline size_t getNumEdges() const { return meshEdges.size(); }
        inline size_t getNumQuads() const { return meshQuads.size(); }
    private:
        MeshVertices meshVertices;
        MeshEdges meshEdges;
        MeshQuads meshQuads;
    }; // class MeshData2D
} // namespace graphics
} // namespace p2d