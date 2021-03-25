#include <iostream>

using namespace std;

int N, K, d= 0;

void permute(char* res, int rep);
bool check(char* res, char ch, int pos);

int main() {
	cin >> N >> K;
	char* res = new char[K];

	permute(res, 0); cout << d << " permutations!" << endl;

	delete[]res;
	return 0;
}

void permute(char* res, int rep) {
	if (rep >= K) {
		for (int i = 0; i < K; ++i)
			cout << res[i];
		cout << endl;
		d++;
	} 
	else {
		for (int i = 0; i < N; i++) {
			if (check(res, 'a' + i, rep - 1)) {
				res[rep] = 'a' + i;
				permute(res, rep + 1);
			}
		}
	}
}

bool check(char* res, char ch, int pos) {
	if (pos < 0) return true;
	if (ch == res[pos]) return false;
	return check(res, ch, pos - 1);
}