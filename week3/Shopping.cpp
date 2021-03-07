#include <iostream>

using namespace std;

struct product {
    int index;
    string name;
    double price;
    double amount;
    double total;

    product getTotal(){
        total = price * amount;
    }
    void print() {
        cout << index << " " << name << "  " << price << "  " << amount << "  " << price * amount << endl;
    }
    double get(string s) {
        if (s == "price") return price;
        else if (s == "total") return price * amount;
        else return index;
    }
};

double totalPricePerProduct(product p){
    p.getTotal();
    return p.total;
}

bool checkMoney(double existingAmount, product* a, int n) {
    double totalPrice = 0;
    for (int i = 0; i < n; i++) {
        totalPrice += totalPricePerProduct(a[i]);
    }
    return (totalPrice <= existingAmount);
}

void Sort(product* a, int n, string s) {
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++) {
            if (a[j].get(s) < a[i].get(s)) swap(a[i], a[j]);
        }
    }
}

void buying(product* a, int n, string s, double existingAmount){
    Sort(a, n, s);
    string res = "";
    double money = 0;
    int numOfProd = 0;
    while (money <= existingAmount){
        money += totalPricePerProduct( a[numOfProd] );
        numOfProd ++;
    }

    Sort(a, numOfProd, "index");
    for (int i = 0; i < numOfProd; i++)
        a[i].print();
}

int main() {
    int n;
    cout << "Enter number of products ... "; cin >> n;

    double existingAmount;
    cout << "Exsiting amount ... "; cin >> existingAmount;

    cout << "Enter name, price, amount of each product ... " << endl;
    product* a = new product[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].price >> a[i].amount;
        a[i].index = i + 1;
        //a[i].print();
    }
     cout << "Shopping list ... " << endl;

    if (checkMoney(existingAmount, a, n)) cout << "All are bought !!!" << endl;
    else {
        // case 1 ...
        buying(a, n, "price", existingAmount);
        cout << "----------" << endl;
        //case 2 ...
        buying(a, n, "total", existingAmount);
    }

    delete []a;
    return 0;
}
