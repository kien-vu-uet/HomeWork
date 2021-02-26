#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    cout << a << " ";
    while (cin >> b) {
        if (a == b) continue;
        if (b < 0) break;
        cout << b << " ";
        a = b;
    }

    return 0;
}
