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

// Function that takes in refrences to the parameters, making it so that modifications of the parameters actually affect the original variables
void swapNums(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

// Passing a list as a parameter to the function
void listFunction(int nums[5]) {
    for (int i = 0; i < 5; i++) {
        cout << nums[i] << "\n";
    }
}

// Function Overloading -- Making a function compatible with multiple data types
int plusFunc(int x, int y) {
    return x + y;
}

double plusFunc(double x, double y) {
    return x + y;
}
// plusFunc now works with ints and doubles


// Recursion!! (SpOoOOooOOkyy)
int sum(int k) {
    if (k > 0) {
        return k + sum(k - 1);
    } else {
    	return 0;
    }
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

    int swapNum1 = 10;
    int swapNum2 = 20;
    cout << "Numbers pre-swap:\n" << swapNum1 << " " << swapNum2 << "\n";
    swapNums(swapNum1, swapNum2);
    cout << "Numbers post-swap:\n" << swapNum1 << " " << swapNum2 << "\n";

    cout << "\nList Function:\n";
    int nums[5] = {1, 2, 3, 4, 5};
    listFunction(nums);

    // Using the overloaded function with both ints and doubles
    int myNum1 = plusFunc(8, 5);
    double myNum2 = plusFunc(4.3, 6.26);
    cout << "Int: " << myNum1 << "\n";
    cout << "Double: " << myNum2 << "\n";

	int nSum = sum(69);
	cout << nSum << "\n";
    return 0;
}

void myOtherFunction() {
    cout << "Hahahahe\n";
}