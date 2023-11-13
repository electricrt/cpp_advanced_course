//
// Created by Alan Hu on 11/11/23.
//

#ifndef UCSC_COMMON_H
#define UCSC_COMMON_H

#include "../lib/appstate/src/appstate.h"

enum class YourEnumType {
    init_,
    graph_constructor,
    graph_getNumVertices,
    graph_add_edge,
    graph_edge_distance,
    graph_generateRandomGraph,
    graph_dijkstrasAlgorithm,


};

extern ProgramStateClass<YourEnumType> stateMachine;

const double MAX_DISTANCE = std::numeric_limits<double>::infinity();
const int NUM_VERTICES = 50;





// Run MONTE_CARLO_SIM or
#endif //UCSC_COMMON_H
