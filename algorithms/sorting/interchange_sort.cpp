#include <bits/stdc++.h>

void interchangeSort(std::vector<int> &arr, const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                const int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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
    interchangeSort(arr, n);
    printArray(arr, n);
}