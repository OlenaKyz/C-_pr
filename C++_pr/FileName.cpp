#include <iostream>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;


class Product
{
public:
    string name;
    string description;
    double price;
    int quantity;

    Product(string name, string description, double price, int quantity) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->quantity = quantity;
    }


};


class Cart
{
public:
    vector<Product*> products;

    void addProduct(Product* product)
    {
        products.push_back(product);
    }

    double getTotalPrice()
    {
        double totalPrice = 0;
        for (Product* product : products)
        {
            totalPrice += product->price;
        }
        return totalPrice;
    }
};


class Order
{
public:
    int orderNumber;
    double orderDate;
    string orderStatus;
    vector<Product*> products;
    string userId;

    Order(int orderNumber, double orderDate, string orderStatu, string userId)
    {
        this->orderNumber = orderNumber;
        this->orderDate = orderDate;
        this->orderStatus = orderStatus;

    }

    void addProduct(Product* product)
    {
        products.push_back(product);
    }

    double getTotalPrice()
    {
        double totalPrice = 0;
        for (Product* product : products)
        {
            totalPrice += product->price;
        }
        return totalPrice;
    }


    void setOrderStatus(string status)
    {
        orderStatus = status;
    }


    void setUserId(string userId)
    {
        this->userId = userId;
    }

    string getOrderStatus() const {
        return orderStatus;
    }

    void Print()
    {
        cout << "\n????? ??????: " << orderNumber << endl;
        cout << "???? ??????: " << orderDate << endl;

        for (Product* product : products)
        {
            cout << "\n????????: " << product->name << endl;
            cout << "????????: " << product->description << endl;
            cout << "????: $" << product->price << endl;
        }
    }
};


class User
{
public:
    string username;
    string password;
    vector<Order*> orders;

    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }
    void addOrder(Order* order)
    {
        orders.push_back(order);
    }

    string getUsername() const
    {
        return username;
    }
};


int main()
{
    setlocale(LC_ALL, "RU");

    User* user = new User("admin", "password");

    Product* product1 = new Product("iPhone 15", "Apple iPhone 15", 999, 10);
    Product* product2 = new Product("Samsung Galaxy S24", "Samsung Galaxy S24", 899, 15);
    Product* product3 = new Product("MacBook", "Apple MacBook", 1499, 5);


    Cart* cart = new Cart();
    cart->addProduct(product1);
    cart->addProduct(product2);

    double totalPrice = cart->getTotalPrice();
    cout << "????? ????????? ??????? ? ???????: " << totalPrice << endl;


    Order* order = new Order(1, double(15.11), "Process", user->username);
    order->addProduct(product1);
    order->Print();
    order->setOrderStatus("Completed");


    cout << "\n?????: " << user->getUsername() << endl;
    cout << "?????? ??????: " << order->getOrderStatus() << endl;


    totalPrice = order->getTotalPrice();
    cout << "????? ????????? ??????? ? ??????: " << totalPrice << endl;


    ofstream outputFile("Order.txt");
    if (!outputFile.is_open()) {
        cout << "error" << endl;
        return 1;
    }
    outputFile << "\n????? ??????: " << order->orderNumber << endl;
    outputFile << "???? ??????: " << order->orderDate << endl;
    outputFile << "????? ????????????: " << order->userId << endl;
    outputFile << "?????? ??????: " << order->orderStatus << endl;
    outputFile << "?????? ? ??????:" << endl;

    for (Product* product : order->products)
    {
        outputFile << "\n????????: " << product->name << endl;
        outputFile << "????????: " << product->description << endl;
        outputFile << "????: $" << product->price << endl;
    }
    outputFile.close();

    return 0;
}