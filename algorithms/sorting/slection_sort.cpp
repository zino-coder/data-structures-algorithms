#include <bits/stdc++.h>

void selectionSort(std::vector<int> &arr, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }

            std::swap(arr[i], arr[min]);
        }
    }
}

void printArray(const std::vector<int> &arr, const int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void initArray(std::vector<int> &arr, int &n) {
    std::cout << "Input n=";
    std::cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "]=";
        std::cin >> arr[i];
    }
}

int main() {
    int n;
    std::vector<int> arr;

    initArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
}