#include <iostream>
#include <string>

using namespace std;

int main() {
    // References are a way to refer to pre-existing variables
    // You can think of it as a way to create a duplicate variable that simply points to the same position in memory
    // Making said variable a clone, moreso than a duplicate

    string food = "Spaghetti";  // Original Variable
    string &meal = food;  // Reference to food
    string meal2 = food;

    cout << food << ", Memory Address: " << &food << "\n";  // Using the & before the variable returns the variable's address in memory
    cout << meal << ", Memory Address: " << &meal << "\n";
    cout << meal2 << ", Memory Address: " << &meal2 << "\n";

    return 0;
}