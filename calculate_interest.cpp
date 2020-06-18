#include <iostream>
#include <cmath>
using namespace std;

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
