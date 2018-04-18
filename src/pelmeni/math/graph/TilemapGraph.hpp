#pragma once

#include "math/graph/Graph.hpp"

namespace p2d { namespace math {
    class TilemapGraph : public Graph{
    public:
        TilemapGraph(const size_t rows, const size_t cols);
    private:
        void setupEdges();
        const size_t numRows;
        const size_t numCols;
    }; // class TilemapGraph
}
}