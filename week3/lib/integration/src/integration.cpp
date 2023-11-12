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
#include "../../../src/common.h"


int run_graph() {
    // Use the construction from class Graph to create a graph with NUM_VERTICES nodes
    Graph g(NUM_VERTICES);

    std::cout << "Initializing Graph with NUM_VERTICES: " << NUM_VERTICES << std::endl;

    // Generate the graph with 20% density and distances between 1.0 and 10.0
    g.generateRandomGraph(0.2, 1.0, 10.0);

    // Calculate average shortest path
    double avgPathLength = g.averageShortestPath();
    std::cout << "Average Path Length at 20% density: " << avgPathLength << std::endl;

    // Repeat for 40% density
    g.generateRandomGraph(0.4, 1.0, 10.0);
    avgPathLength = g.averageShortestPath();
    std::cout << "Average Path Length at 40% density: " << avgPathLength << std::endl;

}

int run_monteCarloSim() {
    // Create a MonteCarloSimulation object with 50 vertices, distances between 1.0 and 10.0
    int numVertices = 50;
    double minDistance = 1.0;
    double maxDistance = 10.0;
    int numGraphs = 1000; // Number of random graphs to generate
    double density = 0.2; // Graph density


    mcm::MonteCarloSimulation mcs(50, 1.0, 10.0);

    // Run the simulation with 1000 graphs and 20% density
    mcs.runSimulation(1000, 0.2);

    // Get the average shortest path
    double avgPathLength = mcs.getAverageShortestPath();
    std::cout << "Average Path Length at 20% density: " << avgPathLength << std::endl;

    // Repeat for 40% density
    mcs.runSimulation(1000, 0.4);
    avgPathLength = mcs.getAverageShortestPath();
    std::cout << "Average Path Length at 40% density: " << avgPathLength << std::endl;


