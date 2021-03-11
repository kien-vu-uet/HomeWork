#include <iostream>

using namespace std;

int Sort(int* a, int n) {
    int pivot = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= 0) continue;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(a[i], a[j]);
                pivot = i+1;
            }
        }
    }
    return pivot;
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p = Sort(a, n);

    if (p > 0) {
        for (int i = 0; i < p; i++){
            for (int j = n - 1; j > i; j--) {
                if (a[j] < 0) break;
                if (a[j] + a[i] == 0) {
                    cout << a[i] << " " << a[j] << endl;
                    break;
                }
            }
        }
    }

    delete []a;
    return 0;
}
