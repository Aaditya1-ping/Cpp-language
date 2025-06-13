#include <iostream>
#include <string>
using namespace std;


class Vehicle {
private:
    string model;
    float speed;

public:
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    void setSpeed(float s) {
        speed = s;
    }

    float getSpeed() {
        return speed;
    }

   
    virtual void displayDetails() {
        cout << "Vehicle Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }

  
    virtual ~Vehicle() {}
};


class Car : public Vehicle {
public:
    void displayDetails()  {
        cout << "Car Details -> Model: " << getModel()
             << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};


class Bike : public Vehicle {
public:
    void displayDetails()  {
        cout << "Bike Details -> Model: " << getModel()
             << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};


int main() {
   
    Car myCar;
    myCar.setModel("Tesla Model 3");
    myCar.setSpeed(120);

    Bike myBike;
    myBike.setModel("Ducati Monster");
    myBike.setSpeed(90);

   
    Vehicle* vehicles[2];
    vehicles[0] = &myCar;
    vehicles[1] = &myBike;

   
    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();  
    }

    
}
/*
Output:
Car Details -> Model: Tesla Model 3, Speed: 120 km/h
Bike Details -> Model: Ducati Monster, Speed: 90 km/h
*/

