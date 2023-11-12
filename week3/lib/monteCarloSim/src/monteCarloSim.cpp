//
// Created by Alan Hu on 11/11/23.
//

#include "monteCarloSim.h"
#include "../../graph/src/graph.h"

namespace mcm {
    MonteCarloSimulation::MonteCarloSimulation(int numVertices, double minDistance, double maxDistance) {
        // initialize graph with number of vertices
        this->numVertices = numVertices;
        this->minDistance = minDistance;
        this->maxDistance = maxDistance;
        totalShortestPath = 0;
        validGraphCount = 0;
    }

    void MonteCarloSimulation::runSimulation(int numGraphs, double density) {
        for(int i = 0; i < numGraphs; i++) {
            generateAndProcessGraph(density);
        }
    }

    double MonteCarloSimulation::getAverageShortestPath() const {
        return validGraphCount > 0 ? totalShortestPath / validGraphCount : 0;
    }

    void MonteCarloSimulation::generateAndProcessGraph(double density) {
        Graph g(numVertices);
        g.generateRandomGraph(density, minDistance, maxDistance);
        double avgPathLength = g.averageShortestPath();
        if(avgPathLength > 0) { // Check if a path exists
            totalShortestPath += avgPathLength;
            validGraphCount++;
        }
    }
} // mcm