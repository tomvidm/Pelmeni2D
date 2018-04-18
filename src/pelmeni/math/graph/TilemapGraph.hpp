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

    enum class GraphBuildRules {
        DOWNSLOPE_IS_FREE,
        COST_BY_TARGET_COLOUR
    };

    class TilemapGraph : public Graph{
    public:
        TilemapGraph();
        TilemapGraph(const Heightmap& heightmap);

        void setHeightmap(const Heightmap& heightmap);

        const CostCounter& getPrecalculatedCosts() const;
        const CostCounter& getPrecalculatedCosts(const size_t sourceNode);
        void precalculateCostsFromNode(const size_t sourceNode);
    private:
        void buildGraphFromHeightmap(const Heightmap& heightmap);
        const size_t numRows;
        const size_t numCols;
        CostCounter precalculatedCosts;
    }; // class TilemapGraph
}
}