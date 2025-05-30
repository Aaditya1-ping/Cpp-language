#include<iostream>
using namespace std;
class cafe
{
	int cafe_id;
	string cafe_type;
    int cafe_rating;
	string cafe_location;
	int cafe_establish_year;
	int cafe_staff_quantity;
	public:
		cafe()
		{
			string n;
			cout<<"Enter cafe id: ";
			cin>>this->cafe_id;
			cout<<"Enter cafe type: ";
			cin>>this->cafe_type;
			cout<<"Enter cafe rating: ";
			cin>>this->cafe_rating>>n;
			cout<<"Enter cafe location: ";
			cin>>this->cafe_location;
			cout<<"Enter cafe establish year: ";
			cin>>this->cafe_establish_year;
			cout<<"Enter cafe staff quantity: ";
			cin>>this->cafe_staff_quantity;
			cout<<endl;
			getData();
		}
		void getData()
		{
			cout<<"Cafe id: "<<this->cafe_id<<endl;
			cout<<"Cafe type: "<<this->cafe_type<<endl;
			cout<<"Cafe rating: "<<this->cafe_rating<<endl;
			cout<<"Cafe location: "<<this->cafe_location<<endl;
			cout<<"Establish year: "<<this->cafe_establish_year<<endl;
			cout<<"Staff quantityu: "<<this->cafe_staff_quantity<<endl;
		}
};

int main()
{
	cafe c1;
}
/*
Output:
Enter cafe id: 101
Enter cafe type: normal
Enter cafe rating: 5 star
Enter cafe location: surat
Enter cafe establish year: 2018
Enter cafe staff quantity: 25

Cafe id: 101
Cafe type: normal
Cafe rating: 5
Cafe location: surat
Establish year: 2018
Staff quantityu: 25

*/
