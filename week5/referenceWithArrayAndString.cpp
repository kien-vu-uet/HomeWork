#include <iostream>

using namespace std;

void increase1unit(int a[]) {
    for (int i = 0; i < 3; i++) {
        a[i] += 1;
    }
}

void insert1tostring(string s){
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 1) s[i] = s[i] - 1;
    }
}

int main () {
    int a[3] = {1, 2, 3};
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    increase1unit(a);
    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    } cout << endl << "---------" << endl;
    // Based on the result, we see the array passed to the function by value

    string s = "dark dark bruh bruh lmao";
    cout << s << endl;
    insert1tostring(s);
    cout << s << endl;
    //Based on the results, we see the string passed to the function by reference
    return 0;
}
