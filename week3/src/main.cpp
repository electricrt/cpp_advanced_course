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


#include <iostream>
#include "graph.h"
#include "debug.h"

const int NUM_VERTICES = 50;


// Main function
int main() {
    try {
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

        // Exception Handler
        } catch (const std::runtime_error& e) {
            std::cerr << "Failed to initialize graph: " << e.what() << std::endl;
            return 1; // Return 1 to indicate error
    }

    return 0; // Return 0 to indicate success
}

