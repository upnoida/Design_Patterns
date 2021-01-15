#include "pch.h"
#include <iostream>
#include <string>


//http://simpletechtalks.com/flyweight-design-pattern/

using namespace std;

class Model
{
private:
	string m_name;
	int m_capacity;
	int m_speed;
public:

	virtual void showdetails()
	{
		cout << " Name " << m_name << "Capacity" << m_capacity << "Speed" << m_speed << endl;
	}

	Model(string name,int capacity,int speed)
	{
		m_name = name;
		m_capacity = capacity;
		m_speed = speed;
	}

	Model(){}
};

class Airbus380 :public Model
{
public:
	Airbus380():Model("Airbus380", 200, 800){}

};

class Boeing797 :public Model
{
public:
	Boeing797() :Model("Boeing797", 200, 800) {}
};

class Boeing787 :public Model
{
public:
	Boeing787() :Model("Boeing787", 200, 800) {}
};


class FlyweightFactory
{
private:
	static Airbus380* s_airbus380;
	static Boeing797* s_boeing797;
	static Boeing787* s_boeing787;

public:

	static Model* getModel(int type)
	{
		switch (type)
		{
		case 380:
			if (!s_airbus380)
			{
				s_airbus380 = new Airbus380();
			}
		case 787:
			if (!s_boeing787)
			{
				s_boeing787 = new Boeing787();
			}
		case 797:
			if (!s_boeing797)
			{
				s_boeing797 = new Boeing797();
			}
		default:
			break;
		}
	}
};
Airbus380* FlyweightFactory::s_airbus380;
Boeing787* FlyweightFactory::s_boeing787;
Boeing797* FlyweightFactory::s_boeing797;


class Aeroplane : public Model
{
private:
	Model* m_model;
	string m_mfgDate;
	int m_id;

public:
	Aeroplane(Model* model, string date, int id)
	{
		m_model = model;
		m_mfgDate = date;
		m_id = id;
	}

	virtual void showDetails()
	{
		m_model->showdetails();
		cout << "MfgDate : " << m_mfgDate << ", Serial No: " << m_id << endl;
	}
};

int main()
{
	Aeroplane first = Aeroplane(FlyweightFactory::getModel(787), "10th Feb 1987", 100213);
	Aeroplane second = Aeroplane(FlyweightFactory::getModel(797), "1th Feb 1987", 100214);
	Aeroplane third = Aeroplane(FlyweightFactory::getModel(787), "20th Jan 1987", 100215);
	Aeroplane forth = Aeroplane(FlyweightFactory::getModel(380), "10th mar 1987", 200216);

	first.showDetails();
	second.showDetails();
	third.showDetails();
	forth.showDetails();
}



















