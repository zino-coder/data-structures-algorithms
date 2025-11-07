#include <numbers>
#include <bits/stdc++.h>

// Ham tim pivot va phan chia mang
int partition(std::vector<int> &arr, int low, int high) {
    // Chon pivot la phan tu cuoi cung
    const int pivot = arr[high];
    // index cua phan tu nho hon
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Neu gia tri be hon pivot thi tang index
        if (arr[j] <= pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    // dat pivot vao vi tri
    std::swap(arr[i+1], arr[high]);

    return i + 1;
}

// Ham quick sort de quy
void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        const int pi = partition(arr, low, high);

        // Sap xep de quy cac phan tu sau chia
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, n - 1);
    printArray(arr, n);
}
