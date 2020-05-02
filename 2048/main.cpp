#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <map>
#include <conio.h>

std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> board_Bool; // true - empty
unsigned int start_Time, your_Time;
int value, score, col_Empty, cell, col_Res;
std::string name;
bool flag;

bool win() { // есть ли клетка >= 2048
    for (auto &i : board) {
        for (int j : i) {
            if (j > 2048) return true;
        }
    }
    return false;
}

void col() { // подсчёт количества пустых клеток
    col_Empty = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board_Bool[i][j]) col_Empty++;
        }
    }
}

bool result() { // проверка существования ходов
    col_Res = 0;
    bool posible = false;
    for (int i = 0; i < 3; i++) { // заполнено ли поле
        for (int j = 0; j < 3; j++) {
            if (!board_Bool[i][j]) col_Res++;
        }
    }
    for (int i = 0; i < 3; i++) { // возможно ли объеденить
        if (board[i][0] == board[i][1] || board[i][2] == board[i][1] || board[0][i] == board[1][i] || board[2][i] == board[1][i]) posible = true;
    }
    return col_Res == 9 && !posible;
}

void left() {
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) { // объедиение ближайших
            if (board_Bool[i][j]) continue;
            if (board[i][j] == board[i][j - 1]) {
                board[i][j - 1] *= 2;
                board[i][j] = 0;
                board_Bool[i][j] = true;
                flag = true;
            }
        }
    }
    for (int i = 0; i < 3; i++) { // объединение через клетку
        if (board_Bool[i][2]) continue;
        if (board_Bool[i][1] && board[i][2] == board[i][0]) {
            board[i][0] *= 2;
            board_Bool[i][2] = true;
            board[i][2] = 0;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++) { // сдвиг
        for (int j = 2; j > 0; j--) {
            if (board_Bool[i][j]) continue;
            if (board_Bool[i][j - 1]) {
                board[i][j - 1] = board[i][j];
                board[i][j] = 0;
                board_Bool[i][j] = true;
                board_Bool[i][j - 1] = false;
                flag = true;
            }
        }
    }
}

void right() {
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) { // объедиение ближайших
            if (board_Bool[i][j]) continue;
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
                board_Bool[i][j - 1] = true;
                flag = true;
            }
        }
    }
    for (int i = 0; i < 3; i++) { // объединение через клетку
        if (board_Bool[i][0]) continue;
        if (board_Bool[i][1] && board[i][2] == board[i][0]) {
            board[i][2] *= 2;
            board_Bool[i][0] = true;
            board[i][0] = 0;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++) { // сдвиг
        for (int j = 0; j < 2; j++) {
            if (board_Bool[i][j]) continue;
            if (board_Bool[i][j + 1]) {
                board[i][j + 1] = board[i][j];
                board[i][j] = 0;
                board_Bool[i][j] = true;
                board_Bool[i][j + 1] = false;
                flag = true;
            }
        }
    }
}

void up() {
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) { // объедиение ближайших
            if (board_Bool[j][i]) continue;
            if (board[j][i] == board[j - 1][i]) {
                board[j - 1][i] *= 2;
                board[j][i] = 0;
                board_Bool[j][i] = true;
                flag = true;
            }
        }
    }
    for (int i = 0; i < 3; i++) { // объединение через клетку
        if (board_Bool[2][i]) continue;
        if (board_Bool[1][i] && board[2][i] == board[0][i]) {
            board[0][i] *= 2;
            board_Bool[2][i] = true;
            board[2][i] = 0;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++) { // сдвиг
        for (int j = 2; j > 0; j--) {
            if (board_Bool[j][i]) continue;
            if (board_Bool[j - 1][i]) {
                board[j - 1][i] = board[j][i];
                board[j][i] = 0;
                board_Bool[j][i] = true;
                board_Bool[j - 1][i] = false;
                flag = true;
            }
        }
    }
}

void down() {
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) { // объедиение ближайших
            if (board_Bool[j][i]) continue;
            if (board[j][i] == board[j - 1][i]) {
                board[j][i] *= 2;
                board[j - 1][i] = 0;
                board_Bool[j - 1][i] = true;
                flag = true;
            }
        }
    }
    for (int i = 0; i < 3; i++) { // объединение через клетку
        if (board_Bool[0][i]) continue;
        if (board_Bool[1][i] && board[2][i] == board[0][i]) {
            board[2][i] *= 2;
            board_Bool[0][i] = true;
            board[0][i] = 0;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++) { // сдвиг
        for (int j = 0; j < 2; j++) {
            if (board_Bool[j][i]) continue;
            if (board_Bool[j + 1][i]) {
                board[j + 1][i] = board[j][i];
                board[j][i] = 0;
                board_Bool[j][i] = true;
                board_Bool[j + 1][i] = false;
                flag = true;
            }
        }
    }
}

void fill() { // появление 2 или 4 на поле
    col();
    value = 1 + rand() % 100 > 32 ? 2 : 4; // P(2) = 66% P(4) = 33%
    cell = 1 + rand() % col_Empty; // генерируем клетку
    for (int i = 0; i < 3; i++) { // ставим сгенерированое значение в сгенерированую клетку
        for (int j = 0; j < 3; j++) {
            if (board_Bool[i][j]) cell--;
            if (cell == 0) {
                board[i][j] = value;
                board_Bool[i][j] = false;
                return;
            }
        }
    }
}

int main() { // работает только в командной строке (бинд клавиш)
    srand(clock());
    start_Time = clock();
    board.resize(3), board_Bool.resize(3);
    for (int i = 0; i < board.size(); i++) {
        board[i].resize(3);
        board_Bool[i].resize(3);
    }
    for (auto &i : board_Bool) {
        for (auto &&j : i) {
            j = true;
        }
    }
    do {
        fill();
        for (auto &i : board) { // выводим поле
            for (auto &&j : i) {
                std::cout << std::setw(5) << j;
            }
            std::cout << std::endl;
        }
        hello:
        flag = false;
        if (kbhit()) { // если на клаву нажали
            switch (getch()) { // на какую клавишу нажали
                case 75:
                    left();
                    left();
                    break;
                case 77:
                    right();
                    right();
                    break;
                case 72:
                    up();
                    up();
                    break;
                case 80:
                    down();
                    down();
                    break;
                default:
                    goto hello;
            }
        }
        if (!flag && !result()) goto hello;
        std::cout << std::endl;
    } while (!result());
    for (auto &i : board) {
        for (int j : i) {
            score += j;
        }
    }
    your_Time = (clock() - start_Time) / 1000;
    std::cout << "your time: " << your_Time << " seconds!\n" << "your score: " << score << " points!";
    std::ofstream out(R"(C:\Users\2000a\CLionProjects\game2048\record.out)", std::ios::app);
    if (out.is_open()) {
        std::cout << std::endl << "What is your name?" << std::endl;
        std::cin >> name;
        out << std::setw(20) << your_Time << std::setw(20) << score << std::setw(7) << win() << std::setw(20) << name
            << std::endl;
    }
    return 0;
}