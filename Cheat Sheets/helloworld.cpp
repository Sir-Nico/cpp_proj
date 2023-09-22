#include <iostream>  // iostream is used for cout, cin among other things

// using namespace std; // I've commented it out this time, but using this line you can save yourself from typing std:: before everything in the standard library

/* Multiline comment
WOOHOO!!!!!!!!!!! */

int main() {  // The main function is what is actually ran
    std::cout << "𒀲" << std::endl;  // std::cout is used to print text to the console, and std::endl is a way to force a newline
    std::cout << "𒀲\n";  // Prints the same as the line above, just using \n for newline
    return 0;  // Return code 0 is universally considered the "everything well" exit code, anything else and you are screwed
}
