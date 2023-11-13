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
#include "../lib/integration/src/integration.h"

#include "common.h"
#include "../lib/appstate/src/appstate.h"

enum class mainState {
    init_,
    run_graph_completed,
    run_monteCarloSim_completed,
};

ProgramStateClass<YourEnumType> stateMachine = ProgramStateClass<YourEnumType>(YourEnumType::init_);

// Main function
int main() {
    try {
      //  stateMachine.setState(static_cast<initState>(mainState::init_));
            run_graph();
            stateMachine.setState(static_cast<YourEnumType>(mainState::run_graph_completed));
        run_monteCarloSim();
        stateMachine.setState(static_cast<YourEnumType>(mainState::run_monteCarloSim_completed));
        // Exception Handler

        } catch (const std::runtime_error& e) {
            std::cerr << "Failed to initialize graph: " << e.what() << std::endl;
            return 1; // Return 1 to indicate error
    }

    return 0; // Return 0 to indicate success
}

