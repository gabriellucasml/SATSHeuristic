//
// Created by Gabriel on 01/09/2021.
//

#ifndef TSP_SATSHEURISTIC_H
#define TSP_SATSHEURISTIC_H


#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include "TSPData.h"

class SATSHeuristic {
private:

    TSPData tspdata;
    std::vector<int> tour;
    int solution{};

public:

    int solve(std::vector<int>solStart, double tStart, double tEnd, double tCool, int numCandidates, int tabuLen, double epochLen);

    static std::vector<std::vector<int>> generate2opNeighborhood(const std::vector<int>& sol, int numNeighbors);

    std::vector<int> nnHeuristic();

    std::vector<int> randomSolution();

    int eval(std::vector<int> sol);

    [[nodiscard]] const TSPData &getTspdata() const;

    void setTspdata(const TSPData &tspdata);

    [[nodiscard]] const std::vector<int> &getTour() const;

    void setTour(const std::vector<int> &tour);

    [[nodiscard]] int getSolution() const;

    void setSolution(int solution);

    SATSHeuristic(TSPData _tspdata, TSPData tspdata);

    [[maybe_unused]] SATSHeuristic(TSPData tspdata);
};


#endif //TSP_SATSHEURISTIC_H
