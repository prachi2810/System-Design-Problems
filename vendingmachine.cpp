#include <bits/stdc++.h>
using namespace std;

class Product {
public:
    string code;
    int price;

    Product(string name, int p) {
        code = name;
        price = p;
    }

    void clickOnButton() {
        cout << "Click on button" << endl;
        return;
    }
};

class ProductShelf {
public:
    vector<Product> productList;

    void addProduct(Product p) {
        productList.push_back(p);
        return;
    }

    string selectProduct(string code) {
        for (int i = 0; i < productList.size(); i++) {
            if (productList[i].code == code) {
                cout << "Product " << code << " is selected" << endl;
                return code;
            }
        }
        cout << "Selected product is not found" << endl;
        return "";
    }
};

class Payment {
public:
    ProductShelf p;
    int coin;
    
    Payment(ProductShelf s): p(s){
        
    }

    void clickOnPay() {
        cout << "Click on Pay" << endl;
        return;
    }

    int insertCoin(int c) {
        cout << c << " coins are inserted." << endl;
        return c;
    }

    bool changeCoin(int c, string code) {
        for (int i = 0; i < p.productList.size(); i++) {
            if (p.productList[i].code == code) {
                cout<<"p"<<p.productList[i].price<<" "<<c<<endl;
                if (p.productList[i].price < c) {
                    
                    cout << "Coin " << (c - p.productList[i].price) << " change" << endl;
                    return true;
                } else if (p.productList[i].price == c) {
                    cout << "no change" << endl;
                    return true;
                }
            }
        }
        return false;
    }

    void despenseProduct(bool state, string code) {
        if (state) {
            cout << code << " product is dispensed" << endl;
        } else {
            cout << "Coins are not enough" << endl;
        }
        return;
    }
};

int main() {
    // Initialize ProductShelf
    ProductShelf p;
    p.addProduct(Product("coke", 40));
    p.addProduct(Product("sprite", 30));
    p.addProduct(Product("shake", 30));

    // Initialize Payment
    Payment payment(p);

    // Simulate vending machine operations
    payment.clickOnPay();
    int c = payment.insertCoin(40);
    string code = p.selectProduct("sprite");
    bool state = payment.changeCoin(c, code);
    payment.despenseProduct(state, code);

    return 0;
}
