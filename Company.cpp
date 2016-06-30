#include<iostream>

#include "Company.h"

using namespace std;

Company::Company()
{
	name="noName";
	address="nowhere";
	CEO="noOne";
}

Company::Company(string name, string address, string CEO)
{
	this->name = name;
	this->address = address;
	this->CEO = CEO;
}
Company::Company(const Company& other)
{
	this->name = other.name;
	this->address = other.address;
	this->CEO = other.CEO;
	
	int size = other.staff.size();

	for (int i = 0; i < size; i++)
	{
		addEmployee(other.staff[i]);
	}
}

void Company::setName(string name)
{
	this->name = name;
}
void Company::setAddress(string address)
{
	this->address = address;
}
void Company::setCEO(string CEO)
{
	this->CEO = CEO;
}
void Company::setCompany(string name, string address, string CEO)
{

	this->name = name;
	this->address = address;
	this->CEO = CEO;
}

string Company::getName()const
{
	return name;
}
string Company::getAddress()const
{
	return address;
}
string Company::getCEO()const
{
	return CEO;
}

void Company::displayCompany(ostream& out)const
{
	out << "Company name: " << name << endl;
	out << "Address: " << address << endl;
	out << "CEO: " << CEO << endl;
}
void Company::addEmployee(Employee* newGuy)
{
	staff.push_back(newGuy);
}
bool Company::displayUs(ostream &out)const
{
	bool isNotEmpty=0;
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		out << staff[i]->getName() << endl;
		isNotEmpty = 1;
	}
	out << endl;
	return isNotEmpty;
}
bool Company::displayEmployeeByEGN(string EGN, ostream& out)const
{
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		if (staff[i]->getEGN() == EGN)
		{
			staff[i]->display(out);
			return 1;
		}
	}
	return 0;
}
bool Company::fireEmployee(string EGN, ostream& out)
{
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		if (staff[i]->getEGN() == EGN)
		{
			out << staff[i]->getName() << " has been fired!" << endl;
			staff.erase(staff.begin()+i);
			return 1;
		}
	}
	return 0;
}
bool Company::updateEmployee(Employee& update)
{
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		if (update.getName() == staff[i]->getName())
		{
			delete staff[i];
			staff[i] = &update;
			return 1;
		}
	}
	return 0;
}
bool Company::displayEmployeesByProject(string project, ostream &out)const
{
	bool projectExists = 0;
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		if (staff[i]->getProject() == project)
		{
			out<<staff[i]->getName()<<endl;
			projectExists = 1;
		}
	}
	return projectExists;
}
bool Company::employeeExists(string name)const
{
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		if (staff[i]->getName() == name)
		{
			return 1;
		}
	}
	return 0;
}

ostream& operator<<(ostream& out, Company& company)
{
	out << company.name << endl;
	out << company.address << endl;
	out << company.CEO << endl;
	return out;
}
istream& operator>>(istream& in, Company& company)
{
	in.clear();
	in.ignore(1);
	getline(in, company.name);
	getline(in, company.address);
	getline(in, company.CEO);
	return in;
}

Company::~Company()
{
	int size = staff.size();
	for (int i = 0; i < size; i++)
	{
		delete staff[i];
	}
}
