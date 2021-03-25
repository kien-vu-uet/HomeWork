#include <iostream>

using namespace std;

void printMatrix(int** matrix, int N);
void flipMatrix(int** matrix, int size, int pos_x, int pos_y, bool status);

int main() {
	int n;
	cin >> n;
	
	int N = 2;
	for (int i = 1; i < n; i++) {
		N *= 2;
	}
	
	int** matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}

	flipMatrix(matrix, N, 0, 0, true);
	printMatrix(matrix, N);

	return 0;
}

void flipMatrix(int** matrix, int size, int pos_x, int pos_y, bool status) {
	if (size == 2) {
		if (status) { 
			matrix[pos_x][pos_y] = 1;
			matrix[pos_x][pos_y + 1] = 1;
			matrix[pos_x + 1][pos_y] = 1;
			matrix[pos_x + 1][pos_y + 1] = 0;
		}
		else { // reverse matrix
			matrix[pos_x][pos_y] = 0;
			matrix[pos_x][pos_y + 1] = 0;
			matrix[pos_x + 1][pos_y] = 0;
			matrix[pos_x + 1][pos_y + 1] = 1;
		}
	}
	else {
		if (status) {
			flipMatrix(matrix, size / 2, pos_x, pos_y, true);
			flipMatrix(matrix, size / 2, pos_x + size / 2, pos_y, true);
			flipMatrix(matrix, size / 2, pos_x, pos_y + size / 2, true);
			flipMatrix(matrix, size / 2, pos_x + size / 2, pos_y + size / 2, false);
		}
		else {
			flipMatrix(matrix, size / 2, pos_x, pos_y, false);
			flipMatrix(matrix, size / 2, pos_x + size / 2, pos_y, false);
			flipMatrix(matrix, size / 2, pos_x, pos_y + size / 2, false);
			flipMatrix(matrix, size / 2, pos_x + size / 2, pos_y + size / 2, true);
		}
	}
}

void printMatrix(int** matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 0) cout << "|||" << " "; // this cell is white;
			else cout << "[ ]" << " "; // this cell is black;
		}
		cout << endl;
	}
}
