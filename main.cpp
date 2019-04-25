#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//#include "filein.h"
//#include "functions.h"
using namespace std;
int main()
{
  string DataFile;
  int choice;
  //
  cout<<"Initialization"<<endl;
  cout<<"Please enter the name of the file that \nincludes employee's information :";
  cin>>DataFile;
  //readfile(DataFile) //from "filein"
  //need this part?
  cout<<setfill('-');
  cout<<setw(17)<<' '<<"Staff Management System"<<setw(17)<<' '<<endl;
  cout<<"Menu"<<endl;
  cout<<"1: List all employees"<<endl;
  cout<<"2: Add a new employee"<<endl;
  cout<<"3: Search for an employee"<<endl;
  cout<<"4. Fire an employee"<<endl;
  cout<<"5. Edit the information of an existing employee"<<endl;
  cout<<"6. Search for employees according to the salary level"<<endl;
  cout<<"7. Add a defined attribute"<<endl;
  cout<<"8. Show the current project an employee is engaging in"<<endl;
  cout<<"9. Add remark to an employee"<<endl;
  cout<<"0. Exit the system"<<endl;
  cout<<setw(57)<<' '<<endl;
  cout<<"Please enter your choice :";
  cin>>choice;
  switch(choice)
  {
    case 1:
     //ListEmployee();
     break; 
    case 2:
    //AddEmployee();
    break;
    case 3:
    //SearchEmployee();
    break;
    case 4:
    //FireEmployee();
    break;
    case 5:
    //EditEmployee();
    break;
    case 6:
    //SearchSalary();
    break;
    case 7:
    //AddAttribute();
    break;
    case 8:
    //ShowProject();
    break;
    case 9:
    //AddRemark();
    break;
    case 0:
    cout<<"Thanks for using."<<endl;
    exit(1);
    default:
      cout<<"Error! Please choose one of the options."<<endl;
  }

}
