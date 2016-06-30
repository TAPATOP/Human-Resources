	#pragma once
#include<string>
using namespace std;
const int currentYear = 2016;

enum Position
{
	Unknown,
	JuniorDeveloper,
	JuniorTester,
	SeniorDeveloper
};


class Employee
{
public:
	Employee();
	Employee(string name, string EGN, string address, string hiredWhen, string boss, string projectname);

	bool setName(string);
	bool setEGN(string);
	void setAddress(string);
	void setHiredWhen(string);
	void setBoss(string);
	void setPosition(Position);	
	void setProject(string);
	
	string getName()const;
	string getEGN()const;
	string getAddress()const;
	string getHiredWhen()const;
	string getBoss()const;
	Position getPosition()const;
	string getProject()const;

	virtual void set();
	virtual void set(istream&);
	virtual void set(istream&, ostream& out);
	virtual void setFromKeyboardByName(istream&);
	virtual void display(ostream&)const;
	void displayPosition(ostream&)const;
	bool validateName(string)const;
	bool validateEGN(string)const;

	friend ostream& operator<<(ostream &out, Employee &employee);
	friend istream& operator>>(istream &in, Employee &employee);

	virtual ~Employee();

private:
	string name;
	string EGN;
	string address;
	string hiredWhen;
	string boss;
	Position position;
	string projectName;
};