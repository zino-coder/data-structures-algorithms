#include <bits/stdc++.h>

void insertionSort(std::vector<int> &arr, const int n) {
    for (int i = 0; i < n; i++) {
        const int min = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > min) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = min;
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
    insertionSort(arr, n);
    printArray(arr, n);
}