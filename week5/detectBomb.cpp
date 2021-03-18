#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>

using namespace std;

void detectCell(int** Map, int m, int n, int i, int j);
void detectMap(int** Map, int m, int n);
void randomBomb(int** Map, int m, int n, int K);
void printMap(int** Map, int m, int n, char** Status, bool &gameContinue);
void spreadAround(int** Map, int m, int n, int i, int j, char** Status);
void showMap(int** Map, int m, int n, char** Status);

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

    bool gameContinue = true;
    printMap(Map, m, n, Status, gameContinue);

    while (gameContinue) {
        int x, y;
        cin >> x >> y;

        system("cls");
        Status[x][y] = 'O';

        if (Map[x][y] == -1){
            cout << "YOU'RE DEAD!" << endl;
            showMap(Map, m, n, Status);
            gameContinue = false;
            printMap(Map, m, n, Status, gameContinue);
            break;
        }
        else if (Map[x][y] == 0)
            spreadAround(Map, m, n, x, y, Status);

        printMap(Map, m, n, Status, gameContinue);

        if (!gameContinue) {
            showMap(Map, m, n, Status);
            system("cls");
            cout << "YOU WIN!" << endl;
            printMap(Map, m, n, Status, gameContinue);
            break;
        }
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

void printMap(int** Map, int m, int n, char** Status, bool &gameContinue) {
    bool check = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            if (Status[i][j] == 'O'){
                if (Map[i][j] == -1) cout << " B ";
                else cout << " " << Map[i][j] <<" ";
            }  else cout << "[] ";
            if (Map[i][j] >= 0 && Status[i][j] == 'C') check = true;
        }
        cout << endl;
    }
    if (!check)
        gameContinue = false;
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

void spreadAround(int** Map, int m, int n, int i, int j, char** Status){
    Status[i][j] = 'O';
    for (int a = i - 1; a <= i+1; a++) {
        if (a < 0 || a >= m) continue;
        for (int b = j - 1; b <= j+1; b++) {
            if (b < 0 || b >= n) continue;;
            if (Map[a][b] == 0 && Status[a][b] == 'C') {
                Status[a][b] = 'O';
                spreadAround(Map, m, n, a, b, Status);
            }
            else if (Map[a][b] > 0 && Status[a][b] == 'C')
                Status[a][b] = 'O';
        }
    }
}

void showMap(int** Map, int m, int n, char** Status){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Status[i][j] = 'O';
        }
    }
}
