#include <iostream>

using namespace std;

int N , REP = 1;

void printArray(int* arr);
int permute(int* arr, int pivot);
bool checkIncrease(int* arr);

int main(){
	cin >> N;
	
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	cout << permute(arr, N - 1) << " permutations" << endl;

	delete[]arr;
	return 0;
}

void printArray(int* arr) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int permute(int* arr, int pivot) {
	if (pivot == 0) {
		if (arr[pivot] == 1 && checkIncrease(arr)) return 0;
		pivot = N - 1;
	}
	//
	printArray(arr);
	//swap
	int temp = arr[pivot];
	arr[pivot] = arr[pivot - 1];
	arr[pivot - 1] = temp;
	//
	return 1 + permute(arr, pivot - 1);
}

bool checkIncrease(int* arr) {
	for (int i = 1; i < N; i++) {
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}