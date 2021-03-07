#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    int _min = 0;
    int _max = 0;
    int sumOfEven = 0;
    int sumOfOdd = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            _min = _max = a[i];
        }
        else if (a[i] > _max) _max = a[i];
        else if (a[i] < _min) _min = a[i];

        if (a[i] % 2 == 0) sumOfEven += a[i];
        else sumOfOdd += a[i];
    }

    cout << "Min number of the array is : " << _min << endl
         << "Max number of the array is : " << _max << endl
         << "Summary of evens in the array is : " << sumOfEven << endl
         << "Summary of odds in the array is : " << sumOfOdd << endl;
    delete []a;
    return 0;
}


