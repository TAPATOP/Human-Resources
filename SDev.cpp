#include "SDev.h"


SDev::SDev()
{
	setPosition(SeniorDeveloper);
}

void SDev::set()
{
	JTest::set();
	setPosition(SeniorDeveloper);
}
void SDev::set(istream& in)
{
	JTest::set(in);
	setPosition(SeniorDeveloper);
}
void SDev::set(istream& in, ostream& out)
{
	JTest::set(in,out);
	setPosition(SeniorDeveloper);
}
void SDev::setFromKeyboardByName(istream& in)
{
	JTest::setFromKeyboardByName(in);
	setPosition(SeniorDeveloper);
}

void SDev::display(ostream& out)const
{
	JTest::display(out);
}

ostream& operator<<(ostream &out, SDev &employee)
{
	out << "Name: " << employee.getName() << endl;
	out << "address: " << employee.getAddress() << endl;
	out << "Was hired: " << employee.getHiredWhen() << endl;
	out << "Boss: " << employee.getBoss() << endl;
	employee.displayPosition(out);
	out << "Working on: " << employee.getProject() << endl;
	out << "OS: " << employee.getOS() << endl;
	return out;
}
istream& operator>>(istream &in, SDev &employee)
{
	employee.set(in);
	return in;
}
SDev::~SDev()
{
}
