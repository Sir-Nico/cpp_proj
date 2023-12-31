#include <iostream>

using namespace std;

int main() {
    int myNum = 69; // Defining the variable and assigning a value immediately 
    cout << myNum << endl;

    int myOtherNum; // Defining the variable without assigning a value
    myOtherNum = 420; // Assigning the variable a value
    cout << myOtherNum << endl;

    int aNum = 5;                // Integer (whole number without decimals)
    double myFloatNum = 5.99;    // Floating point number (with decimals)
    char myLetter = 'D';         // Character
    string myText = "Hello";     // String (remember, a string is just a string of chars)
    bool myBoolean = true;       // Boolean (true or false) 

    // Using a variable together with strings
    int age = 17;
    cout << "I am " << age << " years old.\n";

    // Maffemafics
    int x = 9;
    int y = 10;
    int sum = x + y + 2;
    cout << "The sum of " << x << " + " << y << " is " << sum;  // You Stoopid

    // Holy shit multiple variable declarations at the SAME TIME!!
    int x = 5, y = 6, z = 50;
    cout << x + y + z;

    // Same thing as above, just a different way to do it
    int x, y, z;
    x = y = z = 50;
    cout << x + y + z;

    // Constant variable, ergo immutable, read-only, the whole shabang
    const int PI = 3.141592; //...

    return 0;
}
