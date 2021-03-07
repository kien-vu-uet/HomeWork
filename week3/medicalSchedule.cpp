#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* time = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (time[j] < time[i]) {
                int temp = time[i];
                time[i] = time[j];
                time[j] = temp;
            }
        }
    }

    int res = 0;
    for (int i = 1; i < N; i++) {
        res += time[i-1] * (N-i);
    }

    cout << res << endl;
    delete []time;
    return 0;

}
