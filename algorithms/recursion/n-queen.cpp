#include <iomanip>
#include <iostream>
#include <vector>

int solutionCount = 0;

bool isSafeQueen(const std::vector<std::vector<bool>> &board, const int row, const int col, const int n) {
    // Kiem tra cot
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Kiem tra duong cheo tren
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Kiem tra duong cheo duoi
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void printSolution(const std::vector<std::vector<bool>> &board) {
    std::cout << "Phuong phap thu: " << ++solutionCount << std::endl;

    for (const auto &col : board) {
        for (const auto &cell : col) {
            if (cell) {
                std::cout << " " << 'x' << " ";
            } else {
                std::cout << " " << '.' << " ";
            }
        }

        std::cout << std::endl;
    }

    std::cout << "----------------------------------------------" << std::endl;
}

bool solveQueens(std::vector<std::vector<bool>> &board, const int row, const int n) {
    if (row == n) {
        printSolution(board);

        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < n; col++) {
        if (isSafeQueen(board, row, col, n)) {
            // Dat quan hau tai vi tri moi
            board[row][col] = true;

            // De quy
            foundSolution = solveQueens(board, row + 1, n) || foundSolution;
            board[row][col] = false;
        }
    }

    return foundSolution;
}

int main(int argc, char *argv[]) {
    int n;
    std::cout << "Nhap do lon cua ban co: ";
    std::cin >> n;

    // Khởi tạo bàn cờ:
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n, false));
    if (solveQueens(board, 0, n)) {
        std::cout << "Co tat ca " << solutionCount << " phuong phap cho ban co " << n << " x " << n << std::endl;
    } else {
        if (!solutionCount) {
            std::cout << "Khong co giai phap nao!";
        }
    }
}
