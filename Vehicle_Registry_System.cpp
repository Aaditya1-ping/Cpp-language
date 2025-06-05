#include <iostream>
#include <string.h>
using namespace std;


class Vehicle {
private:
    int vehicle_id;
    string manufacture;
    string model;
    int year;

    static int total_vehicle;

public:
    Vehicle() {
        vehicle_id = 0;
        manufacture = "";
        model = "";
        year = 0;
        total_vehicle++;
    }

    Vehicle(int id, string mfr, string mdl, int yr) {
        vehicle_id = id;
        manufacture = mfr;
        model = mdl;
        year = yr;
        total_vehicle++;
    }

     ~Vehicle() {
        total_vehicle--;
    }

    
    int getVehicleID() const { return vehicle_id; }
    void setVehicleID(int id) { vehicle_id = id; }

    string getManufacture() const { return manufacture; }
    void setManufacture(string mfr) { manufacture = mfr; }

    string getModel() const { return model; }
    void setModel(string mdl) { model = mdl; }

    int getYear() const { return year; }
    void setYear(int yr) { year = yr; }

    static int getTotalVehicle() { return total_vehicle; }

    virtual void display() const {
        cout << "ID: " << vehicle_id << ", Manufacture: " << manufacture
             << ", Model: " << model << ", Year: " << year << endl;
    }
};

int Vehicle::total_vehicle = 0;


class Car : public Vehicle {
protected:
    string fuel_type;

public:
    Car() : Vehicle(), fuel_type("Unknown") {}

    Car(int id, string mfr, string mdl, int yr, string fuel)
        : Vehicle(id, mfr, mdl, yr), fuel_type(fuel) {}

    void setFuelType(string fuel) { fuel_type = fuel; }
    string getFuelType() const { return fuel_type; }

    void display() const override {
        Vehicle::display();
        cout << "Fuel Type: " << fuel_type << endl;
    }
};


class ElectricCar : public Car {
protected:
    int battery_capacity;

public:
    ElectricCar() : Car(), battery_capacity(0) {}

    ElectricCar(int id, string mfr, string mdl, int yr, string fuel, int battery)
        : Car(id, mfr, mdl, yr, fuel), battery_capacity(battery) {}

    void display() const override {
        Car::display();
        cout << "Battery Capacity: " << battery_capacity << " kWh" << endl;
    }
};


class Aircraft {
protected:
    int flight_range;

public:
    Aircraft() : flight_range(0) {}

    Aircraft(int range) : flight_range(range) {}

    void setFlightRange(int range) { flight_range = range; }
    int getFlightRange() const { return flight_range; }

    void displayFlightRange() const {
        cout << "Flight Range: " << flight_range << " km" << endl;
    }
};


class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string mfr, string mdl, int yr, string fuel, int range)
        : Car(id, mfr, mdl, yr, fuel), Aircraft(range) {}

    void display() const {
        Car::display();
        Aircraft::displayFlightRange();
    }
};


class SportCar : public ElectricCar {
    int top_speed;

public:
    SportCar(int id, string mfr, string mdl, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, mfr, mdl, yr, fuel, battery), top_speed(speed) {}

    void display() const override {
        ElectricCar::display();
        cout << "Top Speed: " << top_speed << " km/h" << endl;
    }
};


class Sedan : public Car {
public:
    Sedan(int id, string mfr, string mdl, int yr, string fuel)
        : Car(id, mfr, mdl, yr, fuel) {}

    void display() const override {
        cout << "[Sedan]"<<endl;
        Car::display();
    }
};

class SUV : public Car {
public:
    SUV(int id, string mfr, string mdl, int yr, string fuel)
        : Car(id, mfr, mdl, yr, fuel) {}

    void display() const override {
        cout << "[SUV]"<<endl;
        Car::display();
    }
};


class VehicleRegistry {
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }

    void addVehicle(Vehicle* v) {
        if (count < 100)
            vehicles[count++] = v;
        else
            cout << "Registry full."<<endl;
    }

    void viewAll() const {
        if (count == 0) {
            cout << "No vehicles registered."<<endl;
            
        }
        for (int i = 0; i < count; i++) {
            cout << "Vehicle #" << (i + 1) << ":"<<endl;
            vehicles[i]->display();
            cout << "-----------------------"<<endl;
        }
    }

    void searchById(int id) const {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "Vehicle Found:"<<endl;
                vehicles[i]->display();
                
            }
        }
        cout << "Vehicle not found."<<endl;
    }
};


int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << endl<<"--- Vehicle Registry System ---"<<endl;
        cout << "1. Add Vehicle"<<endl<<"2. View All Vehicles"<<endl<<"3. Search by ID"<<endl<<"4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << endl<<"Select Vehicle Type:"<<endl;
            cout << "1. Car"<<endl<<"2. Electric Car"<<endl<<"3. Flying Car"<<endl<<"4. Sport Car"<<endl<<"5. Sedan"<<endl<<"6. SUV"<<endl<<"Choice: ";
            cin >> type;

            int id, year, battery, speed, range;
            string mfr, model, fuel;

            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Manufacture: "; cin >> mfr;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Year: "; cin >> year;

            switch (type) {
            case 1:
                cout << "Enter Fuel Type: "; cin >> fuel;
                registry.addVehicle(new Car(id, mfr, model, year, fuel));
                break;
            case 2:
                cout << "Enter Fuel Type: "; cin >> fuel;
                cout << "Enter Battery Capacity: "; cin >> battery;
                registry.addVehicle(new ElectricCar(id, mfr, model, year, fuel, battery));
                break;
            case 3:
                cout << "Enter Fuel Type: "; cin >> fuel;
                cout << "Enter Flight Range: "; cin >> range;
                registry.addVehicle(new FlyingCar(id, mfr, model, year, fuel, range));
                break;
            case 4:
                cout << "Enter Fuel Type: "; cin >> fuel;
                cout << "Enter Battery Capacity: "; cin >> battery;
                cout << "Enter Top Speed: "; cin >> speed;
                registry.addVehicle(new SportCar(id, mfr, model, year, fuel, battery, speed));
                break;
            case 5:
                cout << "Enter Fuel Type: "; cin >> fuel;
                registry.addVehicle(new Sedan(id, mfr, model, year, fuel));
                break;
            case 6:
                cout << "Enter Fuel Type: "; cin >> fuel;
                registry.addVehicle(new SUV(id, mfr, model, year, fuel));
                break;
            default:
                cout << "Invalid type."<<endl;
            }
        } else if (choice == 2) {
            registry.viewAll();
        } else if (choice == 3) {
            int search_id;
            cout << "Enter ID to search: ";
            cin >> search_id;
            registry.searchById(search_id);
        } else if (choice == 4) {
            cout << "Exiting..."<<endl;
        } else {
            cout << "Invalid choice."<<endl;
        }

    } while (choice != 4);

   
}
/*
  Output:
--- Vehicle Registry System ---
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 1

Select Vehicle Type:
1. Car
2. Electric Car
3. Flying Car
4. Sport Car
5. Sedan
6. SUV
Choice: 1
Enter Vehicle ID: 105
Enter Manufacture: india
Enter Model: 1975
Enter Year: 2010
Enter Fuel Type: petrol

--- Vehicle Registry System ---
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 2
Vehicle #1:
ID: 105, Manufacture: india, Model: 1975, Year: 2010
Fuel Type: petrol
-----------------------

--- Vehicle Registry System ---
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 3
Enter ID to search: 102
Vehicle not found.

--- Vehicle Registry System ---
1. Add Vehicle
2. View All Vehicles
3. Search by ID
4. Exit
Enter your choice: 4
Exiting...

*/