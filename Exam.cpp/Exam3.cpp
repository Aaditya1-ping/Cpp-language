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
};


class Car : public Vehicle {
public:
    void calculateTime(float distance) {
        float speed = getSpeed();
        if (speed <= 0) {
            cout << "Invalid speed for car." << endl;
            
        }
        float time = distance / speed;
        cout << "Car (" << getModel() << ") will take " << time << " hours to cover " << distance << " km." << endl;
    }
};


class Bike : public Vehicle {
public:
    void calculateTime(float distance) {
        float speed = getSpeed();
        if (speed <= 0) {
            cout << "Invalid speed for bike." << endl;
            
        }
        float time = distance / speed;
        cout << "Bike (" << getModel() << ") will take " << time << " hours to cover " << distance << " km." << endl;
    }
};


int main() {
    Car myCar;
    myCar.setModel("Toyota");
    myCar.setSpeed(80); 

    Bike myBike;
    myBike.setModel("Yamaha");
    myBike.setSpeed(50); 

    float distance = 160; 

    
    myCar.calculateTime(distance);
    myBike.calculateTime(distance);

   
}
/*
Output:
Car (Toyota) will take 2 hours to cover 160 km.
Bike (Yamaha) will take 3.2 hours to cover 160 km.

*/

