//
// Created by Alan Hu on 11/11/23.
// This class stores runtime parameters that can be set externally
// before running simulations

#ifndef UCSC_RUNTIME_PARAMETERS_H
#define UCSC_RUNTIME_PARAMETERS_H

namespace runtime_param {

    class RuntimeParameters {
        private:
            int numVertices;
            double minDistance;
            double maxDistance;
            int numGraphs; // Number of random graphs to generate
            double density; // Graph density
        public:
        // Constructor with default values
            explicit RuntimeParameters(int vertices = 50, double minDist = 1.0, double maxDist = 10.0,
                          int graphs = 1000, double dens = 0.2)
                : numVertices(vertices), minDistance(minDist), maxDistance(maxDist),
                  numGraphs(graphs), density(dens) {}

            // Setters
            void setNumVertices(int vertices) {
                numVertices = vertices;
            }

            void setMinDistance(double minDist) {
                minDistance = minDist;
            }

            void setMaxDistance(double maxDist) {
                maxDistance = maxDist;
            }

            void setNumGraphs(int graphs) {
                numGraphs = graphs;
            }

            void setDensity(double dens) {
                density = dens;
            }

            // Getters
            int getNumVertices() const {
                return numVertices;
            }

            double getMinDistance() const {
                return minDistance;
            }

            double getMaxDistance() const {
                return maxDistance;
            }

            int getNumGraphs() const {
                return numGraphs;
            }

            double getDensity() const {
                return density;
            }
    };
} // rt_param

#endif //UCSC_RUNTIME_PARAMETERS_H
