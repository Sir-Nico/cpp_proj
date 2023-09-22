#include <iostream>

using namespace std;

int main() {
    // try statement
    try {
        int age = 15;
        
        if (age >= 18) {
            cout << "Access granted - you are old enough.";
        } else {
            throw 505;  // throws an exception if if-statement not fulfilled
        }
    }
    catch (int myNum) {  // Code that is run when myNum < 18
    // you can use catch (...) to handle all possible errors with one block of code
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Error Code: " << myNum;
    }

    return 0;
}