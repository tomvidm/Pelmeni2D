#include "gtest/gtest.h"

#include "math/graph/Graph.hpp"
#include "math/graph/Dijkstra.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestGraph, edges_works) {
        Node node_a;
        node_a.addEdge(Edge{1});
        node_a.addEdge(Edge{2});
        node_a.addEdge(Edge{3});
        EXPECT_TRUE(node_a.hasEdgeTo(1));
        EXPECT_TRUE(node_a.hasEdgeTo(2));
        EXPECT_TRUE(node_a.hasEdgeTo(3));
    }

    TEST(TestGraph, shortest_path_Dijkstra_works_fine) {
        Graph graph;
        size_t a = graph.addNode();
        size_t b = graph.addNode();
        size_t c = graph.addNode();
        size_t d = graph.addNode();
        size_t e = graph.addNode();

        graph.connect(a, b, 1.f);
        graph.connect(a, c, 4.f);
        graph.connect(b, c, 1.f);
        graph.connect(b, d, 3.f);
        graph.connect(c, d, 1.f);
        graph.connect(d, e, 1.f);

        Path shortestPath = shortestPath_Dijkstra(graph, a, e);

        Step expected_steps[] = {
            Step{0, 0, 0.f},
            Step{1, 0, 1.f},
            Step{2, 1, 2.f},
            Step{3, 2, 3.f},
            Step{4, 3, 4.f}
        };

        EXPECT_EQ(shortestPath[0], expected_steps[0]);
    }
}
}
}