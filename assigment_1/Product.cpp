//Se da clasa Product(in fisierul Product.cpp).
//
//Avand ca model exercitiul lucrat la seminarul de astazi, sa se implementeze in clasa Product :
//
//-costructor care primeste toti parametrii necesari istantierii complete a unui obiect Product
//
//- constructor de copiere
//
//- destructor
//
//- meoda care calculeaza media preturilor
//
//- metode de set si get necesare
//
//Obs.: Metoda de set pentru atributul "price" trebuie sa modifice si istoricul preturilor.Atributul "priceHistory" nu va avea metoda de set, se va modifica doar la modificarea pretului curent.
//
//- exemplificare prin instantierea de obiecte
//
//- exemplificare necesitate constructor de copiere
#include <iostream>
#include<string>

using namespace std;


class Product
{
	int id = 0;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0.0;
	double* priceHistory = nullptr;
	int itemsSold = 0;

public:
	Product(int _id, const char* _name, const char* _description, double _price, const double* _priceHistory, int _itemsSold) :
		id(_id), price(_price), priceHistory(_priceHistory), itemsSold(_itemsSold)
	{
		this->name = new const char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);

		this->description = new const [strlen(_description) + 1];
		strcpy_s(this->description, strlen(_description) + 1, _description);
	}

	//all setters
	void set_id(int _id) {
		this->id = _id;

	}

	void set_priceHistory(const double* _priceHistory, int _itemsSold) {
		this->itemsSold = _itemsSold;

		this->priceHistory = new const double[_priceHistory;]

	}

	void set_name(const char* _name) {
		if _name == nullptr
			return nullptr
		this->name = new const char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1);

	}

	void set_description(const char* _description) {
		if _name == nullptr
			return nullptr
		this->description = new const char[strlen(_description) + 1];
		strcpy_s(this->name, strlen(_description) + 1);

	}



	//all getters
	//.....

	double getPriceAverage()
	{

	}

	~Product()
	{

	}
};