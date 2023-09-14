#include <iostream>

using namespace std;

int main() {
    /*
    int x;
    cout << "Type a number: ";
    cin >> x;  // Assigns x's value to whatever int the user inputs (Note the ">>" instead of "<<") 
    cout << "Thy number is " << x;
    */

   int x, y;
   int sum;
   cout << "Type a number: ";
   cin >> x;
   cout << "Type another number: ";
   cin >> y;
   sum = x + y;
   cout << "The sum is " << sum << ".";
   
}
