#include <iostream>

using namespace std;

int N, K, d = 0;

void combine(char* res, int start, int rep);

int main() {
	cin >> N >> K;
	char* res = new char[K];
	combine(res, 0, 0); cout << d << " combinations!" << endl;
	delete[] res;
	return 0;
}

void combine(char* res, int start, int rep) {
	if (rep >= K) {
		for (int i = 0; i < K; i++)
			cout << res[i];
		cout << endl;
		d++;
	}
	else {
		for (int i = start; i < N; i++) {
			//cout << start << " " << rep << endl;
			char ch = 'a' + i;
			res[rep] = ch;
			combine(res, i + 1, rep + 1);
		}
	}
}