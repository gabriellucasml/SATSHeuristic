//
// Created by Gabriel on 01/09/2021.
//

#include "SATSHeuristic.h"

using namespace std;

int SATSHeuristic::solve() {
    return 0;
}

const std::vector<int> &SATSHeuristic::getTour() const {
    return tour;
}

void SATSHeuristic::setTour(const std::vector<int> &tour) {
    SATSHeuristic::tour = tour;
}

int SATSHeuristic::getSolution() const {
    return solution;
}

void SATSHeuristic::setSolution(int solution) {
    SATSHeuristic::solution = solution;
}

int SATSHeuristic::eval(std::vector<int> sol) {
    int trip = 0;
    for(int i = 0; i < sol.size(); i++){
        if(i+1<sol.size())
            trip += this->tspdata.getAdjacencyMatrix()[sol[i]][sol[i+1]];
        else
            trip += this->tspdata.getAdjacencyMatrix()[sol[i]][sol[0]];
    }
    return trip;
}

const TSPData &SATSHeuristic::getTspdata() const {
    return tspdata;
}

void SATSHeuristic::setTspdata(const TSPData &tspdata) {
    SATSHeuristic::tspdata = tspdata;
}
