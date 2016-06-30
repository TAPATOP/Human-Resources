#pragma once
#include"JDev.h"
#include"JTest.h"
#include<string>

using namespace std;

class SDev: public JDev, public JTest
{
public:
	SDev();
	SDev(string name, string EGN, string address, string hiredWhen, string boss, string projectName, string OS) :JTest(name, EGN, address, hiredWhen, boss, projectName,OS)
	{
		setPosition(SeniorDeveloper);
	}

	virtual void set();
	virtual void set(istream&);
	virtual void set(istream&, ostream& out);
	virtual void setFromKeyboardByName(istream&);
	virtual void display(ostream&)const;

	friend ostream& operator<<(ostream &out, SDev &employee);
	friend istream& operator>>(istream &in, SDev &employee);

	virtual ~SDev();
};