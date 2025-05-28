#include<iostream>
using namespace std;
class car
{
	public:
	int car_id;
	char car_company_name[20];
	char car_color[10];
	char car_model[10];
	int car_release_year;
};

int main()
{
	car s;
	int n;
	for(int i=1; i<=4; i++)
	{
		cout<<"Enter the id of the car: ";
		cin>>s.car_id;
		cout<<"Enter the company name of the car: ";
		cin>>s.car_company_name;
		cout<<"Enter the color of the car: ";
		cin>>s.car_color;
		cout<<"Enter the model of the car: ";
		cin>>s.car_model>>n;
		cout<<"Enter the car release year: ";
		cin>>s.car_release_year;
		cout<<endl;
		cout<<"Detail of the car:"<<i<<endl;
		cout<<"Id: "<<s.car_id<<endl;
		cout<<"Company Name: "<<s.car_company_name<<endl;
		cout<<"Color: "<<s.car_color<<endl;
		cout<<"Model: "<<s.car_model<<n<<endl;
		cout<<"Realease Date: "<<s.car_release_year<<endl;
		cout<<endl;
	}
}
/*
Output:
Enter the id of the car: 101
Enter the company name of the car: BMW
Enter the color of the car: Black
Enter the model of the car: m 4
Enter the car release year: 1999

Detail of the car:1
Id: 101
Company Name: BMW
Color: Black
Model: m4
Realease Date: 1999

Enter the id of the car: 102
Enter the company name of the car: Audi
Enter the color of the car: Blue
Enter the model of the car: r 9
Enter the car release year: 2000

Detail of the car:2
Id: 102
Company Name: Audi
Color: Blue
Model: r9
Realease Date: 2000

Enter the id of the car: 3
Enter the company name of the car: Buggati
Enter the color of the car: Black
Enter the model of the car: chiron 2
Enter the car release year: 2018

Detail of the car:3
Id: 3
Company Name: Buggati
Color: Black
Model: chiron2
Realease Date: 2018

Enter the id of the car: 104
Enter the company name of the car: BMW
Enter the color of the car: Blue
Enter the model of the car: m 5
Enter the car release year: 2016

Detail of the car:4
Id: 104
Company Name: BMW
Color: Blue
Model: m5
Realease Date: 2016

*/