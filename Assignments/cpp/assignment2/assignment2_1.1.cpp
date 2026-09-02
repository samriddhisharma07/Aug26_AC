#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product{
    string name;
    double price;
    int quantity;
public:
    static int prodId;
    int productId;

    Product(){
        productId = prodId;
        prodId++;
        name = "";
        price = 0.0;
        quantity = 0;
    }

    void acceptDetails(){
        cout << "enter name: " << endl;
        getline(cin, name);
        cout << "enter price: " << endl;
        cin >> price;
        cout << "enter qnty: " << endl;
        cin >> quantity;
        cin.ignore();   
    }

    void displayDetails() const{
        cout << left << setw(8) << productId << setw(12) << name << setw(10) << price << setw(8) << quantity << setw(15) << totalValue(); 
    }

    double totalValue() const{
        return price * quantity;
    }

    bool isLowStock(int threshold) const{
        return quantity < threshold;
    }

    string getName() const { return name; }
    int getId() const { return productId; }
    double getTotal() const { return totalValue(); }
};

int Product::prodId = 1001;

int main(){
    const int size = 5;
    Product product[size];

    for(int i = 0; i < 2; i++){
        product[i].acceptDetails();
    }

    cout << "========= INVENTORY REPORT =========" << endl;
    cout << "ID      Name      Price     Qty    Total Value" << endl;

    Product big = product[0];
    int val = 10;

    for(int i = 0; i < 2; i++){
        product[i].displayDetails();
        if(product[i].isLowStock(val)){
            cout << " <- LOW STOCK";
        }
        if(product[i].getTotal() > big.getTotal()){
            big = product[i];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Highest Value Product : " << big.getName() << " (Rs. " << fixed << setprecision(2) << big.getTotal() << ")" << endl;
    //big.displayDetails();
    cout << endl;

    cout << "Low Stock (threshold: " << val << ") : ";
    for(int i = 0; i < 2; i++){
        if(product[i].isLowStock(val)){
            cout << product[i].getName() << ", ... ";
        }
    }
    cout << endl;

    return 0;
}