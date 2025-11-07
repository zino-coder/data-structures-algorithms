#include <bits/stdc++.h>

void merge(std::vector<int> &arr, const int l, const int m, const int r) {
    const int n1 = m + 1 - l;
    const int n2 = r - m;

    // Mang tam
    std::vector<int> L(n1, 0);
    std::vector<int> R(n2, 0);

    // Sao chep du lieu
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    // Mix L với R
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Sao chep phan du cua L
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Sao chep phan du cua R
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Ham merge sort de quy
void mergeSort(std::vector<int> &arr, const int l, const int r) {
    if (l < r) {
        // Tim vi tri o giua
        const int m = l + (r - l) / 2;

        // Sap xep nua dau va sau
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}
