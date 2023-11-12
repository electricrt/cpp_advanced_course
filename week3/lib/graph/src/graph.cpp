//
// Created by Alan Hu on 11/11/23.
//
#include <queue>
#include <random>
#include "graph.h"
#include "common.h"
#include <stdexcept> // Include for std::runtime_error
#include <iostream>


Graph::Graph(int vertices) {
    try {
        if (vertices <= 0) {
            throw std::runtime_error("Number of vertices must be positive.");
        }

        numVertices = vertices;
        adjMatrix.resize(vertices, std::vector<double>(vertices, MAX_DISTANCE));
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i][i] = 0; // Distance to itself is 0
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error in Graph constructor: " << e.what() << std::endl;
        // Handle the error or rethrow to be handled at a higher level
        throw; // Rethrow the exception if you want to handle it outside the constructor
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

void Graph::addEdge(int start, int end, double distance) {
    adjMatrix[start][end] = distance;
    adjMatrix[end][start] = distance; // For undirected graph
}

void Graph::generateRandomGraph(double density, double minDistance, double maxDistance) {
    srand(time(nullptr)); // Seed for random number generation
    // Other random number generation code
    std::random_device rd;

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            double prob = (double) rand() / RAND_MAX;
            if (prob < density) {
                double distance = minDistance + (double) rand() / RAND_MAX * (maxDistance - minDistance);
                addEdge(i, j, distance);
            }
        }
    }
}

std::vector<double> Graph::dijkstrasAlgorithm(int source) {
    std::vector<double> distances(numVertices, MAX_DISTANCE);
    std::vector<bool> visited(numVertices, false);
    distances[source] = 0;

    using pii = std::pair<double, int>; // Pair of (distance, vertex)
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (int i = 0; i < numVertices; ++i) {
            double edgeDistance = adjMatrix[current][i];
            if (edgeDistance < MAX_DISTANCE && !visited[i]) {
                double newDist = distances[current] + edgeDistance;
                if (newDist < distances[i]) {
                    distances[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }
    }

    return distances;
}

double Graph::averageShortestPath() {
    std::vector<double> distances = dijkstrasAlgorithm(0); // Assuming 0 as the source node
    double totalDistance = 0;
    int count = 0;

    for (int i = 1; i < numVertices; ++i) {
        if (distances[i] != MAX_DISTANCE) {
            totalDistance += distances[i];
            count++;
        }
    }

    return count > 0 ? totalDistance / count : 0;
}

double Graph::edgeDistance(int start, int end) const {
    if (start < 0 || start >= numVertices || end < 0 || end >= numVertices) {
        // Handle invalid indices, perhaps throw an exception or return a special value
        return -1; // Example: return -1 to indicate an error
    }
    return adjMatrix[start][end];
}



