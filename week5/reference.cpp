#include <iostream>

using namespace std;

void swap_pass_by_reference(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_pass_by_value(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5, b = 10;
    //mechanism of parameter transmission:
    cout << "before : " << a << " " << b << endl;
    swap_pass_by_reference(a, b);
    cout << "after : " << a << " " << b << endl;
    // there is no change in the value of a and b
    cout << "-----------------" << endl;
    //value-based parameter transmission
    cout << "before : " << a << " " << b << endl;
    swap_pass_by_value(a, b);
    cout << "after : " << a << " " << b << endl;
    //The values ​​of a and b have been exchanged
    return 0;
}
