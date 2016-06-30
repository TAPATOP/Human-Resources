#pragma once
#include "Employee.h"

#include<string>
using namespace std;

class JDev :
	virtual public Employee
{
public:
	JDev();
	JDev(string name, string EGN, string address, string hiredWhen, string boss, string projectName) :Employee(name, EGN, address, hiredWhen, boss, projectName)
	{
		setPosition(JuniorDeveloper);
	}
	
	virtual void set();
	virtual void set(istream&);
	virtual void set(istream&, ostream& out);
	virtual void setFromKeyboardByName(istream&);
	virtual void display(ostream&)const;

	friend ostream& operator<<(ostream &out, JDev &employee);
	friend istream& operator>>(istream &in, JDev &employee);

	virtual ~JDev();
};

