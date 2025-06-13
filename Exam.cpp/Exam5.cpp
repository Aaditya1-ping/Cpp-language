#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    float balance;

public:
    
    BankAccount(string accNum, string owner, float initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

   
    void display() const {
        cout << "Account Holder: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs." << balance << endl;
    }

   
    float getBalance() const {
        return balance;
    }

   
    float operator+(const BankAccount& other) const {
        return this->balance + other.balance;
    }
};

int main() {
   
    BankAccount account1("1234", "Anish", 1500.50);
    BankAccount account2("2345", "Bipin", 2450.75);

   
    cout << "--- Account 1 ---" << endl;
    account1.display();

    cout << endl<<"--- Account 2 ---" << endl;
    account2.display();

   
    float totalBalance = account1 + account2;
    cout << endl<<"Total Balance of both accounts: Rs." << totalBalance << endl;

    
}
/*
Outpurt:
--- Account 1 ---
Account Holder: Anish
Account Number: 1234
Balance: Rs.1500.5

--- Account 2 ---
Account Holder: Bipin
Account Number: 2345
Balance: Rs.2450.75

Total Balance of both accounts: Rs.3951.25

*/

