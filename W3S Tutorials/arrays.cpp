#include <iostream>
#include <string>

using namespace std;

int main() {
    // To define an array, you must specify the variable type, and optionally the size (no. of elements)
    int myNums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int myOtherNums[] = {1, 2, 3};  // Valid array definition sans array length
    int myEmptyNums[3];  // If you want to define an array without elements, the length is necessary

    cout << myNums[1] << "\n";  // Outputs the 2nd item of myNums (0-based indexing)
    myNums[1] = 11;
    cout << myNums[1] << "\n";

    cout << "\n";

    // Looping through the array
    myNums[1] = 1;
    for (int i = 0; i < 10; i++) {
        cout << myNums[i] << "\n";
    }
    
    cout << "\n";

    // Looping with a For-Each Loop
    for (int i : myNums) {
        cout << i << "\n";
    }

    // Getting the size of an array in bytes
    int array_size = sizeof(myOtherNums);  // (12)
    cout << array_size / sizeof(int) << "\n";  // By dividing array_size by the size of an int, we can get the length of the array

    // Multidimensional array holy smokes
    string letters[2][4] = {
        { "A", "B", "C", "D" },
        { "E", "F", "G", "H" }
    };
    letters[0][0] = "Z";  // Accessing and changing the first first element of the array

    cout << letters[0][0];

    // Looping through multidim array with nested loops
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << letters[i][j] << "\n";
        }
    } 

    return 0;
}