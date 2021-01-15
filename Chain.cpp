#include "pch.h"
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class Request
{
public:
	Request(int num) {
		m_Num = num;
	}

	int getNum() {
		return m_Num;
	}
private:
	int m_Num;
};

class Handler
{
public:
	Handler(Handler *handler = nullptr):m_handler(handler){}

	Handler* getNextHandler(){
		return m_handler;
	}

	void setNextHandler(Handler *handler){
		m_handler = handler;
	}

	virtual void HandleRequest(Request request){}

private:
	Handler *m_handler;

};

class ConcreteHandlerOne :public Handler
{
public:
	void HandleRequest(Request request)
	{
		int val = request.getNum();
		if (val < 0) {
			cout << "Handler with -ve no is called" << endl;
		}
		else
		{
			getNextHandler()->HandleRequest(request);
		}
	}
};

class ConcreteHandlerOne :public Handler
{
public:
	void HandleRequest(Request request)
	{
		int val = request.getNum();
		if (val < 0) {
			cout << "Handler with -ve no is called" << endl;
		}
		else
		{
			getNextHandler()->HandleRequest(request);
		}
	}
};


class ConcreteHandleThree :public Handler
{
public:
	void HandleRequest(Request request)
	{
		int val = request.getNum();
		if (val > 0) {
			cout << "Handler with +ve no is called" << endl;
		}
		else
		{
			getNextHandler()->HandleRequest(request);
		}
	}
};



int main()
{
	Handler* handler1 = new ConcreteHandleThree();
	Handler* handler2 = new ConcreteHandleThree();
	Handler* handler3 = new ConcreteHandleThree();

	handler1->setNextHandler(handler2);
	handler2->setNextHandler(handler3);

	handler1->HandleRequest(Request(2));
	handler1->HandleRequest(Request(-1));
	handler1->HandleRequest(Request(0));

	system("pause");
	return 0;
}







