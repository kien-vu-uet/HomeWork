#include <iostream>

using namespace std;

void Sort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= 0) continue;
        for (int j = i + 1; j < n; j++) {
            if (a[j] * a[i] <= 0) swap(a[i], a[j]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Sort(a, n);

    for (int i = 0; i < n - 2; i++){
        for (int k = i + 1; k < n - 1; k++){
            for (int j = n - 1; j > k; j--) {
                if (a[j] + a[i] + a[k] == 0) {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                    break;
                }
            }
        }
    }

    delete []a;
    return 0;
}
