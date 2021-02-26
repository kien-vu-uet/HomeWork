#include <iostream>

using namespace std;

int salary(int hour) {
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
    return money;
}

double tax(double income) {
    income *= 0.91;
    if (income <= 1000000) income *= 1;
    if (income <= 1500000) income -= (income - 1000000) * 0.1 ;
    else if (income <= 2000000) income -= (50000 + (income - 1500000) * 0.15)  ;
    else if (income > 2000000) income -= (125000 + (income - 2000000) * 0.2) ;

    return income;
}

int main(){
    double debt = 10000000;
    int numOfMonth = 0;
    int hour[12] = {155, 145, 125, 135, 100, 100, 145, 135, 100, 155, 170, 180};
    while (debt > 0) {
        double income = salary(155) + 1500000;
        double moneyPayPerMonth = tax(income) - 2000000;
        debt -= moneyPayPerMonth;
        numOfMonth ++;
    }
    cout << numOfMonth << endl;
    return 0;
}
