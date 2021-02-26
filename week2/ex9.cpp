#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, u, v;

    u = 1000000;
    v = 1000000;
    for (int k = 0; k < n; k++) {
        cin >> a >> b;
        if (a < u) u = a;
        if (b < v) v = b;
    }

    cout << u * v << endl;
    return 0;
}
