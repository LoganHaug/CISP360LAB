// Written by Logan N. Haug
#include <iostream>
#include <string>
/*
Write a program that dynamically allocates an array large enough to hold a user defined number of test scores.  Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.  Another function should be called that calculates the average score.  The program should display the sorted list of scores and averages with appropriate headings.  Use pointer notation rather than array notation whenever possible.
*/
using namespace std;
double* addElements(double *user_array, int user_array_length, int num_new_elements) {
  if (num_new_elements < user_array_length) {
    return nullptr;
  }
  double *new_array = new double[num_new_elements];
  for (int element = 0; element < user_array_length; element++) {
    *(new_array + element) = *(user_array + element);
  }
  delete[] user_array;
  return new_array;
}
//void sortElements(double *user_array, int user_array_length){}
//double averageScore(double *user_array, int user_array_length){}
int main() {
  double *my_array = new double [1];
  string user_input;
  int current_position = 0;
  do {
    cout << "Enter a test score or enter 'quit' to quit: ";
    cin >> user_input;
    try  {
      *(my_array + current_position) = stod(user_input);
      my_array = addElements(my_array, current_position + 1, 1);
      current_position++;
    }
    catch (...) {
      if (user_input != "quit") {
        cout << "invalid test score" << endl;
      }
    }


  }
  while (user_input != "quit");
  for (int i = 0; i < current_position + 1; i++) {
    cout << *(my_array + i);
  }
}
