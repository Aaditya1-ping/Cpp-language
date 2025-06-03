#include <iostream>
#include <string.h>
using namespace std;

class Train {
private:
    int train_number;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    
    Train() {
        train_number = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }


    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        train_number = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }


    ~Train() {
        trainCount--;
    }


    void setTrainNumber(int number) { train_number = number; }
    void setTrainName(const char* name) { strcpy(trainName, name); }
    void setSource(const char* src) { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time) { strcpy(trainTime, time); }


    int getTrainNumber() const {  train_number; }
    const char* getTrainName() const {  trainName; }
    const char* getSource() const {  source; }
    const char* getDestination() const {  destination; }
    const char* getTrainTime() const {  trainTime; }

    
    void inputTrainDetail() {
        cout << "Enter Train Number: ";
        cin >> train_number;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

 
    void displayTrainDetails() const {
        cout << "Train number: " << train_number << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

   
    static int getTrainCount() {
        return trainCount;
    }
};


int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrain;

public:
    RailwaySystem() {
        totalTrain = 0;

       
        trains[0] = Train(101, "Okha Express", "Surat", "Mumbai", "10 AM");
        trains[1] = Train(102, "Rajdhani", "Delhi", "Kolkata", "5 PM");
        trains[2] = Train(103, "Shatabdi", "Bangalore", "Chennai", "7 AM");
        totalTrain = 3;
    }

    void addTrain() {
        if (totalTrain < 100) {
            cout << "Adding Train Record #" << totalTrain + 1 << ":";
            trains[totalTrain].inputTrainDetail();
            totalTrain++;
        } else {
            cout << "Maximum train limit reached!" << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrain == 0) {
            cout << "No train records available!" << endl;
            
        }

        for (int i = 0; i < totalTrain; i++) {
            cout << "Train "<<endl << i + 1 << " details:"<<endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) const {
     bool found = false;
        for (int i = 0; i < totalTrain; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "Train found:"<<endl;
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};


int main() {
    RailwaySystem system;
    int choice;
    do {
        cout << "--- Railway Reservation System Menu ---"<<endl;
        cout << "1. Add New Train Record"<<endl;
        cout << "2. Display All Train Records"<<endl;
        cout << "3. Search Train by Number"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3: {
                int num;
                cout << "Enter Train Number to Search: ";
                cin >> num;
                system.searchTrainByNumber(num);
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.";
        }

    } while (choice != 4);

    
}
/*
Output:

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 1

Adding Train Record #4:
Enter Train Number: 101
Enter Train Name: Okha Express
Enter Source: Surat
Enter Destination: Mumbai
Enter Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 2

Train 1 details:
Train number: 101
Train Name: Okha Express
Source: Surat
Destination: Mumbai
Train Time: 10 AM

Train 2 details:
Train number: 102
Train Name: Rajdhani
Source: Delhi
Destination: Kolkata
Train Time: 5 PM

Train 3 details:
Train number: 103
Train Name: Shatabdi
Source: Bangalore
Destination: Chennai
Train Time: 7 AM

Train 4 details:
Train number: 101
Train Name: Okha Express
Source: Surat
Destination: Mumbai
Train Time: 10 AM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to Search: 102
Train found:
Train number: 102
Train Name: Rajdhani
Source: Delhi
Destination: Kolkata
Train Time: 5 PM

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting the system. Goodbye!

*/
