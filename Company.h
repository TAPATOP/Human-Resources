#pragma once
#include<string>
#include<vector>
#include"Employee.h"
using namespace std;

class Company
{
public:
	Company();
	Company(string name, string address, string CEO);
	Company(const Company& other);

	void setName(string);
	void setAddress(string);
	void setCEO(string);
	void setCompany(string name, string address, string CEO);

	string getName() const;
	string getAddress()const;
	string getCEO()const;

	void displayCompany(ostream&)const;
	void addEmployee(Employee*);
	bool displayUs(ostream&)const;
	bool displayEmployeeByEGN(string EGN, ostream&)const;
	bool fireEmployee(string EGN, ostream&);
	bool updateEmployee(Employee&);
	bool displayEmployeesByProject(string project, ostream&)const;
	bool employeeExists(string name)const;

	friend ostream& operator<<(ostream&, Company&);
	friend istream& operator>>(istream&, Company&);
	~Company();
private:
	string name;
	string address;
	string CEO;
	vector <Employee*> staff;
};

