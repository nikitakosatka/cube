#ifndef RUBIKS_CUBE_CUBE_H
#define RUBIKS_CUBE_CUBE_H

#include <utility>
#include <vector>
#include <map>
#include <string>
#include <ostream>
#include <functional>

#include "utils.h"

class Cube {
private:
    std::map<int, std::vector<std::vector<char>>> sides;

    std::vector<std::string> moves;

    int _fitness;

public:
    Cube();

    Cube(const Cube &other) = default;

    Cube &operator=(const Cube &other);

    bool operator<(const Cube &other) const;

    std::map<int, std::vector<std::vector<char>>> getSides() const;

    std::vector<std::string> getMoves() const;

    int getFitness() const;

    void setSides(std::map<int, std::vector<std::vector<char>>> newSides);

    void setMoves(std::vector<std::string> newMoves);

    void right();

    void left();

    void front();

    void back();

    void top();

    void bottom();

    void xRotate();

    void yRotate();

    void zRotate();

    void middle();

    void randomSingleMove();

    void randomPermutation();

    void randomFullRotation();

    void randomOrientation();

    void generateFitness();

    void rotate(const std::string &move);

    void correctLastMove();
};

std::ostream &operator<<(std::ostream &out, const Cube &cube);

#endif
