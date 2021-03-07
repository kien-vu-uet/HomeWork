#include <iostream>
#include <iomanip>

using namespace std;

struct student{
    int index;
    double math;
    double physic;
    double english;
    double average;

    void getAverage() {
        average = (math + physic + english) / 3;
    }

    double get(string s) {
        if (s == "math") return math;
        else if (s == "physic") return physic;
        else if (s == "average") return average;
        else return index;
    }

    void print(string s){
        cout << "Student " << setw(3) << fixed << setprecision(0) << index << " ";
        if (s == "average") cout << setw(10) << fixed << setprecision(1) << average;
        cout << setw(10) << fixed << setprecision(1) << math
             << setw(10) << fixed << setprecision(1) << physic
             << setw(10) << fixed << setprecision(1) << english << endl;
    }
};

void Sort(student* a, int n, string s){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j].get(s) > a[i].get(s)) swap(a[i], a[j]);
        }
    }
}

void printList(student* a, int n, string s) {
    cout << "Sorting based on " << s << " score list... " << endl;
    cout <<"            ";
        if (s == "average") cout << "   Average";
    cout << "      Math"
             << "    Physic"
             << "   English" << endl;
    Sort(a, n, s);
    for (int i = 0; i < n; i++) {
        a[i].print(s);
    }
    cout << "-----------" << endl;
}

int main() {
    int n;
    cout << "Enter number of students ...";
    cin >> n;

    cout << "Enter student's scores list : Math | Physic | English ... ";
    student* a = new student[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].math >> a[i].physic >> a[i].english;
        a[i].getAverage();
        a[i].index = i + 1;
    }

    printList(a, n, "math");

    printList(a, n, "physic");

    printList(a, n, "average");

    delete []a;
    return 0;
}
