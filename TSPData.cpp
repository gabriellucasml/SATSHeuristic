//
// Created by Gabriel on 29/08/2021.
//

#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "TSPData.h"

using namespace std;

TSPData::TSPData(const string& filePath) {
    this->filePath = filePath;
    ifstream file;
    file.open(filePath);
    string line, aux;
    getline(file, line);
    stringstream l;
    l.str(line);
    while(!file.eof()){
        l.str(line);
        l >> aux;
        if(aux == "NAME"){
            l >> aux;
            l >> aux;
            this->name = aux;
        }else if(aux == "TYPE"){
            l >> aux;
            l >> aux;
            this->type = aux;
        }else if(aux == "DIMENSION"){
            l >> aux;
            l >> aux;
            this->dimension = stoi(aux);
        }else if(aux == "EDGE_WEIGHT_TYPE"){
            l >> aux; l >> aux;
            this->edge_weight_type = aux;
        }else if(aux == "NODE_COORD_SECTION"){
            l.clear();
            l.seekg(0);
            getline(file, line);
            l.str(line);
            string aux2;
            while(!file.eof()){
                l >> aux;
                if(aux == "EOF"){
                    break;
                }
                l >> aux;
                l >> aux2;
                this->coordinates.emplace_back(stod(aux),stod(aux2));
                l.clear();
                l.seekg(0);
                getline(file,line);
                l.str(line);
            }
        }
        l.clear();
        l.seekg(0);
        getline(file,line);
    }
    file.close();
    adjacencyMatrix = new int*[dimension];
    for(int i = 0; i < dimension; i++)
        adjacencyMatrix[i] = new int[dimension];

    for(int i = 0; i < dimension; i++){

        for(int j = 0; j < dimension; j++){
            if(i>j){
                adjacencyMatrix[i][j] = (int)round(sqrt(pow(get<0>(coordinates[i])-get<0>(coordinates[j]),2)+pow(get<1>(coordinates[i])-get<1>(coordinates[j]),2)));
                adjacencyMatrix[j][i] = (int)round(sqrt(pow(get<0>(coordinates[i])-get<0>(coordinates[j]),2)+pow(get<1>(coordinates[i])-get<1>(coordinates[j]),2)));
            }else if(i==j){
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
}

const string &TSPData::getName() const {
    return name;
}

void TSPData::setName(const string &name) {
    TSPData::name = name;
}

const string &TSPData::getType() const {
    return type;
}

void TSPData::setType(const string &type) {
    TSPData::type = type;
}

int TSPData::getDimension() const {
    return dimension;
}

void TSPData::setDimension(int dimension) {
    TSPData::dimension = dimension;
}

int **TSPData::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

void TSPData::setAdjacencyMatrix(int **adjacencyMatrix) {
    TSPData::adjacencyMatrix = adjacencyMatrix;
}

const string &TSPData::getFilePath() const {
    return filePath;
}

void TSPData::setFilePath(const string &filePath) {
    TSPData::filePath = filePath;
}

const string &TSPData::getEdgeWeightType() const {
    return edge_weight_type;
}

void TSPData::setEdgeWeightType(const string &edgeWeightType) {
    edge_weight_type = edgeWeightType;
}

const vector<std::tuple<double, double>> &TSPData::getCoordinates() const {
    return coordinates;
}

void TSPData::setCoordinates(const vector<std::tuple<double, double>> &coordinates) {
    TSPData::coordinates = coordinates;
}
