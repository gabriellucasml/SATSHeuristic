//
// Created by Gabriel on 01/09/2021.
//

#include "SATSHeuristic.h"
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
#include <cmath>


using namespace std;

int SATSHeuristic::solve(vector<int>solStart, double tStart, double tEnd, double tCool, int numCandidates, int tabuLen, double epochLen) {
     random_device rd;
     mt19937 rng(rd());
     uniform_real_distribution<> randFactor(0,1);
     double tCurrent = tStart;
     int it = 0;
     vector<int> currSol = std::move(solStart);
     int currFitness = eval(currSol);
     vector<int> bestSol = currSol;
     int bestFitness = currFitness;
     vector<vector<int>> tabuList;
     double rho;
     while(tCurrent > tEnd){
         while(it < epochLen){
            vector<vector<int>> neighborhood = SATSHeuristic::generate2opNeighborhood(currSol, numCandidates);
            vector<int> varSol;
            varSol.reserve(neighborhood.size());
            for(const auto& neighbor : neighborhood){
                varSol.push_back(eval(neighbor)-currFitness);
            }
            auto iter = min_element(varSol.begin(), varSol.end());
            int optIndex = distance(varSol.begin(), iter);
            if(currFitness + varSol[optIndex] < bestFitness && find(tabuList.begin(), tabuList.end(),neighborhood[optIndex])==tabuList.end()){//aspiration criterion
                currSol = neighborhood[optIndex];
                currFitness += varSol[optIndex];
                bestSol = neighborhood[optIndex];
                bestFitness = currFitness + varSol[optIndex];
                if(tabuList.size() < tabuLen){
                    tabuList.push_back(currSol);
                }else{
                    tabuList.erase(tabuList.cbegin());
                    tabuList.push_back(currSol);
                }
            }else{
                    rho = (eval(neighborhood[optIndex])-eval(currSol)>0?(exp(eval(neighborhood[optIndex])-eval(currSol))/tCurrent):1);
                if((find(tabuList.begin(), tabuList.end(), currSol) == tabuList.end() && varSol[optIndex] < 0) || rho < randFactor(rng)){
                    currSol = neighborhood[optIndex];
                    currFitness += currFitness + varSol[optIndex];
                    if(tabuList.size() < tabuLen){
                        tabuList.push_back(currSol);
                    }else{
                        tabuList.erase(tabuList.cbegin());
                        tabuList.push_back(currSol);
                    }
                }
            }
            it += 1;
         }
         tCurrent *= tCool;
     }
     this->tour = bestSol;
     this->solution = bestFitness;
     return solution;
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
    }
    return trip;
}

const TSPData &SATSHeuristic::getTspdata() const {
    return tspdata;
}

void SATSHeuristic::setTspdata(const TSPData &tspdata) {
    SATSHeuristic::tspdata = tspdata;
}

vector<vector<int>> SATSHeuristic::generate2opNeighborhood(const vector<int>& sol, int numNeighbors) {
    vector<vector<int>> neighborhood;
    for(int i = 0; i < sol.size()-1;i++){
        for(int j = i+1; j < sol.size()-1; j++){
            if(i != j){
                vector<int> newNeighbor(sol);
                int aux1 = newNeighbor[i], aux2 = newNeighbor[j];
                newNeighbor[j] = aux1;
                newNeighbor[i] = aux2;
                newNeighbor[sol.size()-1] = newNeighbor[0];
                neighborhood.push_back(newNeighbor);
            }
        }
        if(neighborhood.size() >= numNeighbors){
            break;
        }
    }
    return neighborhood;
}

vector<int> SATSHeuristic::nnHeuristic() {

    vector<int> nnSol(this->getTspdata().getDimension()+1);
    set<int> vertices;
    auto it = vertices.begin();

    for (int i = 0; i < this->getTspdata().getDimension(); i++) {
        it = vertices.insert(it, i);
    }
    nnSol[0] = 0;
    nnSol[this->getTspdata().getDimension()] = 0;
    vertices.erase(0);
    int currentVertex = 0, currentPosition = 1, shortest = this->getTspdata().getAdjacencyMatrix()[0][1];

    while(!vertices.empty()){
        for(int i = 1; i < this->getTspdata().getDimension(); i++) {
            if (currentVertex != i && vertices.contains(i)){
                if (this->getTspdata().getAdjacencyMatrix()[currentVertex][i] < shortest) {
                    shortest = this->getTspdata().getAdjacencyMatrix()[currentVertex][i];
                    nnSol[currentPosition] = i;
                }
            }
        }
        shortest = 2147483647;
        vertices.erase(nnSol[currentPosition]);
        currentVertex = nnSol[currentPosition];
        currentPosition++;
    }
    return nnSol;
}

SATSHeuristic::SATSHeuristic(TSPData tspdata) : tspdata(std::move(tspdata)) {
}

std::vector<int> SATSHeuristic::randomSolution() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> city(0,this->tspdata.getDimension());

}












