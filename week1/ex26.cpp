#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    int M,m;
    m = 100000000;
    double mean;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mean += a[i];
        M = max(M, a[i]);
        m = min(m, a[i]);
    }
    cout << fixed << setprecision(2) << mean / n << endl;
    cout << M << endl
        << m << endl;
    return 0;
}
