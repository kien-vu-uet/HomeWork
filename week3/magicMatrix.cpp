#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<int> array1D;
typedef vector<array1D> array2D;

int main() {
    int N;
    cin >> N;

    array2D matrix(N,array1D(N,0));

    int x = 0;
    int y = N / 2;

    for (int i = 1; i <= N*N; i++) {
        matrix[x][y] = i;

        if (x == 0 && y == N-1) x++;

        else {
            if (x == 0) x = N-1;
            else x--;

            if (y == N-1) y = 0;
            else y++;
        }

        if (matrix[x][y] != 0) {
            x += 2;
            y -= 1;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
