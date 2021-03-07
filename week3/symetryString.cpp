#include <iostream>

using namespace std;

int main() {
    string s;
    //while (true) {
    getline(cin, s);
    int len = s.length();
    bool Yes = true;
    for (int i = 0; i < len/2; i++){
        if (s[i] != s[len - 1 - i]) {
            Yes = false;
            break;
        }
    }
    if (Yes) cout << "Yes" << endl;
    else cout << "No" << endl;
    //}
    return 0;
}
