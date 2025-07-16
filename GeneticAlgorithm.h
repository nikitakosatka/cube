#ifndef RUBIKS_CUBE_GENETICALGORITHM_H
#define RUBIKS_CUBE_GENETICALGORITHM_H

#include "Cube.h"

class Solver {
private:
    int _populationSize, _maxGenerations, _maxResets, _elitismNum;

public:
    explicit Solver(int populationSize = 500, int maxGenerations = 300, int maxResets = 10, int elitismNum = 50)
            : _populationSize(populationSize), _maxGenerations(maxGenerations), _maxResets(maxResets),
              _elitismNum(elitismNum) {};

    std::string solve(const Cube& cube);
};

#endif
