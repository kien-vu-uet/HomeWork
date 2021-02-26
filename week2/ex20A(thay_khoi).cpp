#include <iostream>

using namespace std;

int main() {
    int hour;
    cin >> hour ;
    int salaryPerHour[4] = {12000, 16000, 20000, 25000};
    int level[4] = {100, 50, 50, 0};
    int i = 0;
    int money = 0;
    while (hour != 0) {
        if (i == 3 || hour <= level[i]){
            money += hour * salaryPerHour[i];
            hour = 0;
        }
        else if (hour > level[i]) {
            money += level[i] * salaryPerHour[i];
            hour -= level[i];
        }
        i++;
    }
    cout << money << endl;
    return 0;
}
