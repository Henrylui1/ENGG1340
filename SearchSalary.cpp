void SearchSalary()
{
	int choice,target,num=0;;
	cout<<"Please enter a salary level :";
	cin>>target;
	cout<<"You want to search employees with salary higher than or lower than the level ?\n";
	cout<<"Please enter 1.Higher than or 2.Lower than : ";
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
  cout<<setfill(' ');
 cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
  for (int i=0;i<total;i++) 
  {
  	if (choice==1)
  	{
  		if (list[i].salary>=target)
  		{
  			num+=1;
  			cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
    <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
		  }
	  }
	if (choice==2)
	{
		if (list[i].salary<=target)
		{
			num+=1;
			cout<<setw(4)<<left<<list[i].ID<<setw(20)<<left<<list[i].name<<setw(4)<<left<<list[i].age
    <<setw(30)<<left<<list[i].role<<setw(7)<<left<<list[i].salary<<endl;
		}
	  }  
  }
	cout<<"Search Ended !"<<endl;
	cout<<"Total "<<num<<" employees found !"<<endl;
	
}
