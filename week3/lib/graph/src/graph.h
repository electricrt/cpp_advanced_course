//
// Created by Alan Hu on 11/11/23.
//
#include <cstdlib>
#include <vector>

#ifndef UCSC_GRAPH_H
#define UCSC_GRAPH_H



class Graph {
private:
    std::vector <std::vector<double>> adjMatrix; // Used for 2D Matrix
    std::vector<double> adjArray; // Used for 1D Array

    int numVertices;

public:
    // Constructor
    Graph(int vertices);
    // Dijkstra's algorithm to find shortest path
    std::vector<double> dijkstrasAlgorithm(int source);
    // getter for numVerices
    int getNumVertices() const;
    // Return distance between two vertices
    double edgeDistance(int start, int end) const;
    //

    // Calculate average shortest path
    double averageShortestPath();
    // Add edge
    void addEdge(int start, int end, double distance);
    // Generate random graph
    void generateRandomGraph(double density, double minDistance, double maxDistance);

};


#endif //UCSC_GRAPH_H
