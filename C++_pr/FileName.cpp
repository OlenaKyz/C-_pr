#include<iostream>
using namespace std;

class Product
{
	string name;
	string details;
	double price;
	int quantity;
};

class Stock
{
	Product* products;
};

class Basket
{
	Product* myProducts;
	double totalPrice;
};

class User
{
	string login;
	string password;
};

class UserAccounting
{
	User* users;
};

class Order
{
	Basket myBasket;
	User buyer;
	string adress;
	string date;
	string status;
};

class OrderAccounting
{
	Order* orders;
};

class PaymentDelivery
{

};

int main()
{

}