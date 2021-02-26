#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int k = 1;
    for (int i = 0; i < n/2 ; i++){
        for (int j = 1; j <= n; j++) {
            if (i + j == n) cout << n << " ";
            else cout << (i + j) % n << " ";
        }
        cout << endl;
    }

    return 0 ;
}
