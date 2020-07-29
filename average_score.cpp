# include <iostream>
using namespace std;

int main() {
    double game1, game2, game3, average;
    cout << "What was your score for the first game of golf: ";
    cin >> game1;
    cout << "What was your score for the second game of golf: ";
    cin >> game2;
    cout << "What was your score for the third game of golf: ";
    cin >> game3;
    average = (game1 + game2 + game3) / 3;
    cout << "The average score of the three games was: " << average << endl;
    return 0;
}
