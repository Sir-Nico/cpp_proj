#include <iostream>

using namespace std;

int main() {
    // While loop
    int num = 0;
    while (num < 5) {
        cout << num << endl;
        num++;
    }

    // Do-While loop
    do {
        cout << num << endl;
        num--;
    } while (num > 0);

    cout << num << endl;

    // For Loop
    cout << "For Loop:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    // Nested Loop
    cout << "Nested Loop:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Outer: " << i << endl;

        for (int j = 0; j < 3; j++) {
            cout << "Inner: " << (i * 3) + j << endl;
        }
    }

    // For-Each Loop
    int myNumbers[5] = {10, 20, 30, 40, 50};
    for (int i : myNumbers) {
        cout << i << endl;
    }

    // break
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            break;  // No more loop for you
        }
        cout << i << "\n";
    }

    // continue keyword
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            continue;  // skips to the next cycle
        }
        cout << i << "\n";
    } 

    return 0;
}
