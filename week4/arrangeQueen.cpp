#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> pos) {
    for (int i = 0; i < pos.size(); i++) {
        for (int j = 0; j < pos.size(); j++){
            if (j != pos[i]) cout << "* ";
            else cout << "Q ";
        }
        cout << endl;
    }
}

int Find(vector<int>pos, int i) {
    for (int _position = 0; _position < pos.size(); _position++){ // position
        bool check = true;
        for (int _column = 0; _column < i; _column++) { // check
            //cout <<_position << " " << pos[_column] << endl << abs(i - _column) << " " << abs(_position- pos[_column]) << endl;
            if (pos[_column] == _position || abs(i - _column) == abs(_position - pos[_column])) {
                check = false;
                break;
            }
        }
        //cout  << "-------------" << endl;
        if (check) return _position;
    }
    return -1;
}

void reset(vector<int> &pos) {
    for (int i = 0; i < pos.size(); i++) {
        pos[i] = -1;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> pos(N, -1);

    bool invalid = true;
    int start = 0;
    while (invalid) {
        pos[0] = start;
        for (int i = 1; i < N; i++) {
            if (Find(pos, i) == -1) {
                reset(pos);
                break;
            }
            pos[i] = Find(pos, i);
            invalid = (i == N - 1);
        }
        start++;
    }
    print(pos);
    return 0;
}




