##include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

class Chatroom;
class Person
{
public:
	string name;
	Chatroom* room = NULL;

	Person(const string&amp; n)
	{
		name = n;
	}

	void msg_receive(const string&amp; sender, const string&amp; msg);
	void msg_send(const string&amp; target, const string&amp; msg);
	void msg_broadcast(const string&amp; msg);
};

class Chatroom
{
public:
	vector <Person*> persons;

	void join(Person *p)
	{
		string msg_join = p->name + " Joins the chatroom";
		broadcast("chatroom", msg_join);
		p->room = this;
		persons.push_back(p);
	}

	void broadcast(const string&amp; sender, const string&amp; msg)
	{
		for (auto p : persons)
		{
			if (p->name != sender)
				p->msg_receive(sender, msg);
		}
	}

	void message(const string&amp; sender, const string&amp; receiver, const string&amp; msg)
	{
		for (auto p : persons)
		{
			if (p->name == receiver)
				p->msg_receive(sender, msg);
		}
	}
};

void Person::msg_receive(const string&amp; sender, const string&amp; msg)
{
	cout << name << " chat screen: " << sender << ": " << msg << endl;
}

void Person::msg_send(const string&amp; target, const string&amp; msg)
{
	room->message(name, target, msg);
}

void Person::msg_broadcast(const string&amp; msg)
{
	room->broadcast(name, msg);
}

int main()
{
	Chatroom room;

	Person im{ "IronMan" };
	Person ca{ "Captain America" };
	Person hu{ "Hulk" };

	room.join(&amp; im);
	room.join(&amp; ca);
	room.join(&amp; hu);

	ca.msg_broadcast("Hello Avengers !!! Ready for END GAME");
	im.msg_broadcast("Aye Aye Captain !!!");
	hu.msg_broadcast("Aye Aye Captain !!!");

	ca.msg_send("Hulk", "Smash everyone !!!");
	ca.msg_send("IronMan", "Tony close the gate!!!");
	return 0;
}