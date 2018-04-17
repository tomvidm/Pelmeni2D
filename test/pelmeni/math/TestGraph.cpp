#include "gtest/gtest.h"

#include "math/graph/Graph.hpp"
#include "math/graph/SearchBFS.hpp"

namespace p2d { namespace math { namespace ut {
    TEST(TestGraph, EdgeWorksFine) {
        Node node_a;
        node_a.addEdge(Edge{1});
        node_a.addEdge(Edge{2});
        node_a.addEdge(Edge{3});
        EXPECT_TRUE(node_a.hasEdgeTo(1));
        EXPECT_TRUE(node_a.hasEdgeTo(2));
        EXPECT_TRUE(node_a.hasEdgeTo(3));
    }

    TEST(TestGraph, GraphWorksFine) {
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
}
}
}