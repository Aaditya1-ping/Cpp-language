#include<iostream>
#include<string.h>
using namespace std;
 
 class Train
 {
 	private:
 		int train_number;
 		char train_name[50];
 		char source[50];
 		char destination[50];
 		char train_time[10];
 		static int train_count;
 		
 		public:
 			Train()
 			{
 				train_number=0;
 				strcpy(train_name, "");
 				strcpy(source, "");
 				strcpy(destination, "");
 				strcpy(train_time, "");
 				train_count++;
			 }
			 
			 Train(int number, const char* name, const char* src, char* dest, char* time )
			 {
			 	train_number=number;
			 	strcpy(train_name, name);
			 	strcpy(source, src);
			 	strcpy(train_time, time);
			 	train_count++;
			 }
			 
			 ~Train()
			 {
			 	train_count--;
			 }
			 
			 void setTrainNumber(int number)
			 {
			 	train_number=number;
			 }
			 void setTrainName(const char* name)
			 {
			 	strcpy(train_name, name);
			 }
			 void setSourace(const char* src)
			 {
			 	strcpy(source, src);
			 }
			 void setDestination(const char* dest)
			 {
			 	strcpy(destination, dest);
			 }
			 void setTrainTime(const char* time)
			 {
			 	strcpy(train_time, time);
			 }
			 
			 int getTrainNUmber()
			 const {
			 	train_number;
			 	}
			 	const char* getTrainName()
			 	const {
			 		train_name;
				 }
			 	const char* getSource()
			 	const{
			 		source;
				 }
 		        const char* getDestination()
 		        const{
 		        	destination;
				 }
				const char* getTime()
				const{
					train_time;
				} 
				
				void inputTrainDetail()
				{
					cout<<"Enter Train Number: ";
					cin>>train_number;
					cout<<"Enter Train Name: ";
					cin>>train_name;
					cout<<"Enter Source: ";
					cin>>source;
					cout<<"Enter Destination: ";
					cin>>destination;
					cout<<"Enter Train Time: ";
					cin>>train_time;
					
				}
				
				void displayTrainDetail()
				{
					cout<<"Train Number: "<<train_number<<endl;
					cout<<"Train Name: "<<train_name<<endl;
					cout<<"Source: "<<source<<endl;
					cout<<"Destination: "<<destination<<endl;
					cout<<"Train Time: "<<train_time<<endl;
				}
				static int getTrainCount()
				{
					train_count;
				}
 };
 
 int Train::train_count=0;
 
 
 class RailwaySystem
 {
 	private:
 		Train trains[100];
 		int total_train;
 		
 	public:
	 	RailwaySystem()
	 	{
	 		total_train=0;
	 		
	 		trains[0]=Train(101, "Okha Express", "Surat", "Mumbai", "10 AM");
	 		trains[1]=Train(102, "Rajdhani", "Delhi", "Kolkata", "5 PM");
	 		trains[2]=Train(103, "Shatabdi", "Bangalore", "Chennai", "7 AM");
	 		total_train=3;
		 }
		 
	void addTrain()
	{
		if(total_train<100)
		{
			cout<<endl<<"Adding Train Record #"<<total_train + 1 <<endl;
			trains[total_train].inputTrainDetail();
			total_train++;
		}else
		{
			cout<<"Maximum train limit reached!"<<endl;
		}
	}
	
	void displayAllTrains()
	
	const{ 
	if(total_train==0)
		{
		cout<<"No train record available!" <<endl;
		}
	
	for (int i=0; i<total_train; i++)
	{
		cout<<endl<<"Train "<<i+1<<"Detail: "<<endl;
		trains[i].displayTrainDetail();
	}
}
    void searchTrainByNumber(int number)
    const{
    	found=false;
    	for(int i=0; i<total_train; i++)
    	{
    		if(trains[i].getTrainNumber()==number){
    			cout<<"Train found: "<<end;
    			trian[i].displayTrainDetail();
    			found=true;
    			break;
			}
		}
		if(!found)
		{
			cout<<"Train with number: "<<number<<"not found! "<<endl;
		}
	}
};

int main()
{
	RailwaySystem system;
	int choice;
	do{
		cout<<"---Railway Reservation System Menu---"<<endl;
		cout<<"1.Add New Train Records."<<endl;
		cout<<"2.Dispaly All Train Records."<<endl;
		cout<<"3.Search Train by Number."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
		  case 1:
		     system.addTrain();
			 break;
			case 2:
			 system.displayAllTrains();
			 break;
			case 3:
			 {
			 	int num;
			 	cout<<"Enter Train Number to Search: ";
			 	cin>>num;
			 	system.searchTrainByNumber();
			 	break;
				 }	
			case 4:
				 cout<<"Exiting the system. Goodbye!"<<end;
				 break;
			default:
				 cout<<"Invalid choice. Plesae try again."<<endl;
		}
	} while(choice!=4);
}
