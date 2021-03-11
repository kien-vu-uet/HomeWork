#include <iostream>

using namespace std;

void findNum(int* a, int N, int num, int pos, int step);

int main() {
    int N;
    cin >> N;
    int *a = new int[N];
    double mean = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) swap(a[i], a[j]);
        }
        mean += a[i];
    }
    mean = mean / N;
    for (int i = 0; i < N + 1; i++){
        int m;
        cin >> m;
        if (m > mean) findNum(a, N, m, N - 1, -1);
        else findNum(a, N, m, 0, 1);
    }
    delete []a;
    return 0;
}

void findNum(int* a, int N, int num, int pos, int step){
    while (a[pos] != num) {
        pos += step;
        if (pos < 0 || pos >= N) {
            cout << num;
            break;
        }
    }
}
