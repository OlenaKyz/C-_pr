#include<iostream>
#include <vector>
using namespace std;

class MyProduct
{
protected:
	string name;
	double price;
	int quantity;
public:
	MyProduct(string myName, double myPrice, int myQuantity) :
		name{ myName }, price{ myPrice }, quantity{ myQuantity } {}
	//Product() : Product(0, 0, 0, 0) {}
	string GetName()
	{
		return name;
	}
	double GetPrice()
	{
		return price;
	}
	int GetQuantity()
	{
		return quantity;
	}
};

class Product : public MyProduct
{
	string name;
	string details;
	double price;
	int quantity;
public:
	Product(string myName, string myDetails, double myPrice, int myQuantity) :
		MyProduct( myName,  myPrice,  myQuantity), details{ myDetails } {}
	//Product() : Product(0, 0, 0, 0) {}
	string GetDetails()
	{
		return details;
	}

};

class Stock
{
	vector <Product> products;
public:


};

class Basket
{
	vector <MyProduct> myProducts;
	double totalPrice=0;
public:
	void PrintBasket()
	{
		for (int i = 0; i < myProducts.size(); i++)
		{
			cout << myProducts[i].GetName() << ",\tprice " << myProducts[i].GetPrice() * myProducts[i].GetQuantity() << " hrn.,\tquantity " << myProducts[i].GetQuantity() << endl;
			cout << "total price: " << totalPrice << endl;
		}
	}
	void AddToBasket(string myName, double myPrice, int myQuantity)
	{
		MyProduct myProduct(myName, myPrice, myQuantity);
		myProducts.push_back(myProduct);
		totalPrice += (myPrice * myQuantity);
	}

	void DeletFromBasket(string productName)
	{
		int temp = 0;
		for (int i = 0; i < myProducts.size(); i++)
		{
			if (myProducts[i].GetName() == productName)
			{
				myProducts.erase(myProducts.begin() + i);
				temp++;
			}
		}
		if (temp == 0) cout << "no such product in busket." << endl;
	}

	//double GetTotalPrice()
	//{
	//	return totalPrice;
	//}
};

class User
{
	string login;
	string password;
public:
	User(string myLogin, string myPassword) :
		login{ myLogin }, password{ myPassword }{}
	//User() : User(0, 0) {}

	string GetLogin()
	{
		return login;
	}

	string GetPassword()
	{
		return password;
	}
	void PrintUser()
	{
		cout << "User: " << login << endl;
	}
};

class UserAccounting
{
	vector <User> users;
public:
	//UserAccounting() : users{ NULL } {}

	//UserAccounting(const UserAccounting& copy)
	//{
	//	size = copy.size;
	//	users = new User[size];
	//	for (int i = 0; i < size; i++)
	//	{
	//		users[i]=copy.users[i];
	//	}
	//}
	bool SearchUser(string mylogin, string mypassword)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].GetLogin() == mylogin && users[i].GetPassword() == mypassword) 
				return true;
			else return false;
		}
	}
};

class Order
{
	Basket basket;
	User buyer;
	string adress;
	string date;
	string statusPayment;
	string statusDelivery;
	//Order(const Basket& myBasket, const User& myBuyer, string myAdress, string myDate, string myStatusPayment, string myStatusDelivery) :
	//	basket{ myBasket }, buyer{ myBuyer }, adress{ myAdress }, date{ myDate },
	//	statusPayment { myStatusPayment }, statusDelivery { myStatusDelivery } {}
	//	adress{0}, date{0}, statusPayment{0}, statusDelivery{0} 
	//{
	//	Basket baskeå;
	//	User buyer;
	//}
public:
	void PrintOrder()
	{
		buyer.PrintUser();
		basket.PrintBasket();
		cout << "adress: " << adress << endl;
		cout << "date of order: " << date << endl;
		cout << "status payment: " << statusPayment << endl;
		cout << "status delivery: " << statusDelivery << endl;
	}

	int StatusPayment()
	{
		cout << "1 - pay for your order now.\n";
		cout << "2 - pay for the order upon receipt.\n";
		cout << "3 - refuse payment and exit the order.\n";
		char ch;
		while (ch != 1 && ch != 2 && ch != 3) cin >> ch;
		if (ch == '1')
		{

		}
			return ch;
	}

	void Shopping()
	{

	}
};

class OrderAccounting
{
	vector <Order> orders;
public:
	//OrderAccounting() : orders{NULL} {}

	//OrderAccounting(const OrderAccounting& copy)
	//{
	//	size = copy.size;
	//	orders = new Order[size];
	//	for (int i = 0; i < size; i++)
	//	{
	//		orders[i] = copy.orders[i];
	//	}
	//}
	void PrintOrders()
	{
		for (int i = 0; i < orders.size(); i++)
		{
			cout << i + 1 << ". order:"<<endl;
			orders[i].PrintOrder();
			cout << endl;
		}
	}


};

//class PaymentDelivery
//{
//	int StatusPayment()
//	{
//		cout << "1 - pay for your order now.\n";
//		cout << "2 - pay for the order upon receipt.\n";
//		cout << "3 - refuse payment and exit the order.\n";
//		char ch;
//		while (ch != 1 && ch != 2 && ch != 3) cin >> ch;
//		if (ch == '1')
//		return ch;
//	}
//};

int main()
{

}