

#ifndef TESTTASK_GRAPH_H
#define TESTTASK_GRAPH_H

#include <vector>
#include <set>

struct Edge {
    int destination;
    double width;
};

void dfs(int current, int destination, const std::vector<std::vector<Edge>> &adjacencyList, double min_width,
         std::vector<bool> &visited, std::vector<double> &path_widths, std::vector<std::vector<double>> &all_paths,
         double count_min);

double findPossibleWidth(int numCities, int capital, int zodanga, const std::vector<std::vector<Edge>> &adjacencyList);

std::vector<std::vector<Edge>> generateGraph(int numCities, int numRoads);

std::vector<std::vector<Edge>> readGraphFromFile();


#endif //TESTTASK_GRAPH_H
