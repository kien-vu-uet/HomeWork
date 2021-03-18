#include <iostream>

using namespace std;

int factorial(int x) {
    if (x <= 2) return x;
    return x * factorial(x - 1);
}

int main() {
    int N;
    cin >> N;
    cout << "x = " << N << " at " << &N << endl;
    cout << "Factorial of " << N << " is : " << factorial(N);
    return 0;
}
