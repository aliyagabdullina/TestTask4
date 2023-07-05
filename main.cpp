#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <set>
#include "graph.h"
#include "random.h"

using namespace std;

void test() {
    // Generate test input and write to a file

    std::cout << "If you want to generate graph randomly, please press R, if you want to test your data, put them into input.txt file and press I" << std::endl;
    char k;
    std::cin>>k;
    int numCities, numRoads;
    vector<vector<Edge>> adjacencyList;
    if(k == 'R'){
        std::cout << "Please write the number of cities and the number of roads" << endl;
        std::cin >> numCities >> numRoads;
        adjacencyList = generateGraph(numCities, numRoads);
    } else{
        std::ifstream inputFile("input.txt");
        inputFile >> numCities >> numRoads;
        inputFile.close();

         adjacencyList = readGraphFromFile();

    }

    // Randomly select the Capital and Zodanga cities
    int capital = generateRandomInteger(1, numCities);
    int zodanga = generateRandomInteger(1, numCities);
    while (zodanga == capital) {
        zodanga = generateRandomInteger(1, numCities);
    }

    // Find the possible width for Armata
    double possibleWidth = findPossibleWidth(numCities, capital, zodanga, adjacencyList);

    cout << "Capital: " << capital << endl;
    cout << "Zodanga: " << zodanga << endl;
    if (possibleWidth == 1e6) {
        cout << "No paths between Capital and Zodanga" << endl;
    } else {
        cout << "Maximal possible width for Armata: " << possibleWidth << endl;
    }
}

int main() {

    // Run the test
    test();

    return 0;
}
