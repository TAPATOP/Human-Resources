#include "JDev.h"
#include<iostream>

JDev::JDev()
{
	setPosition(JuniorDeveloper);
}

void JDev::set()
{
	Employee::set();
	setPosition(JuniorDeveloper);
}
void JDev::set(istream& in)
{
	Employee::set(in);
	this->setPosition(JuniorDeveloper);
}
void JDev::set(istream& in, ostream& out)
{
	Employee::set(in,out);
	setPosition(JuniorDeveloper);
}
void JDev::setFromKeyboardByName(istream& in)
{
	Employee::setFromKeyboardByName(in);
	setPosition(JuniorDeveloper);
}
void JDev::display(ostream& out)const
{
	Employee::display(out);
}

ostream& operator<<(ostream &out, JDev &employee)
{
	out << "Name: " << employee.getName() << endl;
	out << "address: " << employee.getAddress() << endl;
	out << "Was hired: " << employee.getHiredWhen() << endl;
	out << "Boss: " << employee.getBoss() << endl;
	employee.displayPosition(out);
	out << "Working on: " << employee.getProject() << endl;
	return out;
}
istream& operator>>(istream &in, JDev &employee)
{
	employee.set(in);
	return in;
}


JDev::~JDev()
{
}
