// Written by Logan N. Haug
#include <iostream>
using namespace std;

class circle {
    public:
        double radius;
        double pi;
        circle () {
            radius = 0.0;
            pi = 3.14159;
        };
        circle (double user_radius) {
            radius = user_radius;
            pi = 3.14159;
        };
        void setRadius(double user_radius) {
            radius = user_radius;
        };
        double getRadius() {
            return radius;
        };
        double getArea() {
            return pi * radius * radius;
        };
        double getDiameter() {
            return 2 * radius;
        };
        double getCircumference() { 
            return 2 * pi * radius;
        };
    private:
};

int main() {
    bool got_radius = false;
    double user_radius;
    do {
        cout << "Enter a radius length: ";
        try {
            cin >> user_radius;
            got_radius = true;
        } catch (...) {
            cout << "That was an invalid radius" << endl;
        }
    } while (!got_radius);
    circle my_circle = circle(user_radius);
    cout << "The Circle's Area: " << my_circle.getArea() << endl;
    cout << "The Circle's Diameter: " << my_circle.getDiameter() << endl;
    cout << "The Circle's Circumference: " << my_circle.getCircumference() << endl;
}
