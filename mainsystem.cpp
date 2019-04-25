#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <sstream>
#include <iomanip>
//#include "filein.h"
//#include "functions.h"

using namespace std;

int breakdown(string &str,string &name) {
  locale loc;
  bool detectdigit=true;
  int age;
  for (int i=0;i<str.length();i++) {
    if (detectdigit==true) {
      if (isdigit(str[i],loc)){
        name=str.substr(0,i-1);
        string sub=str.substr(i,str.length()-i);
        stringstream(sub) >> age;
        detectdigit=false;
      }
    } else {
      if (isalpha(str[i],loc)) {
        string remain=str.substr(i,str.length()-i);
        str=remain;
      }
    }
  }
  return age;
}

struct Employee {
  int ID;
  string all_info;
  string name;
  int age;
  string role;
  int salary;
};
int ListEmployee() {
  string stopper;
  ifstream fin;
  fin.open("employees.txt");
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  ifstream fintemp;
  fintemp.open("employees.txt");
  if (fintemp.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
 int count=1;
 int total=0,x;
 string s;
 while (fintemp>>x) {
   getline(fintemp,s);
   total++;
 }
 fintemp.close();
 Employee *list=new Employee [total];
 cout<<setfill(' ');
 cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
  <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
 while(fin>>list[count-1].ID) {
  getline(fin,list[count-1].all_info);
  int i=count-1;
  list[i].age=breakdown(list[i].all_info,list[i].name);
  list[i].salary=breakdown(list[i].all_info,list[i].role);
  cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
    <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
  count++;
  }
  fin.close();
  delete [] list;
  return 0;
}

void AddEmployee()
{
  string stopper;
  int id,age,salary;
  string name,role;
  cout<<"Enter ID :\n";
  cin>>id;
  cout<<"Enter Name :\n";
  cin>>ws;
  getline(cin,name);
  cout<<"Enter Age :\n";
  cin>>age;
  cout<<"Enter Role :\n";
  cin>>ws;
  getline(cin,role);
  cout<<"Enter Salary :\n";
  cin>>salary;
  cout<<"A new employee has been added !"<<endl;
  ofstream fout;
  fout.open("employees.txt",ios::app);
  if (fout.fail()) {
    cout<<"Error in file opening!"<<endl;
    exit(1);
  }
  fout<<id<<" "<<name<<" "<<age<<" "<<role<<" "<<salary<<endl;
  fout.close();
}

void SearchNamePrintString(Employee *list,string key,int total) {
  cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
   <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
   for (int i=0;i<total;i++) {
     if (key.length()<=list[i].name.length()){
       for (int j=0;j<list[i].name.length()-key.length()+1;j++){
         if (list[i].name.substr(j,key.length())==key) {
           cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
          }
        }
      }
   }
  cout<<"\n\n\n";
}

void SearchEmployee() {
  ifstream fin;
  fin.open("employees.txt");
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  ifstream fintemp;
  fintemp.open("employees.txt");
  if (fintemp.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
 int count=1;
 int total=0,x;
 string s;
 while (fintemp>>x) {
   getline(fintemp,s);
   total++;
 }
 fintemp.close();
 Employee *list=new Employee [total];
 while(fin>>list[count-1].ID) {
  getline(fin,list[count-1].all_info);
  int i=count-1;
  list[i].age=breakdown(list[i].all_info,list[i].name);
  list[i].salary=breakdown(list[i].all_info,list[i].role);
  count++;
  }
  fin.close();
  cout<<setfill(' ');
  int option;
  while (option!=0) {
    cout<<"You can search by:\n1. ID \n2. name \n3. age \n4. role \n\n0. Exit Searching\n"<<endl;
    cout<<"Option: "<<endl;
    cin>>option;
    system("cls");
    cout<<"Search for: ";
    switch (option) {
      case 1:
      {int x;
      cin>>x;
      cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
      for (int i=0;i<total;i++) {
        if (list[i].ID==x) {
          cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
        }
      }
      cout<<"\n\n\n";
      break;}
      case 2:
      {string y;
      cin>>ws;
      getline(cin,y);
      SearchNamePrintString(list,y,total);
      break;}
      case 3:
      {int z;
      cin>>z;
      cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
      for (int i=0;i<total;i++) {
        if (list[i].age==z) {
          cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
        }
      }
      cout<<"\n\n\n";
      break;}
      case 4:
      {string a;
      cin>>ws;
      getline(cin,a);
      cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
       for (int i=0;i<total;i++) {
         if (a.length()<=list[i].role.length()){
           for (int j=0;j<list[i].role.length()-a.length()+1;j++){
             if (list[i].role.substr(j,a.length())==a) {
               cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
                <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
              }
            }
          }
       }
      cout<<"\n\n\n";
      break;}
      case 0:
      break;
      default:
      cout<<"Error! Please choose one of the options."<<endl;
    }
  }

  delete [] list;
}

void FireEmployee() {
  ifstream fin;
  fin.open("employees.txt");
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  ifstream fintemp;
  fintemp.open("employees.txt");
  if (fintemp.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
 int count=1;
 int total=0,x;
 string s;
 while (fintemp>>x) {
   getline(fintemp,s);
   total++;
 }
 fintemp.close();
 Employee *list=new Employee [total];
 while(fin>>list[count-1].ID) {
  getline(fin,list[count-1].all_info);
  int i=count-1;
  list[i].age=breakdown(list[i].all_info,list[i].name);
  list[i].salary=breakdown(list[i].all_info,list[i].role);
  count++;
  }
  fin.close();
  cout<<"Please enter the employee's id: ";
  int del;
  string confirm;
  cin>>del;
  bool exist=true;
  for (int i=0;i<total;i++) {
    if (list[i].ID==del){
      break;
    } else if (i==total-1) {
      cout<<"The employee does not exist!\n\n\n";
      exist=false;
    }
  }
  while (exist) {
    cout<<"Are you sure you want to delete this employee's information? Y/N ";
    cin>>confirm;
    if (confirm=="Y") {
      ofstream fout;
      fout.open("employees.txt");
      if (fout.fail()) {
        cout<<"Error in file opening!"<<endl;
        exit(1);
      }
      for (int i=0;i<total;i++) {
        if (list[i].ID==del){
          continue;
        }
        fout<<list[i].ID<<list[i].name<<" "<<list[i].age<<" "<<list[i].role<<" "<<list[i].salary<<endl;
      }
      fout.close();
      cout<<"Employee Removed\n\n\n";
      break;
    } else if (confirm=="N") {
      cout<<"Deletion Terminated\n\n\n";
      break;
    } else {
      cout<<"Error! Please type Y/N"<<endl;
    }
  }
}


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
    cout<<"7. Add a defined attribute"<<endl;
    cout<<"8. Show the current project an employee is engaging in"<<endl;
    cout<<"9. Add remark to an employee"<<endl;
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
      case 0:
      cout<<"Thanks for using."<<endl;
      exit(1);
      default:
        cout<<"Error! Please choose one of the options."<<endl;
    }
  }


}
