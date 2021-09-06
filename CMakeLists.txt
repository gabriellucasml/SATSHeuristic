cmake_minimum_required(VERSION 3.20)
project(TSP)

set(CMAKE_CXX_STANDARD 23)

add_executable(TSP main.cpp TSPData.cpp TSPData.h SATSHeuristic.cpp SATSHeuristic.h)
