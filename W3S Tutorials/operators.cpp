#include <iostream>

using namespace std;

int main() {
    // Mainly just for looking at bitwise shift
    int x = 5;
    x <<= 4;  // Shifts the number 4 bits to the left, taking it from 101 (5) to 1010000 (80)
    cout << x << endl;

    int y = 80;
    y >>= 4;  // Shifts the number 4 bits to the right, taking it from 1010000 (80) to 101 (5)
    cout << y;

    // Comparing operators are the same as python:
    // == : Equal (4 == 6)
    // != : Not equal (4 != 6)
    //  < : Less than (4 < 6)
    // <= : Less or equal to (4 <= 6)
    //  > : Greater than (4 > 6)
    // >= : Greater or equal to (4 >= 6)
    
    // Logical operators:
    // && : And (x == y && y > 1)
    // || : Or (x != y || y < 1)
    //  ! : Not (!(4 == 6), this would return true)

    // Bitwise operators:
    // >> / >>= : Bitwise shift right (1010 -> 101)
    // << / <<= : Bitwise shift left  (101 -> 1010)

    return 0;
}
