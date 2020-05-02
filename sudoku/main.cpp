#include <iostream>
#include <vector>
#include <ctime>

std::vector<std::vector<int>> board;
int x, y, col, value, tempX, tempY, randCol;

bool check_row() {
    for (int i = 0; i < 9; i++) {
        if (board[x - 1][i] == value) {
            return false;
        }
    }
    return true;
}

bool check_line() {
    for (int i = 0; i < 9; i++) {
        if (board[i][y - 1] == value) {
            return false;
        }
    }
    return true;
}

bool check_square() {
    tempX = (x - 1) / 3;
    tempY = (y - 1) / 3;
    for (int i = tempX * 3; i < tempX * 3 + 3; i++) {
        for (int j = tempY * 3; j < tempY * 3 + 3; j++) {
            if (board[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool is_empty() {
    return board[x - 1][y - 1] == 0;
}

bool checker() {
    return check_row() && check_line() && check_square() && is_empty();
}

void make_move() {
    do {
        x = 0;
        y = 0;
        value = 0;
        while (x >= 10 || x <= 0) {
            std::cout << "Please input row" << std::endl;
            std::cin >> x;
        }
        while (y >= 10 || y <= 0) {
            std::cout << "Please input line" << std::endl;
            std::cin >> y;
        }
        while (value >= 10 || value <= 0) {
            std::cout << "Please input value" << std::endl;
            std::cin >> value;
        }
    } while (!checker());
    board[x - 1][y - 1] = value;
}

bool result() {
    col = 0;
    for (auto &i : board) {
        for (int j : i) {
            if (j != 0) {
                col++;
            } else {
                return false;
            }
        }
    }
    return true;

}

void write_board() {
    std::cout << "  ";
    for (int i = 2; i < 19; i++) {
        if (i % 2 == 0) {
            std::cout << i / 2;
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl << "  ";
    for (int i = 2; i < 19; i++) {
        std::cout << "_";
    }
    std::cout << std::endl;
    for (int i = 2; i < 11; i++) {
        std::cout << i - 1 << "|";
        for (int j = 2; j < 19; j++) {
            if (j % 2 == 0) {
                if (board[i - 2][j / 2 - 1] == 0) {
                    std::cout << ".";
                } else {
                    std::cout << board[i - 2][j / 2 - 1];
                }
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (int i = 2; i < 19; i++) {
        std::cout << "_";
    }
    std::cout << std::endl;
}

void randomize() {
    x = 1 + rand() % 9;
    y = 1 + rand() % 9;
    value = 1 + rand() % 9;
    if (!checker()) {
        randomize();
    }
    board[x - 1][y - 1] = value;
}

void make_board() {
    board.resize(9);
    for (int i = 0; i < 9; i++) board[i].resize(9);
}

int main() {
    srand(clock());
    std::cout << "Hello, World!" << std::endl;
    unsigned int start_time = clock();
    make_board();
    for (int i = 0; i < 40; i++) {
        randomize();
    }
    while (!result()) {
        write_board();
        make_move();
    }
    unsigned int your_time = (clock() - start_time) / 1000;
    std::cout << "Well done, your time: " << your_time << " seconds" << std::endl;
    return 0;
}
