#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct coordinate{
    int x;
    int y;
};


bool checkPos(coordinate q1, coordinate q2) {
    return ((q1.x == q2.x) || (q1.y == q2.y) || (abs(q1.x - q2.x) == abs(q1.y - q2.y)));
    return false;
}

int main() {
    int N; cin >> N;
    coordinate* queen = new coordinate[N];
    bool noQueenFighting = true;

    for (int i = 0; i < N; i++) {
        cin >> queen[i].x >> queen[i].y;
        for (int j = 0; j < i; j++) {
            if (checkPos(queen[i], queen[j])) {
                noQueenFighting = false;
                break;
            }
        }
        //if (!noQueenFighting) break;
    }

    if (noQueenFighting) cout << "no" << endl;
    else cout << "yes" << endl;

    delete []queen;
    return 0;
}
