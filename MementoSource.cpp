#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Memento
{
private:
	int state;
public:
	Memento(const int s):state(s){}

	void SetState(const int s)
	{
		state = s;
		cout << "Set state is" << state << endl;
	}


	int GetState()
	{
		return state;
	}


};

class Originator
{
private:
	int state;
public:

	void SetState(const int s) {
		cout << "Set state is" << s << endl;
	}

	int GetState()
	{
		return state;
	}

	void SetMemento(Memento* const mem)
	{
		state = mem->GetState();
	}

	Memento* CreateMemento()
	{
		return new Memento(state);
	}
};


class CareTaker
{
private:
	Originator *orignator;
	vector<Memento*> *history;
public:
	CareTaker(Originator* const o):orignator(o) {}

	void Save()
	{
		cout << "State is saving" << endl;
		history->push_back(originator->createMEMENTO())
	}





};












