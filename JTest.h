#pragma once
#include "Employee.h"
class JTest :
	virtual public Employee
{
public:
	JTest();
	JTest(string name, string EGN, string address, string hiredWhen, string boss, string projectName, string OS) :Employee(name, EGN, address, hiredWhen, boss, projectName)
	{
		this->OS = OS;
		setPosition(JuniorTester);
	}

	void setOS(string);

	string getOS();

	virtual void set();

	virtual void set(istream&);
	virtual void set(istream&, ostream& out);
	virtual void setFromKeyboardByName(istream&);
	virtual void display(ostream&)const;

	friend ostream& operator<<(ostream &out, JTest &employee);
	friend istream& operator>>(istream &in, JTest &employee);

	virtual ~JTest();

private:
	string OS;
};

