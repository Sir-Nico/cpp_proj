// CLASSES N STUFF
#include <iostream>
#include <string>

using namespace std;

class MyClass {
    public:  // Access Specifier (public / private)
        string myString;  // Class attribute
        int myNum;
        MyClass(string x, int y) {  // Constructor (same as __init__(self) in python), called on object creation
            myString = x;
            myNum = y;
        }  // Constructors can, just like any other method, be defined outside the class like myCoolerMethod()
        void myMethod() {  // Function inside class :O
            cout << "Siuuuu\n";
        }
        void myCoolerMethod(string param);  // Empty method declaration with parameter
    private:  //This is the default access specifier, meaning any attribute with unspecified access is private 
        string mySecret = "Kebab, mmm";  // This cannot be accessed like the other public attributes. 
};  // Do NOT forget the semicolon after class definition

// Definition of empty method (Written same way as std::cout, curious)
void MyClass::myCoolerMethod(string param) {
    cout << param << "\n";
}

int main() {
    // Declaring an object is the same as declaring any other variable, but with the class as datatype
    MyClass myObj("Unfunny.", 68);
    MyClass myOtherObj("Unfunny.", 68);

    // Assigning new values to the object's properties
    myObj.myString = "Funny.";
    myObj.myNum = 69;

    // Outputting the properties
    cout << myObj.myString << "\n";
    cout << myObj.myNum << "\n";
    
    cout << myOtherObj.myString << "\n";
    cout << myOtherObj.myNum << "\n";
    
    myObj.myMethod();  // Calling the class method
    myObj.myCoolerMethod("Messirve");
    
    // cout << myObj;  // This is not allowed >:(
    cout << &myObj;  // This is though :)
    // ^Gets the memory address of the object

    return 0;
}
