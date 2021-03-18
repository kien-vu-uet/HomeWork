#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>

using namespace std;

void detectCell(int** Map, int m, int n, int i, int j);
void detectMap(int** Map, int m, int n);
void randomBomb(int** Map, int m, int n, int K);
void printMap(int** Map, int m, int n, char** Status);

int main() {
    int m, n, K;
    cin >> m >> n >> K;

    int** Map = new int*[m];
    char** Status = new char*[m];
    for (int i = 0; i < m; i++){
        Map[i] = new int[n];
        Status[i] = new char[n];
        for (int j = 0; j < n; j++) {
            Map[i][j] = 0;
            Status[i][j] = 'C';
        }
    }

    randomBomb(Map, m, n, K);
    detectMap(Map, m, n);
    printMap(Map, m, n, Status);

    bool gameContinue = true; int t = 0;
    while (gameContinue) {
        int x, y;
        cin >> x >> y; t++;
        gameContinue = (t != m * n - K);
        system("cls");
        Status[x][y] = 'O';

        if (Map[x][y] == -1){
            cout << "YOU'RE DEAD!" << endl;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (Map[i][j] == -1) Status[i][j] = 'O';
                }
            }
            gameContinue = false;
        }

        printMap(Map, m, n, Status);

    }

    delete [] Map;
    delete [] Status;
    return 0;
}




void randomBomb(int** Map, int m, int n, int K){
    cout << "Map is loading ..." << endl;
    while (K != 0) {
        srand(time(0));
        int x = rand() % m;
        int y = rand() % n;
        if (Map[x][y] != -1) {
            Map[x][y] = -1;
            K--;
        }
        usleep(200);
    }
    cout << "Loading Successfully !" << endl;
}

void printMap(int** Map, int m, int n, char** Status) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if (Status[i][j] == 'O'){
                if (Map[i][j] == -1) cout << " B ";
                else cout << " " << Map[i][j] <<" ";
            }  else cout << "[] ";
            //cout << Map[i][j] << " ";
        }
        cout << endl;
    }
}

void detectCell(int** Map, int m, int n, int i, int j){
    for (int a = i - 1; a <= i+1; a++) {
        if (a < 0 || a >= m) continue;
        for (int b = j - 1; b <= j+1; b++) {
            if (b < 0 || b >= n) continue;
            if (Map[a][b] == -1) continue;
            Map[a][b] ++;
        }
    }
}

void detectMap(int** Map, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (Map[i][j] == -1) detectCell(Map, m , n, i, j);
        }
    }
}

