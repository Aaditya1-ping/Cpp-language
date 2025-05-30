#include<iostream>
using namespace std;
class Diamond
{

		int comp_id;
		string comp_name;
		int comp_staff_quantity;
		int comp_revenue;
		int comp_import_raw_diamonds;
		int comp_export_diamonds;
		string comp_ceo;
		public:
	Diamond()
	
		{
			cout<<"Enter company id: ";
			cin>>this->comp_id;
			cout<<"Enter company name: ";
			cin>>this->comp_name;
			cout<<"Enter company staff quantity: ";
			cin>>this->comp_staff_quantity;
			cout<<"Enter company per year revenue: ";
			cin>>this->comp_revenue;
			cout<<"Enter imported diamond: ";
			cin>>this->comp_import_raw_diamonds;
			cout<<"Enter exported diamond: ";
			cin>>this->comp_export_diamonds;
			cout<<"Enter name of CEO: ";
			cin>>this->comp_ceo;
			cout<<endl;
			getData();
			}	
		void getData()
		{
			cout<<"Company id: "<<this->comp_id<<endl;
			cout<<"Company name: "<<this->comp_name<<endl;
			cout<<"Staff quantity: "<<this->comp_staff_quantity<<endl;
			cout<<"Company revenue: "<<this->comp_revenue<<endl;
			cout<<"Imported diamond: "<<this->comp_import_raw_diamonds<<endl;
			cout<<"Exported diamond: "<<this->comp_export_diamonds<<endl;
			cout<<"CEO: "<<this->comp_ceo<<endl;
		}
		
};
int main()
{
	Diamond c1;

}
/*
Output:
Enter company id: 101
Enter company name: MeghaShree
Enter company staff quantity: 75
Enter company per year revenue: 100000000
Enter imported diamond: 440000
Enter exported diamond: 440000
Enter name of CEO: Aaditya

Company id: 101
Company name: MeghaShree
Staff quantity: 75
Company revenue: 100000000
Imported diamond: 440000
Exported diamond: 440000
CEO: Aaditya

*/
