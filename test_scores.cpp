// Written by Logan N. Haug
#include <iostream>
#include <string>
/*
Write a program that dynamically allocates an array large enough to hold a user defined number of test scores.  Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.  Another function should be called that calculates the average score.  The program should display the sorted list of scores and averages with appropriate headings.  Use pointer notation rather than array notation whenever possible.
*/
using namespace std;

void displayArray(double *user_array, int user_array_length) {
  for (int element = 0; element < user_array_length; element++) {
      cout << *(user_array + element) << endl;
    }
}


double* changeElements(double *user_array, int user_array_length, int num_new_elements) {
  double *new_array = new double[num_new_elements];
  for (int element = 0; element < num_new_elements; element++) {
    *(new_array + element) = *(user_array + element);
  }
  delete[] user_array;
  return new_array;
}


bool isWithinArray(int *user_array, int user_array_length, int user_element) {
  for (int element = 0; element < user_array_length; element++) {
    if (user_element == *(user_array + element)) {
      return true;
    }
  }
  return false;
}


double* sortElements(double *user_array, int user_array_length) {
  // Stores the current lowest element for purpose of insertion sort
  double lowest_element = user_array[0];
  // Stores the element position that needs the next lowest element
  int current_element = 0;
  // Stores the positions that already are sorted
  int elements_selected[user_array_length];
  // The new sorted array
  double new_array[user_array_length];
  // While its not sorted
  while (current_element != user_array_length - 1 ) {
    // Continually iterate over the old list to try and sort it
    for (int element = 0; element < user_array_length; element++) {
      // If the lowest element is greater than the current element, we want the current element to be the lowest element
      if (lowest_element > *(user_array + element) && !(isWithinArray(elements_selected, user_array_length, *(user_array + element)))) {
        // Otherwise, make the lowest_element equal to the new lower element
        lowest_element = *(user_array + element);
        *(elements_selected + element) = element;
        
      }
    }
    *(new_array + current_element) = lowest_element; 
    current_element++;
    displayArray(new_array, user_array_length);
    cout << endl;

    displayArray(user_array, user_array_length);
    cout << endl;
  }
  return new_array;
}


//double averageScore(double *user_array, int user_array_length){}
int main() {
  double *my_array = new double [1];
  string user_input;
  int current_position = 0;
  do {
    cout << "Enter a test score or enter 'quit' to quit: ";
    cin >> user_input;
    try  { 
      double test_score = stod(user_input);
      if (test_score < 0) {
        throw;
      }
      *(my_array + current_position) = test_score;
      my_array = changeElements(my_array, current_position + 1, current_position + 2);
      cout << current_position << endl;
      current_position++;
      cout << current_position << endl;
    }
    catch (...) {
      if (user_input != "quit") {
        cout << "invalid test score" << endl;
      }
      else { 
        my_array = changeElements(my_array, current_position + 1, current_position);
      }
    }
  }
  while (user_input != "quit");
  my_array = sortElements(my_array, current_position);  
  cout << "Here are the sorted elements: " << endl;
  displayArray(my_array, current_position + 1);
}