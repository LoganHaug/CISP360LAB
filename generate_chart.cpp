# include <iostream>
# include <fstream>
# include <vector>
# include <string>
using namespace std;
/* Logan Haug CISP 360 Lab 3: Sales Bar Chart
Write a program that asks the user to enter today’s sales for five stores.
The program should then display a bar graph comparing each store’s sales.
Create each bar in the bar graph by displaying a row of asterisks.
Each asterisk should represent $100 of sales. */

int main(){
    // Represents the number of sales each store had
    vector<int> sales;
    // Stores user input to add to the sales vector
    string input;
    // Gets user input for the number of sales for each store
    for (int i = 1; i < 6; i++){
        cout << "Enter today's sales for store " << i << ": ";
        cin >> input;
        // Try catch because I don't know how to handle user input easily
        try {
            sales.push_back(stoi(input) / 100);
        }
        catch (...){
            cout << "Please re-run the program, and enter an integer\n";
            return 0;
        }
    }
    // Holds the asterisks that represent the sales each store had
    vector<string> asterisks;
    // Represents each individual bar to add to the vector asterisks
    string bar;
    // Loops through each "bar" and over each store and creates the "bars"
    for (int i = 0; i < 6; i++){
        bar = "";
        for (int a = 0; a < sales[i]; a++){
            bar.push_back('*');
        }
        asterisks.push_back(bar);
    }
    // Declare output object
    ofstream output;
    output.open("output.txt");
    // Write rows of the chart to the output file
    output << "SALES BAR CHART\n(Each * = $100)\n";
    for (int i = 0; i < 5; i++){
        output << "Store " << i + 1 << ": " << asterisks[i] << '\n';
    }
    output.close();
    return 0;
}
