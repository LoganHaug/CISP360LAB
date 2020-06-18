#include <iostream>
#include <cmath>
using namespace std;
/*

Developed by Logan Haug

CISP 360 Lab 2: Interest Earned
Assuming there are no deposits other than the original investment,
the balance in a savings account after one year may be calculated as:

Amount = Principal x (1 + Rate / T)T

Principal is the balance in the savings account, Rate is the interest rate,
and T is the number of times the interest is compounded during a year
(T is 4 if the interest is compounded quarterly).

Write a program that asks for the principal, the interest rate,
and the number of times the interest is compounded.


It should display a report similar to:

Interest Rate:   4.25%
Times Compounded:   12
Principal:  $1000.00
Interest:  $43.34
Amount in Savings: $1043.34
*/
int main() {
    double interest_rate, principle, interest, times_compounded;
    cout << "Enter the interest rate: ";
    cin >> interest_rate;
    if (interest_rate >= 1.0){
        interest_rate /= 100;
    }
    cout << "Enter the number of times compounded: ";
    cin >> times_compounded;
    cout << "Enter the Principle: ";
    cin >> principle;
    cout << "\nInterest Rate: " << interest_rate * 100 << "%\n";
    cout << "Times Compounded: " << times_compounded << '\n';
    cout << "Principle: $" << principle << '\n';
    // interest = principle * pow(((1 + interest_rate) / times_compounded), times_compounded);
    interest = (principle * pow((1 + (interest_rate / times_compounded)), times_compounded)) - principle;
    cout << "Interest: $" << interest << '\n';
    cout << "Amount in savings: $" << principle + interest << '\n';

    return 0;
}
