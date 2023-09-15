#include <iostream>
#include <string>  // You need to include the string library for strings to properly work

using namespace std;

int main() {
    // basic data types
    int aNum = 5;              // Integer (whole number without decimals)
    float myFloatNum = 9.95;   // Floating point number (with decimals) but 4 bytes of memory (under 8 decimals)
    double myDoubleNum = 5.99;  // Floating point number (with decimals) but 8 bytes of memory (>8 decimals)
    char myLetter = 'D';       // Character (single quotes only!)
    string myText = "Hello";   // String (remember, a string is just a string of chars) (Double quotes only!)
    bool myBoolean = true;     // Boolean (true or false)

    // It is possible to define a float with scientific notation
    float f1 = 35e3;
    double d1 = 12E4;

    // chars can also be defined by ASCII character codes
    char a = 65;  // ASCII character code for 'A'
    cout << a;

    // String specific, escape characters:
    string doubleQuotes = "\nYou claim to be the \"Emperor\"";
    string singleQuote = "\nIt\'s what I do";
    string backslash = "\nC:\\users\\nicol\\prog";
    cout << doubleQuotes << singleQuote << backslash << endl;

    // Bools
    bool isCatCute = true;
    bool isCatAlive = false;
    cout << isCatCute << endl;
    cout << isCatAlive << endl;

    return 0;
}
