#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include "functions.h"

using namespace std;

int main()
{
  //string DataFile;
  int choice;
  //
  //cout<<"Initialization"<<endl;
  //cout<<"Please enter the name of the file that \nincludes employee's information :";
  //cin>>DataFile;
  //readfile(DataFile) //from "filein"
  //need this part?
  while (true) {
    cout<<setfill('-');
    cout<<setw(17)<<' '<<"Staff Management System"<<setw(17)<<' '<<endl;
    cout<<"Menu"<<endl;
    cout<<"1: List all employees"<<endl;
    cout<<"2: Add a new employee"<<endl;
    cout<<"3: Search for an employee"<<endl;
    cout<<"4. Fire an employee"<<endl;
    cout<<"5. Edit the information of an existing employee"<<endl;
    cout<<"6. Search for employees according to the salary level"<<endl;
    cout<<"7. Add/Modify/Show a custom attribute"<<endl;
    cout<<"8. View employees (sorted by name/age/salary)"<<endl;
    cout<<"0. Exit the system"<<endl;
    cout<<setw(57)<<' '<<endl;
    cout<<"Please enter your choice :";
    cin>>choice;
    system("cls");
    switch(choice)
    {
      case 1:
       ListEmployee();
       break;
      case 2:
      AddEmployee();
      break;
      case 3:
      SearchEmployee();
      system("cls");
      break;
      case 4:
      FireEmployee();
      break;
      case 5:
      EditEmployee();
      break;
      case 6:
      SearchSalary();
      break;
      case 7:
      Attribute();
      break;
      case 8:
      Sort();
      break;
      case 0:
      cout<<"Thanks for using."<<endl;
      exit(1);
      default:
        cout<<"Error! Please choose one of the options."<<endl;
    }
  }


}
