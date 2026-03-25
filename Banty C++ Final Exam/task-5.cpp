#include<iostream>
#include<cmath>

using namespace std;

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() override {
        return M_PI * radius * radius;
    }
    void draw() override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double calculateArea() override {
        return width * height;
    }
    void draw() override {
        cout << "Drawing a Rectangle with width " << width << " and height " << height << endl;
    }
};

int main() {
    Shape* shapes[2];

    double radius;
    cout << "Enter radius for Circle: ";
    cin >> radius;
    shapes[0] = new Circle(radius);

    double width, height;
    cout << "Enter width for Rectangle: ";
    cin >> width;
    cout << "Enter height for Rectangle: ";
    cin >> height;
    shapes[1] = new Rectangle(width, height);

    for(int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
    }

    for(int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}