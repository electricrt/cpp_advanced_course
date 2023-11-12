/*
 * Convert a C program to C++
 *
 * This program converts a C-style array and sum function into C++ using vectors,
 * inline functions, and C++ style IO.
 *
 * Author: alanhu
 * Date: 11/11/23
 * Course: ${COURSE_NAME}
 */

#include <gtest/gtest.h>
#include "../lib/graph/src/graph.h"
#include "../lib/monteCarloSim/src/monteCarloSim.h"
#include "../lib/runtime_parameters/src/runtime_parameters.h"

#define EDGE_START 0
#define EDGE_END 1
#define EDGE_DISTANCE 2


class MonteCarloTest : public ::testing::Test {
protected:
    // Setup any common resources here
};

//Setup any common resources here
runtime_param::RuntimeParameters rt;

// Tear down any common resources here

TEST_F(MonteCarloTest, RandomGraphGeneration) {
    rt.setNumVertices(50);

    Graph g(rt.getNumVertices());
    g.generateRandomGraph(rt.getDensity(), rt.getMinDistance(), rt.getMaxDistance());
    // Test the properties of the generated graph
    // For example, check the number of edges and vertices
}

TEST_F(MonteCarloTest, DijkstrasAlgorithm) {
    rt.setNumVertices(6);

    Graph g(rt.getNumVertices());
    // Add some predefined edges
    int edgeParam[3] = {0, 1, 2};

    g.addEdge(edgeParam[EDGE_START], edgeParam[EDGE_END], edgeParam[EDGE_DISTANCE]);

    edgeParam[EDGE_START] = 1;
    edgeParam[EDGE_END] = 2;
    edgeParam[EDGE_DISTANCE] = 3;

    g.addEdge(edgeParam[EDGE_START], edgeParam[EDGE_END], edgeParam[EDGE_DISTANCE]);
    // ...
    auto distances = g.dijkstrasAlgorithm(0);
    EXPECT_EQ(distances[2], 5.0); // Expected shortest path from 0 to 2
}

TEST_F(MonteCarloTest, AverageShortestPath) {
    rt.setNumVertices(5);

    Graph g(rt.getNumVertices());
    // Add edges
    // ...
    double averagePath = g.averageShortestPath();
    // Compare the calculated average path with an expected value
}

TEST_F(MonteCarloTest, MonteCarloSimulation) {
    // Set up Monte Carlo simulation parameters
    int numGraphs = 100;
    double density = 0.2;
    // ...
    // Run the Monte Carlo simulation
    // Calculate the average of average shortest paths
    // Compare the result with an expected range or value
}
/*

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
