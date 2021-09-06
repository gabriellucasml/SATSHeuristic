//
// Created by Gabriel on 29/08/2021.
//
#include <iostream>
#include <vector>
#include <tuple>

#ifndef TSP_TSPDATA_H
#define TSP_TSPDATA_H


class TSPData {
private:
    std::string filePath;
    std::string name;
    std::string type;
    std::string edge_weight_type;
    std::vector<std::tuple<double, double>> coordinates;
    int dimension;
    int** adjacencyMatrix;
public:
    TSPData(const std::string& filePath);

    int **getAdjacencyMatrix() const;

    void setAdjacencyMatrix(int **adjacencyMatrix);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getType() const;

    void setType(const std::string &type);

    int getDimension() const;

    void setDimension(int dimension);

    const std::string &getFilePath() const;

    void setFilePath(const std::string &filePath);

    const std::string &getEdgeWeightType() const;

    void setEdgeWeightType(const std::string &edgeWeightType);

    const std::vector<std::tuple<double, double>> &getCoordinates() const;

    void setCoordinates(const std::vector<std::tuple<double, double>> &coordinates);
};


#endif //TSP_TSPDATA_H
