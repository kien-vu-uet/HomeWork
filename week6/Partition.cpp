#include <iostream>

using namespace std;

int N;

void showPart(int* part, int num, int index);
void print(int* part, int index);

int main() {
	cin >> N;

	int* part = new int[N + 1];

	part[0] = N;
	showPart(part, N, 0);
	//cout << solve(n) << endl;
	delete[]part;
	return 0;
}


void showPart(int* part, int num, int index) {
	if (num == 0) {
		print(part, index);
	}
	else {
		for (int i = part[index]; i > 0; i--) {
			part[index + 1] = i; 
			if (i <= num) 
				showPart(part, num - i, index + 1);
		}
	}
}

void print(int* part, int index) {
	for (int i  = 1; i <= index; i++) {
		cout << part[i] << " ";
	}
	cout << endl;
}