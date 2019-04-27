#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Employee {
  int ID;
  std::string all_info;
  std::string name;
  int age;
  std::string role;
  int salary;
};

int breakdown(std::string&,std::string&);
int ListEmployee();
void AddEmployee();
void SearchNamePrintString(Employee *,std::string,int);
void SearchEmployee();
void FireEmployee();
void EditEmployee();
void SearchSalary();
void AddAttribute(Employee *,int);
void ReadAttribute();
int EditAttribute(Employee *,int);
void Attribute();
void Bubblesortstring(std::string[],int);
void Bubblesortnumber(int[],int);
void Sort();

#endif
