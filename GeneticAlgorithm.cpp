#include "GeneticAlgorithm.h"
#include <iostream>

std::string Solver::solve(const Cube& cube) {
    std::vector<Cube*> cubesPtrs;
    std::vector<Cube> cubes;

    size_t scrambleMoves = cube.getMoves().size();

    for (int r = 0; r < _maxResets; r++) {
        for (int i = 0; i < _populationSize; i++) {
            Cube cube1(cube);

            cube1.randomSingleMove();
            cube1.randomSingleMove();

            cubes.push_back(cube1);
        }
    }

    for (auto & c : cubes) {
        cubesPtrs.push_back(&c);
    }

    for (int g = 0; g < _maxGenerations; g++) {
        for (int i = 0; i < cubesPtrs.size(); ++i) {
            cubesPtrs[i]->generateFitness();
        }
        std::sort(cubesPtrs.begin(), cubesPtrs.end(), [](Cube* a, Cube* b) {return a->getFitness() < b->getFitness();});

        for (int i = 0; i < cubesPtrs.size(); i++) {
            if (cubesPtrs[i]->getFitness() == 0) {
                std::string solutuion = "";

                for (size_t j = scrambleMoves; j < cubesPtrs[i]->getMoves().size(); j++) {
                    solutuion += cubesPtrs[i]->getMoves()[j] + " ";
                }
                return "Solution found: " + solutuion;
            }

            if (i > _elitismNum) {
                int elite = rand() % _elitismNum;
                cubesPtrs[i]->setMoves(cubesPtrs[elite]->getMoves());
                cubesPtrs[i]->setSides(cubesPtrs[elite]->getSides());
                int evolutionType = rand() % 6;


                switch (evolutionType) {
                    case 0:
                        cubesPtrs[i]->randomPermutation();
                        break;

                    case 1:
                        cubesPtrs[i]->randomPermutation();
                        cubesPtrs[i]->randomPermutation();
                        break;

                    case 2:
                        cubesPtrs[i]->randomFullRotation();
                        cubesPtrs[i]->randomPermutation();
                        break;

                    case 3:
                        cubesPtrs[i]->randomOrientation();
                        cubesPtrs[i]->randomPermutation();
                        break;

                    case 4:
                        cubesPtrs[i]->randomFullRotation();
                        cubesPtrs[i]->randomPermutation();
                        cubesPtrs[i]->randomOrientation();
                        break;

                    case 5:
                        cubesPtrs[i]->randomOrientation();
                        cubesPtrs[i]->randomFullRotation();
                        cubesPtrs[i]->randomPermutation();
                        break;

                    default:
                        break;
                }
            }
        }
    }

    return "Solution not found";
}
