#include "JTest.h"
#include<iostream>

using namespace std;

JTest::JTest()
{
	OS = "noOS";
	setPosition(JuniorTester);
}

void JTest::setOS(string OS)
{
	this->OS = OS;
}

string JTest::getOS()
{
	return OS;
}

void JTest :: set()
{
	Employee::set();
	
	string OS;
	getline(cin, OS);
	this->OS = OS;
	setPosition(JuniorTester);
}
void JTest::set(istream& in)
{
	Employee::set(in);

	string OS;
	getline(cin, OS);
	this->OS = OS;
	setPosition(JuniorTester);
}
void JTest::set(istream& in, ostream& out)
{
	Employee::set(in,out); string OS;


	getline(in, OS);
	this->OS = OS;
	setPosition(JuniorTester);
}
void JTest::setFromKeyboardByName(istream& in)
{
	Employee::setFromKeyboardByName(in);

	string OS;
	getline(cin, OS);
	this->OS = OS;
	setPosition(JuniorTester);
}
void JTest::display(ostream& out)const
{
	Employee::display(out);
	out << "OS:" << OS << endl;
}

ostream& operator<<(ostream &out, JTest &employee)
{
	out << "Name: " << employee.getName() << endl;
	out << "address: " << employee.getAddress() << endl;
	out << "Was hired: " << employee.getHiredWhen()<< endl;
	out << "Boss: " << employee.getBoss() << endl;
	employee.displayPosition(out);
	out << "Working on: " << employee.getProject() << endl;
	out << "OS: " << employee.OS << endl;
	return out;
}
istream& operator>>(istream &in, JTest &employee)
{
	employee.set(in);
	return in;
}
JTest::~JTest()
{
}
