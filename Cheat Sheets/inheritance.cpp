#include <iostream>

using namespace std;

// Base class
class Vehicle {
    public:
        void vroomVroom() {
            cout << "Nyooommm \n";
        }
        string brand = "Ford";
        void honk() {
            cout << "Tuut, tuut! \n" ;
        }
    protected:  // Protected attributes work the same as private attributes except for the fact they can be inherited, which private attributes can't
        string protectedString = "Protect me!";
};

// Derived class
class Car: public Vehicle {  // Class Car inherits from Vehicle
    public:
        void vroomVroom() {  // Overriding the vroomVroom method from Vehicle class, this is called polymorphism
            cout << "Vrooom vrooom \n";
        }
        string model = "Mustang";
        string getString() {  // Getter function for the protected attribute from Vehicle class
            return protectedString;
        }
};

class OtherCar: public Vehicle {  // Class Car inherits from Vehicle
    public:
        string otherModel = "Focus";
};

class CarSquared: public Car {};  // Empty class, just to show that you can inherit from a derived class

// Class inheriting from multiple classes
class CarCrash: public Car, public OtherCar {
    public:
        int carsDestroyed = 2;
};

int main() {
    Vehicle truck;
    Car myCar;
    CarCrash kaboom;
    myCar.honk();  // myCar has the methods and attributes of the Vehicle class because of the inheritance
    cout << myCar.brand + " " + myCar.model << "\n";
    cout << myCar.getString() << "\n";
    cout << kaboom.model + ", " + kaboom.otherModel + ", Destroyed Cars: " << kaboom.carsDestroyed << "\n";
    truck.vroomVroom();
    myCar.vroomVroom();

    return 0;
}
