#include <iostream>

using namespace std;

// Other Functions MUST be declared before the main function
// Function return types must be declared, and in the case of no return value, specified as void
void myFunction() {
    cout << "Heheheha\n";
}

// Declaring an empty function
void myOtherFunction();

// Function with parameters
void myParamFunction(string myStr, int myNum) {
    cout << myStr << " " << myNum << "\n";
}

// Function with a default parameter value
void myOtherParamFunction(string country = "Norway") {
    cout << country << "\n";
}

// Function with a return value, type specified
int addNums(int x, int y) {
    return x + y;
}

int main() {
    // Call the functions
    myFunction();
    myOtherFunction();
    myParamFunction("Siuuuu", 123);
    myOtherParamFunction("England");
    myOtherParamFunction();
    myOtherParamFunction("Italy");
    int addedNum = addNums(43, 26);
    cout << addedNum << "\n";

    return 0;
}

void myOtherFunction() {
    cout << "Hahahahe\n";
}