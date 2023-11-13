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
#include <iostream>
#include "../../monteCarloSim/src/monteCarloSim.h"
#include "../../graph/src/graph.h"
#include "../../runtime_parameters/src/runtime_parameters.h"
#include "../../../src/common.h"

runtime_param::RuntimeParameters rt;

int run_graph() {
    // Use the construction from class Graph to create a graph with NUM_VERTICES nodes
    Graph g(rt.getNumVertices());

    std::cout << "Initializing Graph with NUM_VERTICES: " << NUM_VERTICES << std::endl;

    rt.setDensity(0.2);
    // Generate the graph with 20% density and distances between 1.0 and 10.0
    g.generateRandomGraph(rt.getDensity(), rt.getMinDistance(), rt.getMaxDistance());

    // Calculate average shortest path
    double avgPathLength = g.averageShortestPath();
    std::cout << "Average Shortest Path Length at 20% density: " << avgPathLength << std::endl;

    rt.setDensity(0.4);
    // Repeat for 40% density
    g.generateRandomGraph(rt.getDensity(), rt.getMinDistance(), rt.getMaxDistance());

    avgPathLength = g.averageShortestPath();

    std::cout << "Average Shortest Path Length at 40% density: " << avgPathLength << std::endl;

    return 0;

}

int run_monteCarloSim() {
    // Create a MonteCarloSimulation object with 50 vertices, distances between 1.0 and 10.0
    mcm::MonteCarloSimulation mcs(rt.getNumVertices(), rt.getMinDistance(), rt.getMaxDistance());

    // Run the simulation with 1000 graphs and 20% density
    mcs.runSimulation(rt.getNumGraphs(), rt.getDensity());

    // Get the average shortest path
    double avgPathLength = mcs.getAverageShortestPath();
    std::cout << "Average Path Length at 20% density: " << avgPathLength << std::endl;

    // Repeat for 40% density
    mcs.runSimulation(rt.getNumGraphs(), rt.getDensity());

    avgPathLength = mcs.getAverageShortestPath();

    std::cout << "Average Path Length at " << rt.getDensity() << " density: "
              << avgPathLength << std::endl;

    std::cout << "Average Shortest Path at " << rt.getDensity() << " density: "
              << mcs.getAverageShortestPath() << std::endl;

    return 0;

}
