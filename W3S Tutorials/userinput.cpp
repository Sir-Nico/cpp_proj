#include <iostream>

using namespace std;

int main() {
    /*
    int x;
    cout << "Type a number: ";
    cin >> x;  // Assigns x's value to whatever int the user inputs (Note the ">>" instead of "<<") 
    cout << "Thy number is " << x;
    */

    // int x, y;
    // int sum;
    // cout << "Type a number: ";
    // cin >> x;
    // cout << "Type another number: ";
    // cin >> y;
    // sum = x + y;
    // cout << "The sum is " << sum << ".";

    // User input with strings
    string fullName;
    cout << "Type your government name: ";
    getline(cin, fullName);  // getline takes the resulting line from cin, and assigns it to fullName*
    cout << "Good Evening, " << fullName;

    return 0;
}
