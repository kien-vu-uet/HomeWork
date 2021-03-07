#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int** decMap = new int*[m+2];
    for (int i = 0; i <= m+1; i++) {
        decMap[i] = new int[n+2];
        for (int j = 0 ; j <= n+1; j++) {
            decMap[i][j] = 0;
        }
    }

    char** Map = new char*[m+1];
    for (int i = 1; i <= m; i++) {
        Map[i] = new char[n+1];
        for (int j = 1 ; j <= n; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == '*') {
                decMap[i-1][j-1] ++;
                decMap[i-1][j] ++;
                decMap[i-1][j+1] ++;
                decMap[i][j-1] ++;
                decMap[i][j+1] ++;
                decMap[i+1][j-1] ++;
                decMap[i+1][j] ++;
                decMap[i+1][j+1] ++;
            }
        }
    }

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++) {
            if (Map[i][j] == '*') cout << "* ";
            else cout << decMap[i][j] << " ";
        }
        cout << endl;
    }

    delete []Map;
    delete []decMap;
    return 0;
}
