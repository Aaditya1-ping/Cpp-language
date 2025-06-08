#include<iostream>
using namespace std;
class BankAccount
{
	private:
		float balance;
		
	protected:
	    int accountNumber;
		string accountHolderName;
		
	public:
	   BankAccount(int accNo, string name, float bal)
	   {
	   	  accountNumber=accNo;
	   	  accountHolderName=name;
	   	  balance=bal;
	   }	
	   
	   virtual ~BankAccount(){}
	   
	   virtual void deposite(float amount)
	   {
	   	if (amount>0)
	   	balance+=amount;
	   }
	   
	   virtual void withdraw(float amount)
	   {
	   	if (amount<=balance)
	   	balance-=amount;
	   	else
	   	cout<<"Insufficient funds."<<endl;
	   }
	   
	   float getBalance()
	   const{
	     return balance;	
	   }	
	   
	   virtual void displayAccountInfo()
	   const{
	   	cout<<"Account Number: "<<accountNumber<<endl;
	   	cout<<"Holder Name: "<<accountHolderName<<endl;
	   	cout<<"Balance: "<<balance<<endl;
	   }
	   virtual void calculateInterest()
	   const{
	   	cout<<"No interest calculation for base account"<<endl;
	   }
	   
};

class SavingAccount : public BankAccount
{
	float interestRate;
	public:
		SavingAccount(int accNo, string name, float bal, float rate)
		 : BankAccount(accNo, name, bal), interestRate(rate) {}	
		void calculateInterest()
		const{
			cout<<"Saving Account Interest: "<<getBalance()*interestRate<<endl;
		}
		
		
};

class CheckingAccount : public BankAccount
{
	float overdraftLimit;
	public:
		CheckingAccount(int accNo, string name, float bal, float limit)
		: BankAccount(accNo, name, bal), overdraftLimit(limit) {}
		
		void withdraw(float amount)
		{
		   if(amount<=getBalance()+overdraftLimit)
		   {
		   	BankAccount::withdraw(amount);
			   }	
			   else{
			   	cout<<"Overdraft limit exceeded."<<endl;
			   }
	    }
	    void calculateInterest()
	    const{
	    	cout<<"Checking Account does not earn interest."<<endl;
		}
		void checkOverdraft()
		const{
			cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
		}
};

class FixedDepositAccount : public BankAccount
{
	int term;
	float fixedRate;
	
	public:
		FixedDepositAccount(int accNo, string name, float bal, int termMonths, float rate)
		: BankAccount(accNo, name, bal), term(termMonths), fixedRate(rate) {}

		void calculateInterest()
		const{
			float interest=getBalance()*fixedRate*(term/12.0f);
			cout<<"Fixed Deposit Interest: "<<interest<<"for"<<term<<"month"<<endl;
		}
};

void showMenu()
{
	cout<<endl<<"---Banking Menu---"<<endl;
	cout<<"1.Creat Saving Account"<<endl;
	cout<<"2.Creating checking Account"<<endl;
	cout<<"3.Creat Fixed Deposit Account"<<endl;
	cout<<"4.Display All Account"<<endl;
	cout<<"5.Deposit"<<endl;
	cout<<"6.Withdraw"<<endl;
	cout<<"7.Calculate Interest"<<endl;
	cout<<"8.Exit"<<endl;
	cout<<"Choose an option: ";
}

int main()
{
	const int Max_Account=100;
	BankAccount* accounts[Max_Account];
	int count=0;
	int choice;
	do{
		showMenu();
		cin>>choice;
		if(choice==1&&count<Max_Account){
			int accNo;
			string name;
			float bal, rate;
			cout<<"Enter Account Number: ";
			cin>>accNo;
			cout<<"Name: ";
			cin>>name;
			cout<<"Balance: ";
			cin>>bal;
			cout<<"Interest Rate: ";
			cin>>rate;
			accounts[count++]=new SavingAccount(accNo, name, bal, rate);
		}
		else if(choice==2&&count<Max_Account)
		{
			int accNo;
			string name;
			float bal, limit;
			cout<<"Enter Account Number: ";
			cin>>accNo;
			cout<<"Name: ";
			cin>>name;
			cout<<"Balance: ";
			cin>>bal;
			cout<<"Overdrafft Limit: ";
			cin>>limit;
			accounts[count++]=new CheckingAccount(accNo, name, bal, limit);
		}
		else if(choice==3&&count<Max_Account)
		{
			int accNo, term;
			string name;
			float bal, rate;
			cout<<"Enter Account Number: ";
			cin>>accNo;
			cout<<"Name: ";
			cin>>name;
			cout<<"Balance: ";
			cin>>bal;
			cout<<"Term (months): ";
			cin>>term;
			cout<<"Rate: ";
			cin>>rate;
			accounts[count++]=new FixedDepositAccount(accNo, name, bal, term, rate);
		}
		else if(choice==4)
		{
		  for(int i=0; i<count; ++i)
		  {
		  	cout<<endl<<"---Account["<<i<<"]---"<<endl;
		  	accounts[i]->displayAccountInfo();
			  }	
		}
		else if(choice==5)
		{
			int index;
			float amt;
			cout<<"Enter account index to deposit: ";
			cin>>index;
			if(index>=0&&index<count)
			{
			  cout<<"Enter amount: ";
			  cin>>amt;
			accounts[index]->deposite(amt);
		    }
	
		else
		{
			cout<<"Invalid index."<<endl;
		}
	}
	else if(choice==6)
	{
		int index;
		float amt;
		cout<<"Enter account index to withdraw from: ";
		cin>>index;
		if(index>=0&&index<count)
		{
			cout<<"Enter amount: ";
			cin>>amt;
			accounts[index]->withdraw(amt);
		}
		else
		{
			cout<<"Invlaid index. "<<endl;
		}
	}
	else if(choice==7)
	{
		for(int i=0; i<count; ++i)
		{
			cout<<endl<<"---Account["<<i<<"] Interest---"<<endl;
			accounts[i]->calculateInterest();
		}
	}
}while(choice!=8);

for(int i=0; i<count; ++i)
{
	delete accounts[i];
}
cout<<"Existing banking system. Goodbye"<<endl;
}
/*
Output:
---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 1
Enter Account Number: 101
Name: Aaditya
Balance: 1000000
Interest Rate: 2.5

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 2
Enter Account Number: 102
Name: Aayush
Balance: 1100000
Overdrafft Limit: 10000

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 3
Enter Account Number: 103
Name: Bipin
Balance: 900000
Term (months): 5
Rate: 2.5

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 4

---Account[0]---
Account Number: 101
Holder Name: Aaditya
Balance: 1e+06

---Account[1]---
Account Number: 102
Holder Name: Aayush
Balance: 1.1e+06

---Account[2]---
Account Number: 103
Holder Name: Bipin
Balance: 900000

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 5
Enter account index to deposit: 101
Invalid index.

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 6
Enter account index to withdraw from: 102
Invlaid index.

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 7

---Account[0] Interest---
Saving Account Interest: 2.5e+06

---Account[1] Interest---
Checking Account does not earn interest.

---Account[2] Interest---
Fixed Deposit Interest: 937500for5month

---Banking Menu---
1.Creat Saving Account
2.Creating checking Account
3.Creat Fixed Deposit Account
4.Display All Account
5.Deposit
6.Withdraw
7.Calculate Interest
8.Exit
Choose an option: 8
Existing banking system. Goodbye

*/

