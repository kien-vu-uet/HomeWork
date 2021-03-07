#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int* a = new int[N];
    bool check = false;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                check = true;
                break;
            }
        }
        if (check) break;
    }
    if (check) cout << "Yes" << endl;
    else cout << "No" << endl;
    delete []a;
    return 0;
}
