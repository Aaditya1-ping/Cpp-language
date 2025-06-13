#include<iostream>
using namespace std;
class Movie
{
	public:
		char title[50];
		char genre[20];
		int releaseYear;
	void setData()
	{
		cout<<"Enter Movie title: ";
		cin>>title;
		cout<<"Enter Genre of the movie: ";
		cin>>genre;
		cout<<"Enter released date: ";
		cin>>releaseYear;
		cout<<endl;
		
	
	}	
	void getData()
	{
		cout<<"Title: "<<title<<endl;
		cout<<"Genre: "<<genre<<endl;
		cout<<"Released Date: "<<releaseYear<<endl;
		cout<<endl;
	}
};

int main()
{
	Movie m;
	int n=2;
	for(int i=1; i<=n; i++)
	{
		m.setData();
		m.getData();
			}
}
/*
Output:
Enter Movie title: Jhola
Enter Genre of the movie: social
Enter released date: 2014

Title: Jhola
Genre: social
Released Date: 2014

Enter Movie title: Captain
Enter Genre of the movie: social
Enter released date: 2019

Title: Captain
Genre: social
Released Date: 2019


*/
