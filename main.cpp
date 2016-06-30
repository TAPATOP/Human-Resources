#include<iostream>
#include<string>
#include<regex>

#include"Company.h"
#include"Employee.h"
#include"JDev.h"
#include"JTest.h"
#include"SDev.h"

using namespace std;


bool menu(Company &company, int command)
{
	switch (command)
	{
	case 1:
	{
			  cout << "Insert company name, address and CEO:" << endl;
			  cin >> company;

			  return 1;
	}
	case 2:
	{
			  cout << "These are the company's name, address and CEO:" << endl;
			  cout << company;
			  return 1;
	}

	case 3:
	{
			 int type;
			 Employee* a = new Employee();

			 //just menu, bro
			 cout <<endl<< "Choose the type of Employee you're about to add:" << endl << "1. Junior Programmer" << endl << "2. Junior Tester" << endl << "3. Senior Programmer" << endl;
			 
			 cin >> type;
			  

			  switch (type)
			  {
			  case 1: delete a; a = new JDev(); break;
			  case 2: delete a; a = new JTest(); break;
			  case 3: delete a; a = new SDev(); break;
			  default:
			  {
						 cout << "Incorrect position..." << endl;
						 cin.clear();
						 cin.ignore(10000, '\n');
						 return 1;
			  }
			  }

			  cout << "Enter employee name, EGN, adress, hire date, boss, project and maybe even OS:"<<endl<<endl;
			 cin >> *a;
			 company.addEmployee(a);
			 cout << endl;
			  return 1;
	}

	case 4:
	{
			  string EGN;
			  cout << "Enter EGN:"; cin >> EGN;
			  cout << endl;
			  if (!company.displayEmployeeByEGN(EGN,cout)) cout << "No Employee with the EGN: " << EGN << " found..." << endl;
			  return 1;
	}
	case 5:
	{
			  string EGN;
			  cout << "Input EGN of the victim:"; cin >> EGN;
			  cout << endl;
			  if (!company.fireEmployee(EGN,cout))  cout << "No Employee with the EGN: " << EGN << " found..." << endl;
			  return 1;
	}
	case 6:
	{
			  string name;
			  cin.clear();
			  cin.ignore(1);
			  cout << "Input Name of the Employee to be changed:"; getline(cin, name);
			  cout << endl;
			  if (!company.employeeExists(name))
			  {
				  cout << "No Employee with the name: " << name << " found..." << endl;
				  return 1;
			  }

			  int type;
			  cout << "Choose the type of Position the Employee is going to take:" << endl << "1. Junior Programmer" << endl << "2. Junior Tester" << endl << "3. Senior Programmer" << endl;
			  cin >> type;

			  Employee* a = new Employee();

			  switch (type)
			  {
			  case 1: delete a; a = new JDev(); break;
			  case 2: delete a; a = new JTest(); break;
			  case 3: delete a; a = new SDev(); break;
			  default:
			  {
						 cout << "Incorrect position..." << endl;
						 return 1;
			  }
			  }

			  a->setName(name);
			  a->setFromKeyboardByName(cin);
			  if (!company.updateEmployee(*a))  cout << "No Employee with the name: " << name << " found..." << endl;
			  return 1;
	}
	case 7:
	{
			  string query;
			  cin.clear();
			  cin.ignore(1);
			  cout << "Insert Project name to search for employees by: "; getline(cin,query);
			  cout << endl;
			  if (!company.displayEmployeesByProject(query,cout))  cout << "No Project with the name: " << query << " found..." << endl;
			  return 1;
	}
	case 8:
	{

			  return 0;
	}
	default:
	{
			   cout << endl << "Unregognized command..." << endl; 

			   cin.clear();
			   cin.ignore(10000, '\n');
			   return 1;
	}
	}

	cout << endl << "List of all employees:" << endl;
	company.displayUs(cout);
}

int main()
{
	cout << "Welcome to the HR program! In order to execute orders, please input the numbers displayed in front of the desired order. At the end of each command you're going to receive a list of all Employees of the company simply for convenience" << endl << endl;
	
	int command;
	Company company;
	while (true)
	{
		cout << "1. Enter Company info" << endl << "2. Display Company info" << endl << "3. Add an Employee" << endl << "4. Display Employee info by EGN" << endl << "5. Fire Employee" << endl << "6. Change Employee info" << endl << "7. Display Employees working on a given project"<< endl <<"8. Exit" << endl;
		cout << endl << "Select command: "; cin >> command;
		while (!cin)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl << "Incorrect command, retry your input: "; cin >> command;
		}

		cout << endl;
		if (menu(company, command))
		{

			cout << endl << "List of all employees:" << endl;
			if (!company.displayUs(cout)) cout << "The list is empty..." << endl<<endl;
			continue;
		}
		cin.clear();
		cin.ignore(10000,'\n');
		if(command == 8) break;
	}
	return 0;
}
//end