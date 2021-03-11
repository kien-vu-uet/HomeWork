#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N,1);

    for (int i = 2; i <= trunc(sqrt(N)); i++) {
            int j = 2;
            while (i * j <= N) {
                arr[i * j - 1] = 0;
                j++;
            }
    }

    for (int i = 2; i < N; i++) {
        if (arr[i - 1] != 0) cout << i << " ";
    }


    return 0;
}
