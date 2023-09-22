#include <iostream>
#include <string>

using namespace std;

int main() {
    // A pointer is used to store the memory address of the value it is assigned
    string munch = "Pizza";
    string* ptr = &munch;

    cout << munch << "\n";  // Outputs the value of munch
    cout << &munch << "\n";  // Outputs the memory address of munch
    cout << ptr << "\n";  // Outputs the memory address of munch
    cout << *ptr << "\n";  // Outputs the value of munch

    // Pointers can be declared in three different ways
    // type* ptr;
    // type *ptr;
    // type * ptr;

    // Changing the value of the pointer
    *ptr = "Hamburger";

    cout << *ptr << "\n";  // Outputs the new value
    cout << munch << "\n";  // Due to changing the value of ptr, the original value is affected, as it is the same address in memory

    return 0;
}