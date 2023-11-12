/*
 *
 *   3.4 Using Dijkstra's Algorithm
 *
 * This program creates a random graph with 50 vertices and runs Dijkstra's algorithm on it.
 * It then calculates the average shortest path length for different densities of the graph.
 *
 * Author: alanhu
 * Date: 11/11/23
 * Course: C++ For C Programmers, Part A
 */
#include "main_test.h"

#include "graph.h"
#include "common.h"
#include <gtest/gtest.h>

// Test the constructor
TEST(GraphTest, HandlesConstruction) {
Graph g(5);
int numVertices = g.getNumVertices();
EXPECT_EQ(numVertices, 5);
}

// Test adding edges
TEST(GraphTest, HandlesAddEdge) {
Graph g(5);
g.addEdge(0, 1, 2.0);
EXPECT_EQ(g.edgeDistance(0, 1), 2.0);
EXPECT_EQ(g.edgeDistance(1, 0), 2.0); // For undirected graph
}

// Test generating random graph
TEST(GraphTest, HandlesRandomGraphGeneration) {
Graph g(10);
g.generateRandomGraph(0.5, 1.0, 10.0);
// Test some property of the graph, like the number of edges
// This will depend on how you can access this information in your Graph class
}

// Test Dijkstra's algorithm
TEST(GraphTest, HandlesDijkstrasAlgorithm) {
Graph g(5);
// Add some edges
g.addEdge(0, 1, 1.0);
g.addEdge(1, 2, 2.0);
g.addEdge(0, 2, 10.0);
auto distances = g.dijkstrasAlgorithm(0);
EXPECT_EQ(distances[2], 3.0); // Shortest path from 0 to 2 should be 3.0
}

// Test average shortest path calculation
TEST(GraphTest, HandlesAverageShortestPath) {
Graph g(5);
// Add edges
// ...
double averagePath = g.averageShortestPath();
// Check the average path length against an expected value
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
