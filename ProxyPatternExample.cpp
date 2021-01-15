#include "pch.h"
#include <iostream>
#include <vector>


//https://www.robertlarsononline.com/2017/05/26/proxy-pattern-using-cplusplus/


using namespace std;

class ZooPatron
{
public:
	ZooPatron(string name):m_name(name){}

	std::string GetName() { return m_name; }

	virtual bool HasAnimalShowAccess() = 0;
	virtual bool HasEarlyAccess() = 0;
private:
	string m_name;

};

class ZooGuest :public ZooPatron
{
public:
	ZooGuest(string name) :ZooPatron(name) {}
	virtual ~ZooGuest(){}

	bool HasAnimalShowAccess()
	{
		return false;
	}

	bool HasEarlyAccess()
	{
		return false;
	}

};

class ZooMember :public ZooPatron
{
public:
	ZooMember(string name) :ZooPatron(name) {}
	virtual ~ZooMember() {}

	bool HasAnimalShowAccess()
	{
		return true;
	}

	bool HasEarlyAccess()
	{
		return true;
	}
private:
	string m_Name;
};

class ZooInterface
{
public:
	virtual void EnterZooEarly(ZooPatron *patron) = 0;
	virtual void AttendAnimalShows(ZooPatron *patron) = 0;
};


class Zoo :public ZooInterface
{


};


