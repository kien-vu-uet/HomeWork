#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    int* a = new int[10];
    for (int i = 0; i < 10; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[m] ++;
    }

    cout << "number    | ";
    for (int i = 0; i < 10; i++) cout << i << " | " ;
    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "frequency | ";

    for (int i = 0; i < 10; i++ ) {
        cout << a[i] << " | ";
    }

    delete []a;
    return 0;
}
