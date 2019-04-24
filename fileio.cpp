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
  int ID;
  Employee *list=new list[];
  while(fin>>ID) {
    
  }
  return 0;
}
