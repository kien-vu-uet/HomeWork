#include <iostream>
#include <fstream>

using namespace std;

int N, d = 0;
int REP = 2;

void tickThreatenedCells(int** map, int pos_x, int pos_y, int comp, int value);
void printMap(int** map);
void arrange(int** map, int col);
bool checkCols(int** map, int col);

int main() {
	//ofstream outf("result.out");
	cin >> N;
	
	int** map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++)
			map[i][j] = 0;
	}
	
	for (int i = 0; i < N / 2 + N % 2; i++) {
		if (i == N / 2) REP = 1;
		tickThreatenedCells(map, 0, i, 0, -1);
		map[0][i] = 1;
		arrange(map, 1);
		tickThreatenedCells(map, 0, i, 1, 0);
	} 
	cout << d << " ways to arrange " << N << " Queens !" << endl;

	delete[]map;
	//outf.close();
	return 0;
}

void tickThreatenedCells(int** map, int pos_x, int pos_y, int comp, int value) {
	for (int i = 0; i < N; i++) {
		if (abs(map[i][pos_y]) == comp) // fill columns
			map[i][pos_y] = value;
		for (int j = 0; j < N; j++) {
			if (abs(map[pos_x][j]) == comp) // fill rows
				map[pos_x][j] = value;
			if (abs(i - pos_x) == abs(j - pos_y) && abs(map[i][j]) == comp) // fill diaglog
				map[i][j] = value;
		}
	}
	//map[pos_x][pos_y] = 1;
}

void printMap(int** map) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 1) cout << "Q ";
			//else if (map[i][j] <= -1) cout << "x "; else cout << "# ";
			else cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
	if (REP == 1) return;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (map[i][j] >= 1) cout << "Q ";
			//else if (map[i][j] <= -1) cout << "x "; else cout << "# ";
			else cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
}

void arrange(int** map, int col) {
	if (col >= N) {
		d += REP;
		printMap(map);
	}
	else {
		for (int y = 0; y < N; y++) {
			if (map[col][y] == 0) {
				tickThreatenedCells(map, col, y, 0, - col - 1);
				map[col][y] = col + 1;

				if (checkCols(map, col + 1)) arrange(map, col + 1);
	//			break;
				tickThreatenedCells(map, col, y, col + 1, 0);
			}
		}
	}
}

bool checkCols(int** map, int cols) {
	if (cols >= N) return true;
	for (int j = 0; j < N; j++) {
		if (map[cols][j] == 0)
			return true;
	}
	return false;
}