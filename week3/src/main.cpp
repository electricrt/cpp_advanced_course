
#include <iostream>
#include "graph.h"




// Main function
    int main() {
        // Create a graph with 50 nodes
        Graph g(6);

        // Generate the graph with 20% density and distances between 1.0 and 10.0
        g.generateRandomGraph(0.2, 1.0, 10.0);

        // Calculate average shortest path
        double avgPathLength = g.averageShortestPath();
        std::cout << "Average Path Length at 20% density: " << avgPathLength << std::endl;

        // Repeat for 40% density
        g.generateRandomGraph(0.4, 1.0, 10.0);
        avgPathLength = g.averageShortestPath();
        std::cout << "Average Path Length at 40% density: " << avgPathLength << std::endl;

        return 0;
    }

