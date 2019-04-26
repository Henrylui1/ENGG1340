void Bubblesortstring(string st[],int n)
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
void Bubblesortnumber(int in[],int n)
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
void Sort()
{ 

  int choice;
  //cout<<"Please enter the attributes to sort :";
  cout<<"1.Name (in alphbetical order) \n2.Age \n3.Salary \n";
  cout<<"Please enter the attribute to sort :";
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
 cout<<setw(4)<<left<<"ID"<<setw(20)<<left<<"Name"<<setw(4)<<left<<"Age"<<setw(30)<<left<<"Role"<<setw(7)<<left<<"Salary"<<endl;
  if (choice==1)
  {
  	string temp[total];
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
  	int temp[total];
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
			}
			}	
		}

} 
}

  }
