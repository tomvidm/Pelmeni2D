#include "math/graph/TilemapGraph.hpp"

namespace p2d { namespace math {
    TilemapGraph::TilemapGraph(const Heightmap& heightmap) 
    : numRows(heightmap.rows), numCols(heightmap.cols) {
        addNodes(numRows * numCols);
        buildGraphFromHeightmap(heightmap);
    }

    const CostCounter& TilemapGraph::getPrecalculatedCosts() const {
        return precalculatedCosts;
    }

    void TilemapGraph::precalculateCostsFromNode(const size_t sourceNode) {
        precalculatedCosts = precalculatedGraphCosts(*this, sourceNode);
    }

    void TilemapGraph::buildGraphFromHeightmap(const Heightmap& heightmap) {
        for (size_t r = 0; r < numRows; r++) {
            for (size_t c = 0; c < numCols; c++) {
                const float weightHere = heightmap.data[r][c];
                const size_t i = r * numCols + c;
                if (r < numRows - 1) {
                    const float weightThere = heightmap.data[r + 1][c];
                    const size_t i_down = (r + 1) * numCols + c;
                    connectTo(i, i_down, weightThere);
                    connectTo(i_down, i, weightHere);
                }
                if (c < numCols - 1) {
                    const float weightThere = heightmap.data[r][c + 1];
                    const size_t i_right = r * numCols + c + 1;
                    connectTo(i, i_right, weightThere);
                    connectTo(i_right, i, weightHere);
                }
            }
        }
    }
}
}