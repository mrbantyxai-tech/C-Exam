#include<iostream>
#include<string>

using namespace std;

class Vehicle {
private:
    string model;
    double speed; 
public:
    void setModel(string m) {
        model = m;
    }
    string getModel() {
        return model;
    }
    void setSpeed(double s) {
        speed = s;
    }
    double getSpeed() {
        return speed;
    }
    virtual double calculateTime(double distance) {
        return distance / speed;
    }
};

class Car : public Vehicle {
public:
    double calculateTime(double distance) override {
        return distance / getSpeed();
    }
};

class Bike : public Vehicle {
public:
    double calculateTime(double distance) override {
        return distance / getSpeed();
    }
};

int main() {
    Vehicle* car = new Car();
    string carModel;
    double carSpeed;
    cout << "Enter Car Model: ";
    getline(cin, carModel);
    car->setModel(carModel);
    cout << "Enter Car Speed (km/h): ";
    cin >> carSpeed;
    car->setSpeed(carSpeed);
    cin.ignore(); 

    Vehicle* bike = new Bike();
    string bikeModel;
    double bikeSpeed;
    cout << "Enter Bike Model: ";
    getline(cin, bikeModel);
    bike->setModel(bikeModel);
    cout << "Enter Bike Speed (km/h): ";
    cin >> bikeSpeed;
    bike->setSpeed(bikeSpeed);

    double distance;
    cout << "Enter Distance (km): ";
    cin >> distance;

    cout << "Car Model: " << car->getModel() << endl;
    cout << "Time for Car to travel " << distance << " km: " << car->calculateTime(distance) << " hours" << endl;

    cout << "Bike Model: " << bike->getModel() << endl;
    cout << "Time for Bike to travel " << distance << " km: " << bike->calculateTime(distance) << " hours" << endl;

    delete car;
    delete bike;

    return 0;
}