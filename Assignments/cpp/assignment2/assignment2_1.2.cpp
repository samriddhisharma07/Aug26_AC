#include <iostream>
using namespace std;
double reorderCost(int qty, double unitPrice){
    return qty*unitPrice;
}
double reorderCost(double qty, double unitPrice){
    return qty*unitPrice;
}
double reorderCost(int qty, double unitPrice, double taxRate){
    double a = qty*unitPrice;
    double tax_amount = a*taxRate/100;
    return a+tax_amount;
}
double applyDiscount(double price, double discountPercent = 10.0){
    double discount = price*discountPercent/100;
    return price - discount;
}

int main(){
    int quantity;
    double fracQuantity;
    double unitPrice;
    double taxRate;
    double price;
    double discountPercent;
    cin>>quantity;
    cin>>unitPrice;
    cin>>taxRate;
    cin>>fracQuantity;
    cin>>price;
    cin>>discountPercent;
    double rel1 = reorderCost(quantity,unitPrice);
    cout<<"Output with int and double : "<<rel1<<endl;
    double rel2 = reorderCost(fracQuantity , unitPrice);
    cout<<"Output with double and double : "<<rel2<<endl;
    double rel3 = reorderCost(quantity , unitPrice , taxRate);
    cout<<"Output with int double double : "<<rel3<<endl;
    double rel4 = applyDiscount(price , discountPercent);
    cout<<"Output with price and discount  : "<<rel4<<endl;
    double rel5 = applyDiscount(price);
    cout<<"Output with default discount  : "<<rel5<<endl;

}