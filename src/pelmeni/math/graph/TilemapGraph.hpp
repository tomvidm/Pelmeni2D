#pragma once

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"

namespace p2d { namespace math {
    struct Heightmap {
        using HeightmapData = std::vector<std::vector<float>>;
        size_t rows;
        size_t cols;
        HeightmapData data;
    }; // struct Heightmap

    enum class GraphBuildRules {
        DOWNSLOPE_IS_FREE,
        COST_BY_TARGET_COLOUR
    };

    class TilemapGraph : protected Graph{
    public:
        TilemapGraph();
        void buildGraphFromHeightmap(const Heightmap& argheightmap);
    }; // class TilemapGraph
}
}