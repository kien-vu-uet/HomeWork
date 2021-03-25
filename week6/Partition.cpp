#include <iostream>

using namespace std;

void showPart(int* part, int num, int index);
void print(int* part, int index);
int solve(int num, int index);

int main() {
	int n;
	cin >> n;
	//cout << solve(n, 0) << endl;

	int* part = new int[n];

	part[0] = 0;
	showPart(part, n, 0);

	delete[]part;
	return 0;
}

int solve(int num, int index) {
	if (num < 0) return 0;
	if (num == 0) return 1;
	
	int ways = 0;
	for (int i = index + 1; i <= num; i++) {
		ways += solve(num - i, i);
	}
	return ways;
}

void showPart(int* part, int num, int index) {
	if (num == 0) {
		print(part, index);
	}
	else {
		for (int i = part[index] + 1; i <= num; i++) {
			part[index + 1] = i; 
			showPart(part, num - i, index + 1);
		}
	}
}

void print(int* part, int index) {
	for (int i = 1; i <= index; i++) {
		cout << part[i] << " ";
	}
	cout << endl;
}