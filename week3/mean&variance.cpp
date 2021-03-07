#include <iostream>
#include <iomanip>

using namespace std;

double square(double x){
    return x*x;
}

int main() {
    int n;
    cin >> n;

    int * arr = new int[n];
    double mean = 0;
    double variance = 0;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mean += arr[i];
    }
    mean = mean / n;
    cout << fixed << setprecision(2) << "mean of the array is : " << mean << endl;

    for (int i = 0; i < n; i++) {
        variance += square(arr[i] - mean);
    }
    variance = variance / n;
    cout << fixed << setprecision(2) << "variance of the array is : " << variance << endl;

    delete []arr;
    return 0;
}
