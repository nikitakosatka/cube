#include "utils.h"

void rotateMatrix(std::vector<std::vector<char>> &matrix) {
    reverse(matrix.begin(), matrix.end());

    size_t size = matrix.size();

    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

std::vector<std::string> generateScramble() {
    std::vector<int> scramble{rand() % 6};
    std::vector<std::string> scrambleMoves;

    for (int i = 1; i < SCRAMBLE_COUNT; i++) {
        int move;
        for (move = rand() % 6; move == scramble.back(); move = rand() % 6);

        scramble.push_back(move);
    }


    for (int i = 0; i < SCRAMBLE_COUNT; i++) {
        scrambleMoves.push_back(SINGLE_MOVES[scramble[i] * 3 + rand() % 3]);
    }

    return scrambleMoves;
}
