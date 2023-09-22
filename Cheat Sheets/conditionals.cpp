#include <iostream>

using namespace std;

int main() {
    // If statement
    if (2 > 1) {
        cout << "Siuuu" << endl;
    }

    // If-else statement
    if (2 < 1) {
        cout << "Siuuu" << endl;
    } else {
        cout << "Messirve" << endl;
    }

    // If-else-if statement
    if (2 < 1 + 1) {
        cout << "Siuuu" << endl;
    } else if (2 == 1 + 1) {
        cout << "\'Arry Maguiah" << endl;
    } else {
        cout << "Messirve" << endl;
    }

    // Ternary operator :O     True       False
    string result = (2 > 1) ? "Siuuu" : "Messirve";
    cout << result << endl;

    // Switch Statement
    int day = 4;
    switch (day) {
    case 6:
        cout << "Today is Saturday";
        break;

    case 7:
        cout << "Today is Sunday";
        break;

    default:
        cout << "Looking forward to the Weekend!";
    }

    return 0;
}