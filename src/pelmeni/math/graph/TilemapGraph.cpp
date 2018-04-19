#include "math/graph/TilemapGraph.hpp"

namespace p2d { namespace math {
    Heightmap buildRandomHeightmap(const size_t rows, const size_t cols) {
        Heightmap hm;
        hm.rows = rows;
        hm.cols = cols;
        hm.data.resize(rows);
        for (size_t r = 0; r < rows; r++) {
            hm.data[r].resize(cols);
            for (size_t c = 0; c < cols; c++) {
                hm.data[r][c] = 2.f * std::min(rand(), rand());
            }
        }
        return hm;
    }

    TilemapGraph::TilemapGraph() {
        ;
    }

    void TilemapGraph::buildGraphFromHeightmap(const Heightmap& heightmap) {
        addNodes(heightmap.rows * heightmap.cols);
        for (size_t r = 0; r < heightmap.rows; r++) {
            for (size_t c = 0; c < heightmap.cols; c++) {
                const float weightHere = heightmap.data[r][c];
                const size_t i = r * heightmap.cols + c;
                if (r < heightmap.rows - 1) {
                    const float weightThere = heightmap.data[r + 1][c];
                    const size_t i_down = (r + 1) * heightmap.cols + c;
                    connectTo(i, i_down, weightThere);
                    connectTo(i_down, i, weightHere);
                }
                if (c < heightmap.cols - 1) {
                    const float weightThere = heightmap.data[r][c + 1];
                    const size_t i_right = r * heightmap.cols + c + 1;
                    connectTo(i, i_right, weightThere);
                    connectTo(i_right, i, weightHere);
                }
            }
        }
    }
}
}