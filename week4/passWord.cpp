#include <iostream>
#include <vector>

using namespace std;

void checkEqual(string s1, string s2){
    bool check = true;
    int len = s1.size();
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[len - 1 - i]) {
            check = false;
            break;
        }
    }
    if (check) cout << len << " " << s1[len / 2] << endl;

}

int main() {
    int N;
    cin >> N;
    vector<string> code;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.size() % 2 == 1) code.push_back(s);
        for (int j = 0; j < code.size() - 1; j++) {
            if (s.size() != code[j].length()) continue;
            checkEqual(s, code[j]);
        }
    }

    return 0;
}
