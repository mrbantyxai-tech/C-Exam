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
    virtual void displayDetails() {
        cout << "Vehicle Model: " << model << ", Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
public:
    double calculateTime(double distance) override {
        return distance / getSpeed();
    }
    void displayDetails() override {
        cout << "Car Model: " << getModel() << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};

class Bike : public Vehicle {
public:
    double calculateTime(double distance) override {
        return distance / getSpeed();
    }
    void displayDetails() override {
        cout << "Bike Model: " << getModel() << ", Speed: " << getSpeed() << " km/h" << endl;
    }
};

int main() {
    Vehicle* vehicles[2];
    vehicles[0] = new Car();
    vehicles[1] = new Bike();

    string models[2] = {"Car", "Bike"};

    for(int i = 0; i < 2; i++) {
        string model;
        double speed;
        cout << "Enter " << models[i] << " Model: ";
        getline(cin, model);
        vehicles[i]->setModel(model);
        cout << "Enter " << models[i] << " Speed (km/h): ";
        cin >> speed;
        vehicles[i]->setSpeed(speed);
        cin.ignore();
    }

    double distance;
    cout << "Enter Distance (km): ";
    cin >> distance;
    cout << endl;
    for(int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();
        cout << "Time to travel " << distance << " km: " << vehicles[i]->calculateTime(distance) << " hours" << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}