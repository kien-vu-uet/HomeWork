#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int A[4] = {1,2,3,4};
int a[] = {1,2,3,4};

int main(){
    //array 1D
    for (int i = 0; i < 4; i++) cout << A[i] << "/" << a[i] << " ";
    cout << "----------" << endl;

    //array 2D
    char daytab[2][12] = {
     {31,28,31,30,31,30,31,31,30,31,30,31},
     {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            cout << daytab[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;

    //sort
    int b[30];
    for (int i = 0; i < 30; i++){
        b[i] = rand() % 100;
        // use sleep to get a new seed
        Sleep(500);
        srand(time(NULL));
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "after being sorted :" << endl;
    for (int i = 0; i < 29; i++) {
        for (int j = i + 1; j < 30; j++) {
            if (b[j] < b[i]) swap(b[i], b[j]);
        }
    }
    for (int i = 0; i < 30; i++) cout << b[i] <<  " ";
    return 0;
}
