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
  cout<<"1: Add a new employee"<<endl;
  cout<<"2: Search for an employee"<<endl;
  cout<<"3. Fire an employee"<<endl;
  cout<<"4. Edit the information of an existing employee"<<endl;
  cout<<"5. Search for employees according to the salary level"<<endl;
  cout<<"6. Add a defined attribute"<<endl;
  cout<<"7. Show the current project an employee is engaging in"<<endl;
  cout<<"8. Add remark to an employee"<<endl;
  cout<<"9. Exit the system"<<endl;
  cout<<setw(57)<<' '<<endl;
  cout<<"Please enter your choice :";
  cin>>choice;
  switch(choice)
  {
    case 1:
    //AddEmployee();
    break;
    case 2:
    //SearchEmployee();
    break;
    case 3:
    //FireEmployee();
    break;
    case 4:
    //EditEmployee();
    break;
    case 5:
    //SearchSalary();
    break;
    case 6:
    //AddAttribute();
    break;
    case 7:
    //ShowProject();
    break;
    case 8:
    //AddRemark();
    break;
    case 9:
    cout<<"Thanks for using."<<endl;
    exit(1);
  }

}
