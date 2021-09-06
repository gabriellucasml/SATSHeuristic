//
// Created by Gabriel on 01/09/2021.
//

#ifndef TSP_SATSHEURISTIC_H
#define TSP_SATSHEURISTIC_H


#include <vector>
#include "TSPData.h"

class SATSHeuristic {
private:
    TSPData tspdata;
    std::vector<int> tour;
    int solution;
public:

    int solve();

    int eval(std::vector<int> sol);

    [[nodiscard]] const TSPData &getTspdata() const;

    void setTspdata(const TSPData &tspdata);

    [[nodiscard]] const std::vector<int> &getTour() const;

    void setTour(const std::vector<int> &tour);

    [[nodiscard]] int getSolution() const;

    void setSolution(int solution);
};


#endif //TSP_SATSHEURISTIC_H
