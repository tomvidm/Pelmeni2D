#include "gtest/gtest.h"

#include "math/graph/Graph.hpp"
#include "math/graph/SearchBFS.hpp"

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

    TEST(TestGraph, fill_BFS_works_fine) {
        Graph graph;
        size_t node_a = graph.addNode();
        size_t node_b = graph.addNode();
        size_t node_c = graph.addNode();

        graph.connect(node_a, node_b);
        graph.connect(node_b, node_c);

        EXPECT_TRUE(graph.isConnected(node_a, node_b));
        EXPECT_TRUE(graph.isConnected(node_b, node_c));
        EXPECT_FALSE(graph.isConnected(node_a, node_c));

        SearchBFS bfs_without_isolated_node(graph, node_a);
        EXPECT_EQ(bfs_without_isolated_node.fill().size(), 3);

        size_t isolated_node = graph.addNode();

        SearchBFS bfs_with_isolated_node(graph, isolated_node);
        EXPECT_EQ(bfs_with_isolated_node.fill().size(), 1);
    }

    TEST(TestGraph, shortest_path_BFS_works_fine) {
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

        SearchBFS bfs_shortest_path(graph, a, e);
        Path shortest_path = bfs_shortest_path.getShortestPath();
        EXPECT_EQ(shortest_path.nodes.size(), 5);
    }
}
}
}