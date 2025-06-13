#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    float balance;
    string ownerName;

public:
    
    BankAccount(string accNum, string owner, float initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

        void credit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credited " << amount << " to account."<<endl;
        } else {
            cout << "Invalid amount to credit."<<endl;
        }
    }

    
    void debit(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Debited " << amount << " from account."<<endl;
        } else {
            cout << "Invalid amount or insufficient balance."<<endl;
        }
    }

    
    void displayBalance() {
        cout << "Account Holder: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs." << balance << endl;
    }
};

int main() {
    
    BankAccount myAccount("1234", "Anish Bk", 1000.0);

    
    myAccount.displayBalance();

    myAccount.credit(500.0);   
	  myAccount.debit(200.0);    

    myAccount.displayBalance(); 

   
}
/*
Output:
Account Holder: Anish Bk
Account Number: 1234
Current Balance: Rs.1000
Credited 500 to account.
Debited 200 from account.
Account Holder: Anish Bk
Account Number: 1234
Current Balance: Rs.1300

*/

