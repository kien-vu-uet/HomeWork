#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int t = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            cout << s[i] << s[j] << " ";
            for (int k = 0; k < s.size(); k++) {
                cout << s[i] << s[j] << s[k] << " ";
            }
        }
    }
    return 0;
}

