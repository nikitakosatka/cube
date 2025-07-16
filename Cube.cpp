#include "Cube.h"

Cube::Cube() {
    sides = {
            {FRONT, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'G'))},
            {LEFT, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'O'))},
            {RIGHT, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'R'))},
            {TOP, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'W'))},
            {BOTTOM, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'Y'))},
            {BACK, std::vector<std::vector<char>>(LAYERS_NUMBER, std::vector<char>(LAYERS_NUMBER, 'B'))},
    };

    _fitness = 0;
}

Cube &Cube::operator=(const Cube &other) {
    sides = std::map<int, std::vector<std::vector<char>>>(other.sides);
    moves = other.moves;
    _fitness = other._fitness;

    return *this;
}

bool Cube::operator<(const Cube &other) const {
    return getFitness() < other.getFitness();
}

std::map<int, std::vector<std::vector<char>>> Cube::getSides() const {
    return sides;
}

void Cube::right() {
    rotateMatrix(sides[RIGHT]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[FRONT][i][2];
        tmpColor2 = sides[TOP][i][2];
        sides[TOP][i][2] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BACK][LAYERS_NUMBER - (i + 1)][0];
        sides[BACK][LAYERS_NUMBER - (i + 1)][0] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BOTTOM][i][2];
        sides[BOTTOM][i][2] = tmpColor1;

        sides[FRONT][i][2] = tmpColor2;
    }
}

void Cube::left() {
    rotateMatrix(sides[LEFT]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[FRONT][i][0];
        tmpColor2 = sides[BOTTOM][i][0];
        sides[BOTTOM][i][0] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BACK][LAYERS_NUMBER - (i + 1)][2];
        sides[BACK][LAYERS_NUMBER - (i + 1)][2] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[TOP][i][0];
        sides[TOP][i][0] = tmpColor1;

        sides[FRONT][i][0] = tmpColor2;
    }
}

void Cube::front() {
    rotateMatrix(sides[FRONT]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[LEFT][LAYERS_NUMBER - (i + 1)][2];
        tmpColor2 = sides[TOP][2][i];
        sides[TOP][2][i] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[RIGHT][i][0];
        sides[RIGHT][i][0] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BOTTOM][0][LAYERS_NUMBER - (i + 1)];
        sides[BOTTOM][0][LAYERS_NUMBER - (i + 1)] = tmpColor1;

        sides[LEFT][LAYERS_NUMBER - (i + 1)][2] = tmpColor2;
    }
}

void Cube::back() {
    rotateMatrix(sides[BACK]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[RIGHT][LAYERS_NUMBER - (i + 1)][2];
        tmpColor2 = sides[TOP][0][LAYERS_NUMBER - (i + 1)];
        sides[TOP][0][LAYERS_NUMBER - (i + 1)] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[LEFT][i][0];
        sides[LEFT][i][0] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BOTTOM][2][i];
        sides[BOTTOM][2][i] = tmpColor1;

        sides[RIGHT][LAYERS_NUMBER - (i + 1)][2] = tmpColor2;
    }
}

void Cube::top() {
    rotateMatrix(sides[TOP]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[LEFT][0][i];
        tmpColor2 = sides[BACK][0][i];
        sides[BACK][0][i] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[RIGHT][0][i];
        sides[RIGHT][0][i] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[FRONT][0][i];
        sides[FRONT][0][i] = tmpColor1;

        sides[LEFT][0][i] = tmpColor2;
    }
}

void Cube::bottom() {
    rotateMatrix(sides[BOTTOM]);

    char tmpColor1, tmpColor2;

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        tmpColor1 = sides[LEFT][2][i];
        tmpColor2 = sides[FRONT][2][i];
        sides[FRONT][2][i] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[RIGHT][2][i];
        sides[RIGHT][2][i] = tmpColor1;

        tmpColor1 = tmpColor2;
        tmpColor2 = sides[BACK][2][i];
        sides[BACK][2][i] = tmpColor1;

        sides[LEFT][2][i] = tmpColor2;
    }
}

void Cube::xRotate() {
    rotateMatrix(sides[RIGHT]);

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        rotateMatrix(sides[LEFT]);
    }

    std::vector<std::vector<char>> tmpSide1(sides[FRONT]);
    std::vector<std::vector<char>> tmpSide2(sides[TOP]);
    sides[TOP] = std::vector<std::vector<char>>(tmpSide1);

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[BACK]);
    sides[BACK] = std::vector<std::vector<char>>(tmpSide1);
    for (int i = 0; i < 2; i++) {
        rotateMatrix(sides[BACK]);
    }

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[BOTTOM]);
    sides[BOTTOM] = std::vector<std::vector<char>>(tmpSide1);
    for (int i = 0; i < 2; i++) {
        rotateMatrix(sides[BOTTOM]);
    }

    sides[FRONT] = std::vector<std::vector<char>>(tmpSide2);
}

void Cube::yRotate() {
    rotateMatrix(sides[TOP]);

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        rotateMatrix(sides[BOTTOM]);
    }

    std::vector<std::vector<char>> tmpSide1(sides[FRONT]);
    std::vector<std::vector<char>> tmpSide2(sides[LEFT]);
    sides[LEFT] = std::vector<std::vector<char>>(tmpSide1);

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[BACK]);
    sides[BACK] = std::vector<std::vector<char>>(tmpSide1);

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[RIGHT]);
    sides[RIGHT] = std::vector<std::vector<char>>(tmpSide1);

    sides[FRONT] = std::vector<std::vector<char>>(tmpSide2);
}

void Cube::zRotate() {
    rotateMatrix(sides[FRONT]);

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        rotateMatrix(sides[BACK]);
    }

    std::vector<std::vector<char>> tmpSide1(sides[TOP]);
    std::vector<std::vector<char>> tmpSide2(sides[RIGHT]);
    sides[RIGHT] = std::vector<std::vector<char>>(tmpSide1);
    rotateMatrix(sides[RIGHT]);

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[BOTTOM]);
    sides[BOTTOM] = std::vector<std::vector<char>>(tmpSide1);
    rotateMatrix(sides[BOTTOM]);

    tmpSide1 = std::vector<std::vector<char>>(tmpSide2);
    tmpSide2 = std::vector<std::vector<char>>(sides[LEFT]);
    sides[LEFT] = std::vector<std::vector<char>>(tmpSide1);
    rotateMatrix(sides[LEFT]);

    sides[TOP] = std::vector<std::vector<char>>(tmpSide2);
    rotateMatrix(sides[TOP]);
}

void Cube::middle() {
    for (int i = 0; i < LAYERS_NUMBER; i++) {
        xRotate();
        left();
    }

    right();
}

int Cube::getFitness() const {
    return _fitness;
}

void Cube::generateFitness() {
    int fitness = 0;

    for (auto &side: sides) {
        char center = side.second[1][1];

        for (int i = 0; i < LAYERS_NUMBER; i++) {
            for (int j = 0; j < LAYERS_NUMBER; j++) {
                if (side.second[i][j] != center) {
                    fitness++;
                }
            }
        }
    }

    _fitness = fitness;
}

void Cube::randomSingleMove() {
    rotate(SINGLE_MOVES[rand() % SINGLE_MOVES.size()]);
}

void Cube::randomPermutation() {
    int r = rand() % PERMUTATIONS.size();

    std::vector<std::string> permutations = PERMUTATIONS[r];

    for (auto &permutation: permutations) {
        rotate(permutation);
    }
}

void Cube::randomFullRotation() {
    rotate(FULL_ROTATIONS[rand() % FULL_ROTATIONS.size()]);
}

void Cube::randomOrientation() {
    rotate(ORIENTATIONS[rand() % ORIENTATIONS.size()]);
}

std::vector<std::string> Cube::getMoves() const {
    return moves;
}

void Cube::rotate(const std::string &move) {
    moves.push_back(move);
    correctLastMove();

    if (move == "F") {
        front();
    } else if (move == "F'") {
        for (int i = 0; i < 3; i++) {
            front();
        }
    } else if (move == "F2") {
        for (int i = 0; i < 2; i++) {
            front();
        }
    } else if (move == "R") {
        right();
    } else if (move == "R'") {
        for (int i = 0; i < 3; i++) {
            right();
        }
    } else if (move == "R2") {
        for (int i = 0; i < 2; i++) {
            right();
        }
    } else if (move == "U") {
        top();
    } else if (move == "U'") {
        for (int i = 0; i < 3; i++) {
            top();
        }
    } else if (move == "U2") {
        for (int i = 0; i < 2; i++) {
            top();
        }
    } else if (move == "B") {
        back();
    } else if (move == "B'") {
        for (int i = 0; i < 3; i++) {
            back();
        }
    } else if (move == "B2") {
        for (int i = 0; i < 2; i++) {
            back();
        }
    } else if (move == "L") {
        left();
    } else if (move == "L'") {
        for (int i = 0; i < 3; i++) {
            left();
        }
    } else if (move == "L2") {
        for (int i = 0; i < 2; i++) {
            left();
        }
    } else if (move == "D") {
        bottom();
    } else if (move == "D'") {
        for (int i = 0; i < 3; i++) {
            bottom();
        }
    } else if (move == "D2") {
        for (int i = 0; i < 2; i++) {
            bottom();
        }
    } else if (move == "x") {
        xRotate();
    } else if (move == "x'") {
        for (int i = 0; i < 3; i++) {
            xRotate();
        }
    } else if (move == "x2") {
        for (int i = 0; i < 2; i++) {
            xRotate();
        }
    } else if (move == "y") {
        yRotate();
    } else if (move == "y'") {
        for (int i = 0; i < 3; i++) {
            yRotate();
        }
    } else if (move == "y2") {
        for (int i = 0; i < 2; i++) {
            yRotate();
        }
    } else if (move == "z") {
        zRotate();
    } else if (move == "z'") {
        for (int i = 0; i < 3; i++) {
            zRotate();
        }
    } else if (move == "z2") {
        for (int i = 0; i < 2; i++) {
            zRotate();
        }
    } else if (move == "M") {
        middle();
    } else if (move == "M'") {
        for (int i = 0; i < 3; i++) {
            middle();
        }
    } else if (move == "M2") {
        for (int i = 0; i < 2; i++) {
            middle();
        }
    }
}

void Cube::correctLastMove() {
    size_t size = moves.size();

    if (size == 1) {
        return;
    }

    if (moves[size - 2] == moves.back()) {
        if (moves[size - 1].back() == '2'){
            moves.pop_back();
            moves.pop_back();
        } else {
            moves.pop_back();
            moves[size - 2] = std::string(1, moves[size - 2][0]) + "2";
        }
    } else if (moves[size - 2][0] == moves.back()[0]) {
        if (moves[size - 1].size() == 1 && moves[size - 2].back() == '\'' || moves[size - 2].size() == 1 && moves[size - 1].back() == '\'') {
            moves.pop_back();
            moves.pop_back();
        } else if (moves[size - 1].size() == 1 && moves[size - 2].back() == '2' || moves[size - 2].size() == 1 && moves[size - 1].back() == '2') {
            moves.pop_back();
            moves[size - 2] = std::string(1, moves[size - 2][0]) + "'";
        } else if (moves[size - 1].back() == '\'' && moves[size - 1].back() == '2' || moves[size - 1].back() == '2' && moves[size - 1].back() == '\'') {
            moves.pop_back();
            moves[size - 2] = std::string(1, moves[size - 2][0]);
        }
    }
}

void Cube::setMoves(std::vector<std::string> newMoves) {
    moves = std::move(newMoves);
}

void Cube::setSides(std::map<int, std::vector<std::vector<char>>> newSides) {
    sides = std::move(newSides);
}

std::ostream &operator<<(std::ostream &out, const Cube &cube) {
    for (int i = 0; i < LAYERS_NUMBER; i++) {
        out << "         ";

        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[TOP][i][j] << "  ";
        }

        out << "\n";
    }

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[LEFT][i][j] << "  ";
        }
        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[FRONT][i][j] << "  ";
        }
        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[RIGHT][i][j] << "  ";
        }
        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[BACK][i][j] << "  ";
        }
        out << '\n';
    }

    for (int i = 0; i < LAYERS_NUMBER; i++) {
        out << "         ";

        for (int j = 0; j < LAYERS_NUMBER; j++) {
            out << cube.getSides()[BOTTOM][i][j] << "  ";
        }

        out << std::endl;
    }

    return out;
}
