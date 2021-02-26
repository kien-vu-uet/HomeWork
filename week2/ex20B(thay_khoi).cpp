#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double income;
    cin >> income;

    income *= 0.91;
    if (income <= 1000000) income *= 1;
    if (income <= 1500000) income -= (income - 1000000) * 0.1 ;
    else if (income <= 2000000) income -= (50000 + (income - 1500000) * 0.15)  ;
    else if (income > 2000000) income -= (125000 + (income - 2000000) * 0.2) ;

    cout << fixed << setprecision(0) << income << endl;
    return 0;
}


