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
//
// Created by Alan Hu on 11/11/23.
//

#include "debug.h"

// Define DEBUG_MODE to enable debug output
#define DEBUG_MODE

#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) std::cout << (x) << std::endl
#else
#define DEBUG_PRINT(x)
#endif

