#include <iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int k = s;
    
    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++];
    }

    int p = 0, q = 0;
    k = s;

    while (p < len1 && q < len2) {
        if (first[p] < second[q]) {
            arr[k++] = first[p++];
        } else {
            arr[k++] = second[q++];
        }
    }

    while (p < len1) {
        arr[k++] = first[p++];
    }

    while (q < len2) {
        arr[k++] = second[q++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int* arr, int s, int e) {
    if (s >= e) return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    mergeSort(arr, 0, 6);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    // https://www.naukri.com/code360/problems/merge-sort_920442

    // Inversion Count Problem
    // https://www.naukri.com/code360/problems/count-inversions_615
}