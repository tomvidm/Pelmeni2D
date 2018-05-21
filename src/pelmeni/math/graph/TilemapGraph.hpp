#pragma once

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"
#include "graphics/Tilemap.hpp"

namespace p2d { namespace math {
    struct Heightmap {
        using HeightmapData = std::vector<std::vector<float>>;
        size_t rows;
        size_t cols;
        HeightmapData data;
    }; // struct Heightmap

    Heightmap buildRandomHeightmap(const size_t rows, const size_t cols);
    Heightmap buildUniformHeightmap(const size_t rows, const size_t cols);

    enum class GraphBuildRules {
        DOWNSLOPE_IS_FREE,
        COST_BY_TARGET_COLOUR
    };

    class TilemapGraph : public Graph {
    public:
        TilemapGraph();
        void buildGraphFromHeightmap(const Heightmap& argheightmap);

        const size_t getNode(const graphics::TileCoordinate coord) const;
    private:
        size_t rows;
        size_t cols;
    }; // class TilemapGraph
}
}