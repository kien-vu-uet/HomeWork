#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string a[20] = { "" , " one" , " two" , " three" , " four" , " five" , " six" , " seven" , " eight" , " nine" , " ten" , " eleven" , " twelve" , " thirteen" , " fourteen" , " fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen" };
    string b[10] = { "" , "" , " twenty" , " thirty" , " forty" , " fifty" , " sixty" , " seventy" , " eighty" , " ninety"};
    string c[3] = { "" , " thousand" , " million"};

    while (true) {
        long n;
        cout << "Please, enter your number : ";
        cin >> n;

        string spell = "";

        string sign = "";
        if (n < 0) {
            sign = "negative ";
            n = -n;
        }

        int i = 0;
        while (n != 0){
            spell = c[i] + spell;
            int p = n % 1000;
            n = n / 1000;

            int m = p % 100;
            p = p / 100;

            if (m < 20) spell = a[m] + spell;
            else if (m % 10 == 0) spell = b[m/10] + spell;
            else {
                spell = a[m%10] + spell;
                spell = b[m/10] + spell;
            }

            if (p != 0){
                spell = " hundred and" + spell;
                spell = a[p] + spell;
                spell = "," + spell;
            }

           i++;
        }
        while (spell[0] == ' ' || spell[0] == ',') spell.erase(0, 1);
        spell = sign + spell;
        spell[0] = spell[0] - 32;

        cout << spell << endl;
        cout << "----------" << endl;
    }
    return 0;
}
