#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/* Logan Haug Lab 1:
The volume of a sphere is V = (4.0/3.0)πr^3 and the surface area is A = 4.0πr^2, where r is the radius of the sphere.
Given the radius (user input), design a program that computes the volume and surface area of the sphere.
Assume the value of π = 3.141592.
*/


int main(){
    string user_input;
    float radius;
    cout << "What is the radius of the sphere: ";
    cin >> user_input;
    try {
        radius = abs(stof(user_input));
    }
    catch (...){
        cout << "Please enter a positive non-zero radius";
        return 0;
    }
    cout << "The approximate volume of a sphere with radius " << radius << " is: " << (4.0/3.0) * (3.141592) * pow(radius, 3) << "\n";
    cout << "The approximate surface area of a sphere with radius " << radius << " is: " << 4.0 * 3.141592 * pow(radius, 2) << "\n";
    return 0;
}
