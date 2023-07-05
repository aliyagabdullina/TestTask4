#include "random.h"
#include <random>

int generateRandomInteger(int min_value, int max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_value, max_value);
    return distrib(gen);
}

double generateRandomDouble(double min_value, double max_value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(min_value, max_value);
    return distrib(gen);
}
