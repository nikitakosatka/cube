#include <iostream>
#include <ctime>

#include "GeneticAlgorithm.h"

using namespace ;

int main() {
    srand(time(nullptr));

    Solver s;

    Cube cube;

    std::vector<std::string> scramble = generateScramble();

    for (std::string &p: scramble) {
        std::cout << p << " ";
        cube.rotate(p);
    }
    std::cout << std::endl;

    std::cout << cube << std::endl;

    std::cout << s.solve(cube) << std::endl;

    return 0;
}