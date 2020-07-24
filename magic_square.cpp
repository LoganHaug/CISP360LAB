#include <iostream>
#include <vector>
using namespace std;
// Determines the side length of the magic square
const int SIDE_LENGTH = 3;
void display2DArray(const int my_array[SIDE_LENGTH][SIDE_LENGTH]) {
  // displays 2d arrays
  for (int row = 0; row < SIDE_LENGTH; row++) {
    for (int column = 0; column < SIDE_LENGTH; column++) {
      cout << my_array[row][column] << " ";
    }
    cout << endl;
  }
}
bool isConsistentArray(int array[], int elements) {
    // Checks if all array elements are the same
    for (int element = 0; element < elements; element++) {
        if (element == 0){
            continue;
        }
        if (array[element - 1] != array[element]) {
            return false;
        }
    }
    return true;
}

bool isMagicSquare(const int my_array[SIDE_LENGTH][SIDE_LENGTH]) {
    // Checks if the 2d array is a magic square or not
    int sum;
    // Find first diagonal sum
    int first_diagonal_sum = 0;
    for (int row = 0; row < SIDE_LENGTH; row++) {
        for (int column = 0; column < SIDE_LENGTH; column++) {
            if (row == column) {
                first_diagonal_sum += my_array[row][column];
            }
        }
    }
    // Find second diagonal sum
    int second_diagonal_sum = 0;
    for (int row = SIDE_LENGTH; row > 0; row--) {
        for (int column = 0; column < SIDE_LENGTH; column++) {
            if (row - 1 == column) {
                second_diagonal_sum += my_array[row - 1][column];
            }
        }
    }
    // Check the rows
    int row_sum[SIDE_LENGTH] = {0};
    for (int row = 0; row < SIDE_LENGTH; row++) {
        for (int element = 0; element < SIDE_LENGTH; element++) {
            row_sum[row] += my_array[row][element];
        }
    }
    if (!isConsistentArray(row_sum, SIDE_LENGTH))
        return false;

    // Check the columns
    int column_sum[SIDE_LENGTH] = {0};
    for (int row = 0; row < SIDE_LENGTH; row++) {
        for (int element = 0; element < SIDE_LENGTH; element++) {
            column_sum[element] += my_array[row][element];
        }
    }
    if (!isConsistentArray(column_sum, SIDE_LENGTH))
        return false;
    // Make sure all of the various things are equal to each other
    // Add all sums to a vector
    vector<int> sums;
    sums.push_back(first_diagonal_sum);
    sums.push_back(second_diagonal_sum);
    for (int sum = 0; sum < SIDE_LENGTH; sum++) {
        sums.push_back(row_sum[sum]);
    }
    for (int sum = 0; sum < SIDE_LENGTH; sum++) {
        sums.push_back(column_sum[sum]);
    }
    // Create an array so that we can pass it to isConsistentArray()
    int array_sums[sums.size()];
    for (sum = 0; sum < sums.size(); sum++) {
        array_sums[sum] = sums[sum];
    }
    if (!isConsistentArray(array_sums, sums.size()))
        return false;
    return true;
}

void checkAndDisplay(int my_array[SIDE_LENGTH][SIDE_LENGTH]) {
    // Displays and checks if a square is a magic square
    cout << "Is this square a magic square?" << endl;
    display2DArray(my_array);
    if (isMagicSquare(my_array)) {
        cout << "Yes, this is a magic square" << endl << endl;
    }
    else {
        cout << "No, this is not a magic square" << endl << endl;
    }

}

int main() {
  int magic_square1[SIDE_LENGTH][SIDE_LENGTH] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
  checkAndDisplay(magic_square1);
  int magic_square2[SIDE_LENGTH][SIDE_LENGTH] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
  checkAndDisplay(magic_square2);
  int non_magic_square[SIDE_LENGTH][SIDE_LENGTH] = {{1, 4, 7}, {8, 9, 3}, {10, 2, 7}};
  checkAndDisplay(non_magic_square);
}
