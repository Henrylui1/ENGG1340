#include <fstream>
#include <iostream>
using namespace std;

struct Employee {
  int ID;
  string name;
  int age;
  string role;
  int salary;
}
int main() {
  ifstream fin("employees.txt");
  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1);
  }
  int temp;
  Employee *list=new Employee [];
  count=0;
  while(fin>>temp) {
    Employee[count].ID=temp;
    
    count++;
  }
  return 0;
}
