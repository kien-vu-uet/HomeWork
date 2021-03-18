#include <iostream>

using namespace std;

int main() {
    int a[3];
    cout << &a[0] << " | " << &a[1] << " | " << &a[2] << endl;
    cout << "Dia chi cua 3 phan tu trong mang khac nhau o ki tu cuoi cung" << endl;

    //

    char b[3];
    cout << &b[0] << " | " << &b[1] << " | " << &b[2] << endl;
    cout << "Dia chi cua 3 phan tu trong mang khac nhau o ki tu dau tien" << endl;
    return 0;
}
