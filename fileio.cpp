#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <sstream>
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
int main() {
  ifstream fin("employees.txt");
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  int temp;
  int count=1;
  Employee *list=new Employee [count];
  while(fin>>temp) {
    list[count-1].ID=temp;
    getline(fin,list[count-1].all_info);
    count++;

  }
  fin.close();

  for (int i=0;i<count;++i) {
    list[i].age=breakdown(list[i].all_info,list[i].name);
    list[i].salary=breakdown(list[i].all_info,list[i].role);
    cout<<"Employee "<<list[i].ID<<"'s name is "<<list[i].name<<". Aged "<<list[i].age<<", has a position of "
      <<list[i].role<<", and has a salary of "<<list[i].salary<<".\n";
  }
  delete [] list;
  return 0;
}
