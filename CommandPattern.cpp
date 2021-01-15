#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//https://www.bogotobogo.com/DesignPatterns/command.php

class Command
{
public:

	virtual void execute() = 0;
};

class Light
{
public:

	void On()
		{
			cout << "light is on" << endl;
		}
	void Off() {
		cout << "light is off" << endl;
	}

};

class LightOnCommand :public Command
{
public:
	LightOnCommand(Light *light):m_Light(light){}

	void execute() {
		mLight->On();
	}
private:
	Light *m_Light;
	


};
class LightOffCommand : public Command
{
public:
	LightOffCommand(Light *light) : mLight(light) {}
	void execute() {
		mLight->Off();
	}
private:
	Light *mLight;
};

// Invoker 
// Stores the ConcreteCommand object 
class RemoteControl
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	}
private:
	Command *mCmd;
};

// The client
int main()
{
	// Receiver 
	Light *light = new Light;

	// concrete Command objects 
	LightOnCommand *lightOn = new LightOnCommand(light);
	LightOffCommand *lightOff = new LightOffCommand(light);

	// invoker objects
	RemoteControl *control = new RemoteControl;

	// execute
	control->setCommand(lightOn);
	control->buttonPressed();
	control->setCommand(lightOff);
	control->buttonPressed();

	delete light, lightOn, lightOff, control;

	return 0;
}