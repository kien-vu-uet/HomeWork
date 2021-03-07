#include <iostream>

using namespace std;

bool checkSymetry(int num) {
    int rev = 0;
    while (num != 0){
        rev = rev * 10 + num % 10;
        bool check =  (num == rev);
        if (check) return true;
        num = num / 10;
    }
    return false;
}
int main() {
    int T, A, B;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        int m = 0;
        for (int i = A; i <= B; i++){
            if (checkSymetry(i)) m++;
        }
        cout << m << endl;
    }
    return 0;
}
