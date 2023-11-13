//
// Created by Alan Hu on 11/11/23.
//
#include <queue>
#include <random>
#include "graph.h"
#include "common.h"
#include <stdexcept> // Include for std::runtime_error
#include <iostream>
#include <limits>

//#include "../../appstate/src/appstate.h"
#define ARRAY_2D


// Constructor for the Graph class.
// Initializes a graph with a specified number of vertices.
Graph::Graph(int vertices) {
    try {
        if (vertices <= 0) {
            throw std::runtime_error("Number of vertices must be positive.");
        }

        numVertices = vertices;
#ifdef ARRAY_1D
        adjArray.resize(numVertices * numVertices, MAX_DISTANCE);

        for (int i = 0; i < numVertices; i++) {
            adjArray[i * numVertices + i] = 0;
        }
#endif
        // 2-D Array
#ifdef ARRAY_2D
        adjMatrix.resize(vertices, std::vector<double>(vertices, MAX_DISTANCE));

        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i][i] = 0; // Distance to itself is 0
        }
#endif
    } catch (const std::runtime_error& e) {
        std::cerr << "Error in Graph constructor: " << e.what() << std::endl;
        // Handle the error or rethrow to be handled at a higher level
        throw; // Rethrow the exception if you want to handle it outside the constructor
    }
}

// Getter for numVertices
int Graph::getNumVertices() const {
    return numVertices;
}

void Graph::addEdge(int start, int end, double distance) {

#ifdef ARRAY_1D
    double edgeWeight_start_end = start * numVertices + end;
    double edgeWeight_end_start = end * numVertices + start;
    adjArray[edgeWeight_start_end] = distance;
    adjArray[edgeWeight_end_start] = distance;
#endif
#ifdef ARRAY_2D
    adjMatrix[start][end] = distance;
    adjMatrix[end][start] = distance; // For undirected graph
#endif
}

// Generates a random graph based on given density and distance range.
// Density determines the likelihood of an edge existing between two vertices.
// Distance range determines the range of edge weights.
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

// Implementation of Dijkstra's algorithm to find the shortest path from a source vertex.
// Returns a vector of distances from the source to all other vertices.
/*std::vector<double> Graph::dijkstrasAlgorithm(int source) {
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
}*/

std::vector<double> Graph::dijkstrasAlgorithm(int source) {
    if (source < 0 || source >= numVertices) {
        throw std::invalid_argument("Invalid source vertex");
    }

    const double MAX_DISTANCE = std::numeric_limits<double>::infinity();
    std::vector<double> distances(numVertices, MAX_DISTANCE);
    std::vector<bool> visited(numVertices, false);
    distances[source] = 0;

    using DistanceVertexPair = std::pair<double, int>;
    std::priority_queue<DistanceVertexPair, std::vector<DistanceVertexPair>, std::greater<>> minHeap;
    minHeap.emplace(0, source);

    while (!minHeap.empty()) {
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        if (visited[currentVertex]) continue;
        visited[currentVertex] = true;

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            double edgeWeight = adjMatrix[currentVertex][neighbor];
            if (edgeWeight < MAX_DISTANCE && !visited[neighbor]) {
                double newDistance = distances[currentVertex] + edgeWeight;
                if (newDistance < distances[neighbor]) {
                    distances[neighbor] = newDistance;
                    minHeap.emplace(newDistance, neighbor);
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



