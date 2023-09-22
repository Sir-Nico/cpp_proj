#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Accessing the file through fstream's ofstream class
    ofstream MyFile("file.txt");

    MyFile << "This be written to the file, aye!";
    MyFile.close();

    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file with ifstream class
    ifstream ReadFile("file.txt");

    // Use a while loop together with the getline function to read the file line by line
    while (getline (ReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }

    // Close the file
    ReadFile.close();

    return 0;
}