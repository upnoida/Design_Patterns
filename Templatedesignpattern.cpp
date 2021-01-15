#include "pch.h"
#include <iostream>

using namespace std;

class Pizza
{
public:
	Pizza(string name):m_description(name) {}

	virtual ~Pizza() {}

	void Prepare();

protected:

	virtual void PrepareDough();
	virtual void AddToppings() = 0;
	virtual void BakePizza();
	virtual void PrepareSauce();

private:
	string m_description;
};

class Cheesepizza :public Pizza
{
public:
	Cheesepizza():Pizza(string("Cheese pizza"))
	{
		
	}
	~Cheesepizza(){}

	void AddToppings();
};

class Meatpizza :public Pizza
{
public:
	Meatpizza() :Pizza(string("Meat pizza"))
	{

	}
	~Meatpizza() {}

	void AddToppings();
};


void Pizza::Prepare()
{

	cout << "Preparing a pizza" << m_description << endl;

	PrepareDough();
	PrepareSauce();
	AddToppings();
	BakePizza();

}

void Cheesepizza::AddToppings()
{
	cout << "Add cheese topping" << endl;
}

void Meatpizza::AddToppings()
{
	cout << "Add meat topping" << endl;
}


int main()
{


	Cheesepizza cheesePizza;

	cheesePizza.Prepare();

	Meatpizza meatLoversPizza;

	meatLoversPizza.Prepare();

	return 0;


}