// Rotation a matrix 90 degree clockwise

#include <bits/stdc++.h>

void printMatrix(const std::vector<std::vector<int> > &matrix) {
    for (const auto &row: matrix) {
        for (const auto &cell: row) {
            std::cout << std::setw(3) << cell;
        }

        std::cout << std::endl;
    }
}

// Rotate the matrix 90 degree
std::vector<std::vector<int> > rotateMatrix(const std::vector<std::vector<int> > &matrix, int m, int n) {
    if (matrix.empty()) {
        return {};
    }

    std::vector<std::vector<int> > rotatedMatrix(n, std::vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Xoay theo chieu kim dong ho
            int newRow = j;
            int newCol = m - i - 1;

            // Xoay nguoc chieu kim dong ho
            // int new_row = n - j - 1;
            // int new_col = i;

            // Gan gia tri cho row moi
            rotatedMatrix[newRow][newCol] = matrix[i][j];
        }
    }

    return rotatedMatrix;
}

// Init the matrix
void initMatrix(std::vector<std::vector<int> > &matrix, int &m, int &n) {
    std::cout << "Input number of rows: ";
    std::cin >> m;

    std::cout << "Input number of cols: ";
    std::cin >> n;
    std::cout << "========================================" << std::endl;

    matrix.resize(m, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "a[" << i << "][" << j << "]= ";
            std::cin >> matrix[i][j];
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int> > matrix;
    int m, n;

    initMatrix(matrix, m, n);
    printMatrix(matrix);

    std::cout << "Mang sau khi xoay 90 do la: " << std::endl;
    std::vector<std::vector<int> > rotatedMatrix = rotateMatrix(matrix, m, n);
    printMatrix(rotatedMatrix);

    return 0;
}
