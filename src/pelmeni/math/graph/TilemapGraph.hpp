#pragma once

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"

namespace p2d { namespace math {
    struct Heightmap {
        using HeightmapData = std::vector<std::vector<float>>;
        const size_t rows;
        const size_t cols;
        HeightmapData data;
    }; // struct Heightmap

    class TilemapGraph : public Graph{
    public:
        TilemapGraph(const Heightmap& heightmap);

        const CostCounter& getPrecalculatedCosts() const;
        void precalculateCostsFromNode(const size_t sourceNode);
    private:
        void buildGraphFromHeightmap(const Heightmap& heightmap);
        const size_t numRows;
        const size_t numCols;
        CostCounter precalculatedCosts;
    }; // class TilemapGraph
}
}