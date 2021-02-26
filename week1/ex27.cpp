#include <iostream>

using namespace std;

int main(){
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            cout << "bye" << endl;
            break ;
        }
        else if (n >= 0 && n % 5 == 0) cout << n/5 << endl;
        else cout << "-1" << endl;
    }
    return 0;
}
