#include "Employee.h"
#include<iostream>
#include<regex>
using namespace std;

Employee::Employee()
{
	name="noName";
	EGN = "0000000000";
	address= "noAddress";
	hiredWhen="noInfo";
	boss="noOne";
	position = (Position)0;
	projectName = "noProject";
}
Employee::Employee(string name, string EGN, string address, string hiredWhen, string boss, string projectName)
{
	this->name = name;
	this->EGN = EGN;
	this->address = address;
	this->hiredWhen = hiredWhen;
	this->boss = boss;
	this->position = (Position)0;
	this->projectName = projectName;
}

bool Employee::setName(string name)
{
	if (validateName(name))
	{
		this->name = name;
		return 1;
	}
	return 0;
}
bool Employee::setEGN(string EGN)
{
	if(validateEGN(EGN))
	{
		this->EGN = EGN;
		return 1;
	}
	else
	{
		return 0;
	}
}
void Employee::setAddress(string address)
{
	this->address = address;
}
void Employee::setHiredWhen(string hiredWhen)
{
	this->hiredWhen = hiredWhen;
}
void Employee::setBoss(string boss)
{
	this->boss = boss;
}
void Employee::setPosition(Position position)
{
	this->position = position;
}
void Employee::setProject(string projectName)
{
	this->projectName = projectName;
}


string Employee::getName()const
{
	return name;
}
string Employee::getEGN()const
{
	return EGN;
}
string Employee::getAddress()const
{
	return address;
}
string Employee::getHiredWhen()const
{
	return hiredWhen;
}
string Employee::getBoss()const
{
	return boss;
}
Position Employee::getPosition()const
{
	return position;
}
string Employee::getProject()const
{
	return projectName;
}

void Employee::set()
{
	string name;
	cin.clear();
	cin.ignore(1);
	while (true)
	{
		cout << "Input name:"; getline(cin, name);
		if (validateName(name))
		{
			this->name = name;
			break;
		}
		cout << "Try again..." << endl;
	}

	string EGN;

	
	while (true)
	{
		cin >> EGN;
		if (!validateEGN(EGN))
		{
			cout << "Inavlid EGN" << endl;
			continue;
		}
		break;
	}
		this->EGN = EGN;

	cin.clear();
	cin.ignore(1);
	string address;
	cout << "Address:"; getline(cin, address);
	this->address = address;
	
	string hiredWhen;
	cout << "When was this Employee hired:"; getline(cin, hiredWhen);
	this->hiredWhen = hiredWhen;

	string boss;
	cout << "Boss:"; getline(cin, boss);
	this->boss = boss;

	this->position = (Position)0;
	
	string projectName;
	cout << "Which project is the Employee working on: "; getline(cin, projectName);
	this->projectName = projectName;
}
void Employee::set(istream& in)
{
	string name;
	in.clear();
	in.ignore(1);
	while (true)
	{
		getline(in, name);
		if (validateName(name))
		{
			this->name = name;
			break;
		}
	}

	string EGN;


	while (true)
	{
		in >> EGN;
		if (!validateEGN(EGN))
		{
			continue;
		}
		break;
	}
	this->EGN = EGN;

	in.clear();
	in.ignore(1);
	string address;
	getline(in, address);
	this->address = address;

	string hiredWhen;
	getline(in, hiredWhen);
	this->hiredWhen = hiredWhen;

	string boss;
	getline(in, boss);
	this->boss = boss;

	this->position = (Position)0;

	string projectName;
	getline(in, projectName);
	this->projectName = projectName;
}
void Employee::set(istream& in, ostream& out)
{
	string name;
	in.clear();
	in.ignore(1);
	while (true)
	{
		getline(in, name);
		if (validateName(name))
		{
			this->name = name;
			break;
		}
		out << "Try again..." << endl;
	}

	string EGN;


	while (true)
	{
		in >> EGN;
		if (!validateEGN(EGN))
		{
			out << "Inavlid EGN" << endl;
			continue;
		}
		break;
	} 

	this->EGN = EGN;

	in.clear();
	in.ignore(1);
	string address;
	getline(in, address);
	this->address = address;

	string hiredWhen;
	getline(in, hiredWhen);
	this->hiredWhen = hiredWhen;

	string boss;
	getline(in, boss);
	this->boss = boss;

	this->position = (Position)0;

	string projectName;
	getline(in, projectName);
	this->projectName = projectName;
}
void Employee::setFromKeyboardByName(istream& in)
{
	string EGN;

	in >> EGN;
	while (!validateEGN(EGN))
	{
		in.clear();
		in.ignore(10000, '\n');
		in >> EGN;
	}
	this->EGN = EGN;

	in.clear();
	in.ignore(1);
	string address;
	getline(in, address);
	this->address = address;

	string hiredWhen;
	getline(in, hiredWhen);
	this->hiredWhen = hiredWhen;

	string boss;
	getline(in, boss);
	this->boss = boss;

	string projectName;
	getline(in, projectName);
	this->projectName = projectName;
}
void Employee::display(ostream& out)const
{
	out << "Name: "<< name << endl;
	out << "address: " << address << endl;
	out << "Was hired: " << hiredWhen << endl;
	out << "Boss: " << boss << endl;
	displayPosition(out);
	out << "Working on: " << projectName << endl;
}
void Employee::displayPosition(ostream& out)const
{
	switch (position)
	{
	case Unknown:out << "Unknown position"; break;
	case JuniorDeveloper:out << "Junior Developer"; break;
	case JuniorTester:out << "Junior Tester"; break;
	case SeniorDeveloper:out << "Senior Developer"; break;
	}
	out << endl;
}
bool Employee::validateName(string name)const
{
	regex something("[a-zA-Z\\s]*");
	if (regex_match(name,something))
	{
		return 1;
	}
	return 0;
}
bool Employee::validateEGN(string EGN)const
{
	regex something("[0-9]{10}");
	if ((regex_match(EGN, something)) && (( (EGN[0] - 48) * 10 + EGN[1] - 48)!=currentYear%100))
		{
			return 1;
		}

		return 0;
}


ostream& operator<<(ostream &out, Employee &employee)
{
	out << "Name: " << employee.name << endl;
	out << "EGN:" << employee.EGN << endl;
	out << "Address: " << employee.address << endl;
	out << "Was hired: " << employee.hiredWhen << endl;
	out << "Boss: " << employee.boss << endl;
	employee.displayPosition(out);
	out << "Working on: " << employee.projectName << endl;
	return out;
}
istream& operator>>(istream &in, Employee &employee)
{
	employee.set(in);
	return in;
}

Employee::~Employee()
{
}
