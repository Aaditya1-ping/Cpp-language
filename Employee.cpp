#include<iostream>
using namespace std;
class employee
{
	public:
	int emp_id;
	char emp_name[30];
	int emp_age;
	int emp_salary;
	char emp_role[20];
	char emp_city[20];
	int emp_experience;
	char Company_name[20];
	
};

int main()
{
	
	employee e;
	char n[10];
	for(int i=1; i<=5; i++)
	{
		cout<<"Enter employee id: ";
		cin>>e.emp_id;
		cout<<"Enter the name of employee:  ";
		cin>>e.emp_name;
		cout<<"Enter the age of employee: ";
		cin>>e.emp_age;
		cout<<"Enter the salary of employee: ";
		cin>>e.emp_salary;
		cout<<"Enter the role of employee: ";
		cin>>e.emp_role;
		cout<<"Enter the city of the employee: ";
		cin>>e.emp_city;
		cout<<"Enter the experience of the employee: ";
		cin>>e.emp_experience>>n;
		cout<<"Enter the name of the company: ";
		cin>>e.Company_name;
	

		cout<<endl;
		cout<<"Detail of the employee:"<<i<<endl;
		cout<<"Id: "<<e.emp_id<<endl;
		cout<<"Name: "<<e.emp_name<<endl;
		cout<<"Age: "<<e.emp_age<<endl;
		cout<<"Salary: "<<e.emp_salary<<endl;
		cout<<"Role: "<<e.emp_role<<endl;
		cout<<"City: "<<e.emp_city<<endl;
		cout<<"Experience: "<<e.emp_experience<<n<<endl;
		cout<<"Company Name: "<<e.Company_name<<endl;
		cout<<endl;	

	
	
	}
	
	
}

/*
 Output:
Enter employee id: 101
Enter the name of employee:  Aayush
Enter the age of employee: 20
Enter the salary of employee: 100000
Enter the role of employee: Doctor
Enter the city of the employee: Lamki
Enter the experience of the employee: 5 year
Enter the name of the company: Rnw

Detail of the employee:1
Id: 101
Name: Aayush
Age: 20
Salary: 100000
Role: Doctor
City: Lamki
Experience: 5year
Company Name: Rnw

Enter employee id: 102
Enter the name of employee:  Anish
Enter the age of employee: 17
Enter the salary of employee: 10000
Enter the role of employee: Plumber
Enter the city of the employee: Dhangadhi
Enter the experience of the employee: 4 year
Enter the name of the company: Global

Detail of the employee:2
Id: 102
Name: Anish
Age: 17
Salary: 10000
Role: Plumber
City: Dhangadhi
Experience: 4year
Company Name: Global

Enter employee id: 103
Enter the name of employee:  Bipin
Enter the age of employee: 18
Enter the salary of employee: 15000
Enter the role of employee: Planner
Enter the city of the employee: Surat
Enter the experience of the employee: 3 year
Enter the name of the company: Megha

Detail of the employee:3
Id: 103
Name: Bipin
Age: 18
Salary: 15000
Role: Planner
City: Surat
Experience: 3year
Company Name: Megha

Enter employee id: 104
Enter the name of employee:  Saugat
Enter the age of employee: 17
Enter the salary of employee: 20000
Enter the role of employee: Shiner
Enter the city of the employee: Rajkot
Enter the experience of the employee: 2 year
Enter the name of the company: Bhola

Detail of the employee:4
Id: 104
Name: Saugat
Age: 17
Salary: 20000
Role: Shiner
City: Rajkot
Experience: 2year
Company Name: Bhola

Enter employee id: 105
Enter the name of employee:  Ganesh
Enter the age of employee: 19
Enter the salary of employee: 25000
Enter the role of employee: Boiling
Enter the city of the employee: Mumbai
Enter the experience of the employee: 1 year
Enter the name of the company: Uber

Detail of the employee:5
Id: 105
Name: Ganesh
Age: 19
Salary: 25000
Role: Boiling
City: Mumbai
Experience: 1year
Company Name: Uber

*/