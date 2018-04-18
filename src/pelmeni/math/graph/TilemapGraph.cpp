#include "math/graph/TilemapGraph.hpp"

namespace p2d { namespace math {
    TilemapGraph::TilemapGraph(const size_t rows, const size_t cols) 
    : numRows(rows), numCols(cols) {
        addNodes(numRows * numCols);
    }

    void TilemapGraph::setupEdges() {
        for (size_t r = 0; r < numRows; r++) {
            for (size_t c = 0; c < numCols; c++) {
                const size_t i = r * numCols + c;
                if (r < numRows - 1) {
                    const size_t i_down = (r + 1) * numCols + c;
                    connect(i, i_down, 1.f);
                }
                if (c < numCols - 1) {
                    const size_t i_right = r * numCols + c + 1;
                    connect(i, i_right, 1.f);
                }
            }
        }
    }
}
}