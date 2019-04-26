void EditEmployee()
{
  int edit,newchoice;
  cout<<"Please enter the ID of the employee you want to edit : ";
  cin>>edit;
  //cout<<"1.Name \n2.Age \n3.Role \n4.Salary";
  //cout<<endl<<"Please enter the attributes you want to edit : ";
  //cin>>newchoice;
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
    <<setw(30)<<left<<list[j].role<<setw(7)<<left<<list[j].salary<<endl;
		  }}
		  cout<<"Please enter new name :";
  cin>>ws;
  getline(cin,nname);
  cout<<"Please enter new age :";
  cin>>nage;
  cout<<"Please enter new role :";
  cin>>ws;
  getline(cin,nrole);	 
  cout<<"Please enter new salary :";
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
      cout<<"Employee's Record Edited !\n\n\n";}
