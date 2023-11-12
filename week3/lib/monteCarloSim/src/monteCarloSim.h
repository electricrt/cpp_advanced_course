//
// Created by Alan Hu on 11/11/23.
//

#ifndef UCSC_MONTECARLOSIM_H
#define UCSC_MONTECARLOSIM_H

namespace mcm {

    class MonteCarloSimulation {
    public:
        MonteCarloSimulation(int numVertices, double minDistance, double maxDistance);
        void runSimulation(int numGraphs, double density);
        double getAverageShortestPath() const;

    private:
        int numVertices;
        double minDistance;
        double maxDistance;
        double totalShortestPath;
        int validGraphCount;

        void generateAndProcessGraph(double density);
    };


} // mcm

#endif //UCSC_MONTECARLOSIM_H
