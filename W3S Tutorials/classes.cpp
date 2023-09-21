// CLASSES N STUFF
#include <iostream>
#include <string>

using namespace std;

class MyClass {
    public:  // Access Specifier (public / private)
        int myNum;  // Class attribute
        string myString;
};

int main() {
    MyClass myObj;
    
    myObj.myNum = 69;
    myObj.myString = "Funny.";

    cout << myObj.myNum;

    return 0;
}