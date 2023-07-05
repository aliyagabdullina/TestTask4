#include "graph.h"
#include "random.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <set>

void dfs(int current, int destination, const std::vector<std::vector<Edge>> &adjacencyList, double min_width,
         std::vector<bool> &visited, std::vector<double> &path_widths, std::vector<std::vector<double>> &all_paths,
         double count_min) {
    visited[current - 1] = true;

    if (current == destination) {
        // Store the path widths
        int count_cur_min = 0;
        for (double width : path_widths) {
            if (width == min_width) {
                count_cur_min++;
            }
        }
        if (count_cur_min >= count_min) {
            // If this path does not satisfy the condition of the problem
            return;
        }
        all_paths.push_back(path_widths);
        visited[current - 1] = false;
        if (!path_widths.empty()) {
            path_widths.pop_back();
        }
        return;
    }

    // Start dfs from current vertex's children
    for (const Edge &edge : adjacencyList[current - 1]) {
        if (!visited[edge.destination - 1]) {
            path_widths.push_back(edge.width);
            dfs(edge.destination, destination, adjacencyList, min_width, visited, path_widths, all_paths, count_min);
        }
    }

    if (!path_widths.empty()) {
        path_widths.pop_back();
    }
}

double findPossibleWidth(int numCities, int capital, int zodanga, const std::vector<std::vector<Edge>> &adjacencyList) {
    std::vector<bool> visited(numCities, false);
    std::vector<double> path_widths;
    std::vector<std::vector<double>> all_paths;

    double r_a = std::numeric_limits<double>::max();

    int count_min = 0;
    // Find the minimum element in the adjacencyList and number of it
    for (const std::vector<Edge> &edges : adjacencyList) {
        for (const Edge &edge : edges) {
            if (edge.width < r_a) {
                r_a = edge.width;
                count_min = 0;
            }
            if (edge.width == r_a) {
                count_min++;
            }
        }
    }

    count_min /= 2;
    // Start dfs
    dfs(capital, zodanga, adjacencyList, r_a, visited, path_widths, all_paths, count_min);

    // Find the minimum width among all paths
    double r = 1e6;
    for (const std::vector<double> &path : all_paths) {
        double path_width = std::numeric_limits<int>::max();
        for (double width : path) {
            if (width < path_width) {
                path_width = width;
            }
        }
        if (path_width < r) {
            r = path_width;
        }
    }

    return r;
}

std::vector<std::vector<Edge>> generateGraph(int numCities, int numRoads) {
    std::set<std::pair<int, int>> generatedRoads; // Set to store generated road pairs
    std::vector<std::vector<Edge>> adjacencyList(numCities);
    std::ofstream outputFile("input.txt");

    outputFile << numCities << " " << numRoads << std::endl;

    // Randomly generate roads and widths and write it to file
    for (int i = 0; i < numRoads; ++i) {
        int city1 = generateRandomInteger(1, numCities);
        int city2 = generateRandomInteger(1, numCities);
        if (city1 > city2) {
            std::swap(city1, city2);
        }
        while (city2 == city1 || generatedRoads.count(std::make_pair(city1, city2))) {
            city1 = generateRandomInteger(1, numCities);
            city2 = generateRandomInteger(1, numCities);
            if (city1 > city2) {
                std::swap(city1, city2);
            }
        }
        double width = generateRandomDouble(1.0, 100.0);

        generatedRoads.insert(std::make_pair(city1, city2)); // Add the generated road pair to the set

        outputFile << city1 << " " << city2 << " " << width << std::endl;

        // Update the adjacency list
        adjacencyList[city1 - 1].push_back({city2, width});
        adjacencyList[city2 - 1].push_back({city1, width});
    }
    outputFile.close();

    return adjacencyList;
}

std::vector<std::vector<Edge>> readGraphFromFile() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

    int numCities, numRoads;
    inputFile >> numCities >> numRoads;

    std::vector<std::vector<Edge>> adjacencyList(numCities);

    for (int i = 0; i < numRoads; ++i) {
        int city1, city2;
        double width;
        inputFile >> city1 >> city2 >> width;

        adjacencyList[city1 - 1].push_back({city2, width});
        adjacencyList[city2 - 1].push_back({city1, width});
    }

    inputFile.close();

    return adjacencyList;
}

