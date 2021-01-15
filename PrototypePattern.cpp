#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class IPerson
{
public:

	IPerson(const string& name,int id):m_sName(name),m_id(id){}

	IPerson(const IPerson& person) {
		this->m_sName = person.m_sName;
		this->m_id = person.m_id;
	}

private:
	string m_sName;
	int m_id;


};

class Student :public IPerson
{
	Student(const string& sName,int id):IPerson(sName,id){}

	Student(const Student& student):IPerson(student){}

	IPerson* Clone()
	{
		return new Student(*this);
	}
};


class Teacher :public IPerson
{
	Teacher(const string& sName, int id) :IPerson(sName, id) {}

	Teacher(const Student& student) :IPerson(student) {}

	IPerson* Clone()
	{
		return new Teacher(*this);
	}
};

class Univeristy:













