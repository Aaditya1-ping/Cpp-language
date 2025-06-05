#include<iostream>
using namespace std;
 class X
 {
 	public:
 		int a, b, c;
 };
 
 class Y : public X
 {
 	public:
 		void setData()
 		{
 			cout<<"Enter a: ";
 			cin>>a;
 			cout<<"Enter b: ";
 			cin>>b;
 			cout<<"Enter c: ";
 			cin>>c;
		}
		void getData()
		{
			int sum;
			cout<<"Cube of the numbers: "<<endl;
			cout<<"a: "<<a*a*a<<endl;
			cout<<"b: "<<b*b*b<<endl;
			cout<<"c: "<<c*c*c<<endl;
			
			sum=(a*a*a)+(b*b*b)+(c*c*c);
			cout<<"sum: "<<sum;
		}
};

int main()
{
	Y y1;
	y1.setData();
	y1.getData();
	
}