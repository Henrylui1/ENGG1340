#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include "functions.h"

using namespace std;

int breakdown(string &str,string &name) {                   	// a function to breakdown a line string of info of 
  locale loc;                                                	// one employee into separated attributes
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

int ListEmployee() {						//List all employees by entering order
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
 cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"			//formatted output of attribute titles
  <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
 while(fin>>list[count-1].ID) {
  getline(fin,list[count-1].all_info);
  int i=count-1;
  list[i].age=breakdown(list[i].all_info,list[i].name);
  list[i].salary=breakdown(list[i].all_info,list[i].role);
  cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age	//formatted output of staff info
    <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
  count++;											
  }
  fin.close();
  delete [] list;
  return 0;
}

void AddEmployee()                //Add a new employee to the system
{
  int id,age,salary;
  string name,role;
  cout<<"Enter ID :\n";           //Get the information of the new employee
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
  cout<<"A new employee has been added !"<<endl;   //Show that the new employee is added to the system
  ofstream fout;
  fout.open("employees.txt",ios::app);
  if (fout.fail()) {
    cout<<"Error in file opening!"<<endl;
    exit(1);
  }
  fout<<id<<" "<<name<<" "<<age<<" "<<role<<" "<<salary<<endl;
  fout.close();
}

void SearchNamePrintString(Employee *list,string key,int total) {      //To search the name of a employee
  cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"  //formatted output of attribute titles
   <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
   for (int i=0;i<total;i++) {
     if (key.length()<=list[i].name.length()){
       for (int j=0;j<list[i].name.length()-key.length()+1;j++){
         if (list[i].name.substr(j,key.length())==key) {
           cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;           //formatted output of the required staff info
          }
        }
      }
   }
  cout<<"\n\n\n";
}

void SearchEmployee() {         //To search for employees in the system
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
  while (option!=0) {                             //Get the type of attribute to be searched
    cout<<"You can search by:\n1. ID \n2. name \n3. age \n4. role \n\n0. Exit Searching\n"<<endl;
    cout<<"Option: "<<endl;
    cin>>option;
    //system("cls");
    cout<<"Search for: ";                        //Get the attribute of the employees to be searched
    switch (option) {
      case 1:
      {int x;
      cin>>x;
      cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"   //formatted output of employees' attributes
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
      for (int i=0;i<total;i++) {
        if (list[i].ID==x) {
          cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;       
        }                                                          //formatted output of the information of the employee searched by ID
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
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;         //formatted output of employees' attributes
      for (int i=0;i<total;i++) {
        if (list[i].age==z) {
          cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
            <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
        }                                                           //formatted output of the information of the employee searched by age
      }
      cout<<"\n\n\n";
      break;}
      case 4:
      {string a;
      cin>>ws;
      getline(cin,a);
      cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<setw(4)<<left<<"Age"
       <<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;       //formatted output of employees' attributes
       for (int i=0;i<total;i++) {
         if (a.length()<=list[i].role.length()){
           for (int j=0;j<list[i].role.length()-a.length()+1;j++){
             if (list[i].role.substr(j,a.length())==a) {
               cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
                <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
              }                                                   //formatted output of the information of the employee searched by role
            }
          }
       }
      cout<<"\n\n\n";
      break;}
      case 0:
      break;
      default:
      cout<<"Error! Please choose one of the options.\n"<<endl;
    }
  }

  delete [] list;
}

void FireEmployee() {             //To delete the information of an employee from the system
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
  cout<<"Please enter the employee's id: ";                    //Get the ID of the employee to be fired
  int del;
  string confirm;
  cin>>del;
  bool exist=true;
  for (int i=0;i<total;i++) {
    if (list[i].ID==del){
      break;
    } else if (i==total-1) {
      cout<<"The employee does not exist!\n\n\n";             //Output error message if the ID entered is not valid
      exist=false;
    }
  }
  while (exist) {
    cout<<"Are you sure you want to delete this employee's information? Y/N ";   //ask for confirmation
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
      cout<<"Employee Removed\n\n\n";              //Output message if the employee is deleted sucessfully
      break;
    } else if (confirm=="N") {
      cout<<"Deletion Terminated\n\n\n";            //Output message if the user chose not to delete the employee
      break;
    } else {
      cout<<"Error! Please type Y/N"<<endl;          //Output message if the user entered invalid choice
    }
  }
  delete [] list;
}

void EditEmployee()                                  //To edit the information of an employee
{
  int edit,newchoice;
  cout<<"Please enter the ID of the employee you want to edit : ";  //Get the ID of the employee to be edited
  cin>>edit;
  int nage,nsalary;
  string nname,nrole;

  //
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
  ofstream fout;
      fout.open("employees.txt");
      if (fout.fail()) {
        cout<<"Error in file opening!"<<endl;
        exit(1);
      }
      for (int j=0;j<total;j++)
      {
      	if (list[j].ID==edit){
      		cout<<"Original Record :\n" ;
			  cout<<setfill(' ');
 cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
 cout<<setw(4)<<left<<list[j].ID<<setw(20)<<left<<list[j].name<<setw(4)<<left<<list[j].age
    <<setw(30)<<left<<list[j].role<<setw(7)<<left<<list[j].salary<<endl;      //Show the original information of the employee
		  }}                                 
		  cout<<"Please enter new name :";
  cin>>ws;
  getline(cin,nname);
  cout<<"Please enter new age :";
  cin>>nage;
  cout<<"Please enter new role :";
  cin>>ws;
  getline(cin,nrole);
  cout<<"Please enter new salary :";         //Get the new information of the employee
  cin>>nsalary;

	  for (int k=0;k<total;k++) {
        if (list[k].ID==edit){
           fout<<list[k].ID<<" "<<nname<<" "<<nage<<" "<<nrole<<" "<<nsalary<<endl;}
        else{

		{
			 fout<<list[k].ID<<list[k].name<<" "<<list[k].age<<" "<<list[k].role<<" "<<list[k].salary<<endl;
		   }
        }
}
fout.close();
      cout<<"Employee's Record Edited !\n\n\n";   //Output message if the employee is edited successfully
      delete [] list;
    }

      void SearchSalary()                 //To search for employees that according to the salary level entered 
      {
      	int choice,target;
      	cout<<"Please enter a salary level :";         //Get an integer as the salary level
      	cin>>target;
      	cout<<"You want to search employees with salary higher than or lower than the level ?\n";
      	cout<<"Please enter 1.Higher than or 2.Lower than : ";   
      	cin>>choice;                       //Ask if the user want to show the employees with employer higher than or lower than the salary level
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
        cout<<setfill(' ');
       cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
        for (int i=0;i<total;i++)                    //formatted output of the attributes
        {
        	if (choice==1)
        	{
        		if (list[i].salary>=target)
        		{
        			cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
          <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
      		  }
      	  }        
      	if (choice==2)
      	{
      		if (list[i].salary<=target)
      		{
      			cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
          <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
      		}
      	  }
        }                              //output the information of the employees that satisfy the requirement
      	cout<<"Search Ended !\n\n\n"<<endl;      //output message when the searching is ended
        delete [] list;
      }

void AddAttribute(Employee * list,int total) {    //To add a new attribute of the employees
  cout<<"New attribute name (One word only): ";   //Get a new attribute in one word
  string new_att;
  cin>>new_att;
  ofstream fout;
  fout.open("attributes.txt",ios::app);
  if (fout.fail()) {
    cout<<"Error in file opening!"<<endl;
    exit(1);
  }
  fout<<new_att<<" ";
  string enter;
  for (int i=0;i<total;i++) {
    //system("cls");
    cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
    cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
       <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
    cout<<"\nPlease initialize this employee's "<<new_att<<".\nPlease type / to skip this employee.\nEach item is limited to one word(without spacing).\n\n"<<new_att<<": ";
    cin>>enter;
    fout<<enter<<" ";   //Get the initial attribute of each employee
  }
  fout<<endl;
  fout.close();
  cout<<"New attribute added!\n\n\n";  //Output message if the new attribute is added successfully

}

void ReadAttribute() {      //To read the existing attribute of the employees
  ifstream fin2;
  fin2.open("attributes.txt");
  if (fin2.fail()) {
    cout<< "Error in file opening!" << endl;
    exit(1);
  }
  string x,y;
  cout<<"Existing attribute: ";   //Output the existing attribute of each employee
  while (fin2>>x) {
    cout<<x<<" ";
    getline(fin2,y);
  }
  cout<<endl;
  fin2.close();
}

int EditAttribute(Employee * list,int total) {   //To edit the attribute added to the employees
  //system("cls");
  ReadAttribute();
  cout<<"Attribute name: ";        //Get the name of the attribute to be edited 
  string att;
  cin>>att;
  string x,y,z;
  bool found=false;
  int choice;
  bool exist=true;
  while (choice!=0) {
    ifstream fin2;
    fin2.open("attributes.txt");
    if (fin2.fail()) {
      cout<< "Error in file opening!\nThere maybe no custom attributes. If so, Please add new attributes." << endl;
      exit(1);
    }
    while (fin2>>x) {
      if (x==att) {
        found=true;
        if (!exist) {
          //system("cls");
          cout<<"Employee doesn't exist!\n\n\n";
        }
        cout<<setw(5)<<left<<"ID"<<setw(19)<<left<<"Name"<<att<<endl;
        for (int i=0;i<total;i++) {
          fin2>>y;
          cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<y<<endl;
        }
        cout<<"\n\n\n";
      }
      getline(fin2,y);
    }
    fin2.close();
    if (!found) {
      //system("cls");
      cout<<"The attribute does not exist!\n\n\n";
      return 0;
    }
    cout<<"1. Edit\n0. Back\n";       //Ask if the user want to edit the attribute or exit
    cin>>choice;
    switch (choice) {
      case 1:{
        ofstream fout;
        fout.open("attributes_new.txt");
        if (fout.fail()) {
          cout<<"Error in file opening!"<<endl;
          exit(1);
        }
        cout<<"Enter the employee's ID: ";
        int change;
        string ninfo;
        cin>>change;
        ifstream fin3;
        fin3.open("attributes.txt");
        if (fin3.fail()) {
          cout<< "Error is file opening!" << endl;
          exit(1);
        }
        while (fin3>>x) {
          if (x==att) {
            fout<<x<<" ";
            exist=false;
            for (int i=0;i<total;i++) {
              if (list[i].ID==change) {
                exist=true;
                cout<<"Type one word only (don't use space).\n";   //Get the new attrbute of each employee
                cout<<"New "<<att<<" for"<<list[i].name<<": ";
                cin>>ninfo;
                fin3>>y;
                fout<<ninfo<<" ";
                //system("cls");
                cout<<att<<" for"<<list[i].name<<" changed!\n\n\n";
              } else {
                fin3>>y;
                fout<<y<<" ";
              }
            }
            fout<<endl;
          } else {
            getline(fin3,y);
            fout<<x<<y<<endl;
          }
        }
        fin3.close();
        fout.close();
        remove("attributes.txt");
        rename("attributes_new.txt","attributes.txt");
        break;
      }
      case 0:
      break;
      default:
      //system("cls");
      cout<<"Error! Please choose one of the options.\n"<<endl;
    }

  }


}

void Attribute() {            //To add, read, or edit the attribute of the employees
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
  int choice;
  while (choice!=0){
    cout<<setfill(' ');
    cout<<"You can: \n1. Add a new attribute \n2. View/Edit an existing custom attribute"<<endl;
    cout<<"\n0.Exit to main menu\n\nOption: ";         //Get the command from the user 
    cin>>choice;
    switch (choice) {
      case 1:{
        AddAttribute(list,total);
        break;
      }
      case 2:{
        EditAttribute(list,total);
        break;
      }
      case 0:
      //system("cls");
      break;
      default:
      cout<<"Error! Please choose one of the options.\n"<<endl;    //output message if the command entered by the user is invalid
    }

  }
  delete [] list;


}

void Bubblesortstring(string st[],int n)    //To sort an array of string by bubble sort
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-1-i;j++)
		{
			if (st[j]>=st[j+1])
			{
				string temp=st[j];
				st[j]=st[j+1];
				st[j+1]=temp;
			}
		}
	}
}
void Bubblesortnumber(int in[],int n)    //to sort an array of integer by bubble sort
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-1-i;j++)
		{
			if (in[j]>=in[j+1])
			{
				int temp=in[j];
				in[j]=in[j+1];
				in[j+1]=temp;
			}
		}
	}
}
void Sort()        //To sort the information of the employees by name,age,or salary
{

  int choice;
  //cout<<"Please enter the attributes to sort :";
  cout<<"1.Name (in alphbetical order) \n2.Age \n3.Salary \n";
  cout<<"Please enter the attribute to sort :";       //Get the attribute to be sorted
  cin>>choice;
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
  cout<<"Sorting Result :\n";
cout<<setfill(' ');
 cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;   //formatted output of attributes
  if (choice==1)
  {
  	string *temp=new string[total];
  	for (int i=0;i<total;i++)
  	{
  		temp[i]=list[i].name;
	  }
	Bubblesortstring(temp,total);
	for (int i=0;i<total;i++)
{
	    for (int j=0;j<total;j++)
	    {
	    	if (temp[i]==list[j].name)
	    	{
	    		cout<<setw(4)<<left<<list[j].ID<<setw(20)<<left<<list[j].name<<setw(4)<<left<<list[j].age
                <<setw(30)<<left<<list[j].role<<setw(7)<<left<<list[j].salary<<endl;
			}
		}
}
  }
  if (choice==2||choice==3)
  {
  	int *temp=new int[total];
  	for (int i=0;i<total;i++)
  	{
  		if (choice==2){
		    temp[i]=list[i].age;}
		if (choice==3){
			temp[i]=list[i].salary;}
		}
	  Bubblesortnumber(temp,total);
 for (int i=0;i<total;i++)
{

	for (int j=0;j<total;j++)
	    {if (choice==2)
	    {

	    	if (temp[i]==list[j].age)
	    	{


	    	if (list[j].age==temp[i+1])
			{
			continue;
			}

				cout<<setw(4)<<left<<list[j].ID<<setw(20)<<left<<list[j].name<<setw(4)<<left<<list[j].age
                <<setw(30)<<left<<list[j].role<<setw(7)<<left<<list[j].salary<<endl;

			}}
		if (choice==3)
		{
			if (temp[i]==list[j].salary)
	    	{
	    		if (list[j].salary==temp[i+1])
				{
				continue;
				}
	    		cout<<setw(4)<<left<<list[j].ID<<setw(20)<<left<<list[j].name<<setw(4)<<left<<list[j].age
                <<setw(30)<<left<<list[j].role<<setw(7)<<left<<list[j].salary<<endl;
	         }                                    //formatted output of the employee's information after sorting according to user's command
		}}}}}
