#include <iostream>

using namespace std;

int binSortByRecursive(int* arr, int N, int low, int high, int key) {
    if (low > high || key > arr[N-1] || key < arr[0])
        return -1;
    else{
        int pivot = (low + high) / 2;
        if (key == arr[pivot])
            return pivot;
        else if (key > arr[pivot])
            return binSortByRecursive(arr, N, pivot + 1, high, key);
        else
            return binSortByRecursive(arr, N, 0, pivot - 1, key);
    }
}

int binSortByLoops(int* arr, int N, int key) {
    if (key > arr[N-1] || key < arr[0])
        return -1;
    int low = 0, high = N -1;
    while (low <= high) {
        int pivot = (low + high)  / 2;
        if (key == arr[pivot]) return pivot;
        else if (key > arr[pivot]) low = pivot + 1;
        else high = pivot - 1;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    if (binSortByRecursive(arr, N, 0, N - 1, key) == -1) cout << "false key" << endl;
    else cout << binSortByRecursive(arr, N, 0, N - 1, key) << endl;

    cout << "-----------------" << endl;

    if (binSortByLoops(arr, N, key) == -1) cout << "false key" << endl;
    else cout << binSortByLoops(arr, N, key) << endl;

    delete[] arr;
    return 0;
}
