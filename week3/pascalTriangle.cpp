#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    int** pas = new int*[n];
    for (int i = 0; i < n; i++){
        pas[i] = new int[i+1];
        for (int j = 0 ; j <= i; j++) {
            if (j == 0 || j == i) pas[i][j] = 1;
            else pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
            cout << setw(4) << pas[i][j] << " ";
        }
        cout << endl;
    }
    delete []pas;
    return 0;
}
