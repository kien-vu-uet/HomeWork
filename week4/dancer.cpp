#include <iostream>

using namespace std;

struct couple {
    double male;
    double female;
    bool greatCouple;
    couple get(double _male, double _female){
        male = _male;
        female = _female;
        greatCouple = (male > female);
    }
};

void arrange(couple* height, int N);

int main() {
    int N;
    cin >> N;

    couple* height = new couple[N];

    bool greatTeam = true;

    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        height[i].get(x, y);
        if (!height[i].greatCouple) greatTeam = false;
    }

    if(greatTeam) cout << "Yes" << endl;
    else arrange(height, N);

    delete []height;
    return 0;
}

void arrange(couple* height, int N){
    for (int i = 0; i < N; i++){
        if (height[i].greatCouple) continue;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (height[j].male > height[i].female && height[j].female < height[i].male){
                double temp1 = height[j].male;
                double temp2 = height[i].male;
                height[i].get(temp1, height[i].female);
                height[j].get(temp2, height[j].female);
                break;
            }
        }
    }

    bool greatLineup = true;
    for (int i = 0; i < N; i++){
        if (!height[i].greatCouple) {
            greatLineup = false;
            cout << "No" << endl;
            break;
        }
    }

    if (greatLineup) cout << "Yes" << endl;

}

