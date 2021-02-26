#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double money;
    cin >> money;

    double coef = 1.268241795;
    cout << fixed << setprecision(0) << money * coef << endl;

    return 0;
}
