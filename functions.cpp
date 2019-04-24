#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//#include "filein.h"
//#include "functions.h"
using namespace std;
void AddEmployee()
{
  cout<<"Enter Name :";
  cin>>list[total].name;
  cout<<endl<<"Enter Age :";
  cin>>list[total].age;
  cout<<endl<<"Enter Role :";
  cin>>list[total].role;
  cout<<endl<<"Enter Salary :";
  cin>>list[total].salary;
  cout<<"A new employee has been added !"<<endl;
  total++;
}
