#include <iostream>
#include <vector>

using namespace std;

string getString(char ch1, char ch2, char ch3){
    string res = "";
    res += ch1;
    res += ch2;
    if (ch3 != ' ') res += ch3;
    return res;
}

bool getComparisonRes(string s1, string s2, int* ord) {
    //clause : (s1 is bigger than s2) ? true / false
    if (s1.size() < 3) {
        s1 += s1[1];
        if (s1 == s2) return false;
    }
    if (s2.size() < 3) {
        s2 += s2[1];
        if (s1 == s2) return true;
    }
    return (ord[s1[0]- '0'] > ord[s2[0] - '0']);
    return (ord[s1[1]- '0'] > ord[s2[1] - '0']);
    return (ord[s1[2]- '0'] > ord[s2[2] - '0']);

}

void triple(char ch, vector<string> &word);
void flip(char ch1, char ch2, vector<string> &word , bool rep);
void mix(char ch1, char ch2, char ch3, vector<string> &word, int no);
void sort_list(vector<string> &word, int* ord);
void print(vector<string> word);

int main() {
    string s;
    cin >> s;

    int len = s.length();
    int* ord = new int[100]; ord[0] = 0;
    vector <string> word;

    int _i, _j;
    if (len <= 2) {
        _i = 1;
        _j = len;
    }
    else {
        _i = len / 3;
        _j = 2 * len / 3;
    } //cout << _i << " " << _j << endl;

    for (int i = 0; i < _i; i++) {
        ord[s[i] - '0'] = i;
        triple(s[i], word);
        for (int j = _i; j < _j; j++) {
            ord[s[j] - '0'] = j;
            triple(s[j], word);
            flip(s[i], s[j], word, true);
            for (int k = _j; k < len; k++) {
                ord[s[k] - '0'] = k;
                triple(s[k], word);
                flip(s[i], s[k], word, true);
                mix(s[i], s[j], s[k], word , 1);
            }
        }
    }

    //print(word); cout << endl;
    sort_list(word, ord);
    //cout << '~' - 'z' << endl;
    print(word);
    //if (getComparisonRes("wqw", "wqq", ord)) cout << "yes"; else cout << "no";
    delete []ord;
    cout << "BAI NAY KHO QUA CO OI :<";
    return 0;
}

void triple(char ch, vector<string> &word){

    word.push_back(getString(ch, ch, ch));
    word.push_back(getString(ch, ch, ' '));
}

void flip(char ch1, char ch2, vector<string> &word , bool rep) {
    word.push_back(getString(ch1 , ch1 , ch2));
    word.push_back(getString(ch1 , ch2 , ch1));
    word.push_back(getString(ch2 , ch1 , ch1));
    word.push_back(getString(ch1, ch2, ' '));
    if (rep)
        flip(ch2, ch1, word, false);
}

void mix(char ch1, char ch2, char ch3, vector<string> &word, int no){
    word.push_back(getString(ch1 , ch2 , ch3));
    word.push_back(getString(ch1 , ch3 , ch2));
    if (no == 1)
        mix(ch2, ch3, ch1, word, 2);
    else if (no == 2)
        mix(ch3, ch1, ch2, word, 3);
}

void sort_list(vector<string> &word, int* ord) {
    for (int i = 0; i < word.size() - 1; i++) {
        for (int j = i + 1; j < word.size(); j++){
            //cout << word[i] << " " << word[j] << " " << getComparisonRes(word[i], word[j], ord) << endl;
            if (getComparisonRes(word[i], word[j], ord)) {
                string temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}

void print(vector<string> word){
    for (int i = 0; i < word.size(); i++){
        cout << word[i] << " ";
    } cout << endl;
}

