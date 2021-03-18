#include <iostream>

using namespace std;

void A() {
    cout << "answer for a..." << endl;
    int x = 5;
    int* a;
    *a = x;
    cout << &x << " " << &a << endl;
    //reference variable and pointed-variable are two different variables;
}



void C() {
    cout << "answer for c..." << endl;
    int* p;
    int x = 5;
    *p = x;
    cout << *p << endl;
    int y = 10;
    *p = y;
    cout << *p << endl;
    // reference variable can point to a different variable
}

void B() {
    cout << "answer for b..." << endl;
    int* b;
    cout << *b << endl;
    // after this command, the program has failed and gave no results
}

int main() {
    A();

    //B();

    C();

    B();
    return 0;
}
