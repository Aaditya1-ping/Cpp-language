#include<iostream>
using namespace std;
class time_converter
{
	public:
		int total_second;
		int hour;
		int minute;
		int second;
};
int main()
{
	time_converter s;
	cout<<"Enter total second: ";
	cin>>s.total_second;
	s.hour=s.total_second/3600;
	s.minute=(s.total_second%3600)/60;
	s.second=s.total_second%60;
	cout<<s.hour<<":"<<s.minute<<":"<<s.second;
	cout<<endl;
	cout<<"Enter hour: ";
	cin>>s.hour;
	cout<<"Enter minute: ";
	cin>>s.minute;
	cout<<"Enter second: ";
	cin>>s.second;
	s.total_second=s.hour*3600 + s.minute*60 + s.second;
	cout<<"Total second: "<<s.total_second;
	
}
/*
Output:
Enter total second: 4200
1:10:0
Enter hour: 1
Enter minute: 10
Enter second: 0
Total second: 4200
*/
