/*
 *
 *   3.4 Using Dijkstra's Algorithm
 *
 * This program creates a random graph with 50 vertices and runs Dijkstra's algorithm on it.
 * It then calculates the average shortest path length for different densities of the graph.
 *
 * Author: Alan Hu
 * Date: 11/11/23
 * Course: C++ For C Programmers, Part A
 */


#include <iostream>
#include "../lib/graph/src/graph.h"
#include "../lib/debug/src/debug.h"
#include "../lib/integration/src/integration.h"


// Main function
int main() {
    try {

        run_graph();

        run_monteCarloSim();
        // Exception Handler
        } catch (const std::runtime_error& e) {
            std::cerr << "Failed to initialize graph: " << e.what() << std::endl;
            return 1; // Return 1 to indicate error
    }

    return 0; // Return 0 to indicate success
}

