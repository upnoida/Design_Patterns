
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Usb
{
public:

	bool IsAvailable();

	void conenct();

	void send(string file);

};

bool Usb::IsAvailable()
{
	return true;
}

void Usb::conenct()
{
	cout << "Connected";
}

void Usb::send(string file)
{
	cout << file  << "Send the file" << endl;
}

class Bluetooth
{

public:

	bool isAvilable();

	void Connect();

	void Authenticate();

	void Send(string file);
};


bool Bluetooth::isAvilable()
{
	return true;
}

void Bluetooth::Connect()
{
	cout << "Connected to bluetooth" << endl;
}

void Bluetooth::Authenticate()
{
	cout << "Authenticated to bluetooth" << endl;
}

void Send(string file) {

	cout << file << "is sent" << endl;
}


class FileTransfer
{
public:
	void SendFile(string filename);
};


void FileTransfer::SendFile(string filename)
{
	Usb *usbptr = new Usb();
	Bluetooth *bprt = new Bluetooth();
	if (usbptr->IsAvailable())
	{
		usbptr->conenct();
		usbptr->send(filename);
	}
	else
	{
		bprt->isAvilable();
		bprt->Connect();
		bprt->Authenticate();
		bprt->Send(filename);
	}
}


void main()
{
	FileTransfer *fltransfer = new FileTransfer();
	fltransfer->SendFile("pic");


}























