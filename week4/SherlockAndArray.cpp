#include <iostream>

using namespace std;

string check(int* a, int* sum, int N) {
    if (sum[N - 1] - sum[1] == 0 || sum[N - 2] == 0) return "YES";
    for (int i = 1; i < N; i ++) {
        if (sum[i - 1] == sum[N - 1] - sum[i])
            return "YES";
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int* a = new int[N];
        int* sum = new int[N];
        cin >> a[0]; sum[0] = a[0];
        for (int i = 1; i < N; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }

        cout <<check(a, sum, N) << endl;

        delete []a;
        delete []sum;
    }
}
