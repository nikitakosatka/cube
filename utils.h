#ifndef RUBIKS_CUBE_UTILS_H
#define RUBIKS_CUBE_UTILS_H

#include <vector>
#include <string>

const int LAYERS_NUMBER = 3;

const int SCRAMBLE_COUNT = 20;

enum SIDES {
    FRONT,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    BACK
};

const std::vector<std::vector<std::string>> PERMUTATIONS = {
        {"F'", "L'", "B'", "R'", "U'", "R", "U'", "B", "L", "F", "R", "U", "R'", "U"},
        {"F", "R", "B", "L", "U", "L'", "U", "B'", "R'", "F'", "L'", "U'", "L", "U'"},
        {"U2", "B", "U2", "B'", "R2", "F", "R'", "F'", "U2", "F'", "U2", "F", "R'"},
        {"U2", "R", "U2", "R'", "F2", "L", "F'", "L'", "U2", "L'", "U2", "L", "F'"},
        {"U'", "B2", "D2", "L'", "F2", "D2", "B2", "R'", "U'"},
        {"U", "B2", "D2", "R", "F2", "D2", "B2", "L", "U"},
        {"D'", "R'", "D", "R2", "U'", "R", "B2", "L", "U'", "L'", "B2", "U", "R2"},
        {"D", "L", "D'", "L2", "U", "L'", "B2", "R'", "U", "R", "B2", "U'", "L2"},
        {"R'", "U", "L'", "U2", "R", "U'", "L", "R'", "U", "L'", "U2", "R", "U'", "L", "U'"},
        {"L", "U'", "R", "U2", "L'", "U", "R'", "L", "U'", "R", "U2", "L'", "U", "R'", "U"},
        {"F'", "U", "B", "U'", "F", "U", "B'", "U'"},
        {"F", "U'", "B'", "U", "F'", "U'", "B", "U"},
        {"L'", "U2", "L", "R'", "F2", "R"},
        {"R'", "U2", "R", "L'", "B2", "L"},
        {"M2", "U", "M2", "U2", "M2", "U", "M2"}
};

const std::vector<std::string> ORIENTATIONS = {"z", "z'", "z2"};

const std::vector<std::string> FULL_ROTATIONS = {"x", "x'", "x2", "y", "y'", "y2"};

const std::vector<std::string> SINGLE_MOVES = {"F", "F2", "F'", "R", "R2", "R'", "U", "U2", "U'", "B", "B2", "B'", "L",
                                               "L2", "L'", "D", "D2", "D'"};

void rotateMatrix(std::vector<std::vector<char>> &matrix);

std::vector<std::string> generateScramble();

#endif
