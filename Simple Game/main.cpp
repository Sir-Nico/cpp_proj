#include <iostream>
#include <conio.h>
 
using namespace std;
 
int chooseTile() {
 
    int tileNum;
    int row;
 
    cout << "Choose a row. (y-axis) \n>> ";
    cin >> tileNum;
    cout << "\x1b[1A" << "\x1b[2K" << "\x1b[1A" << "\x1b[2K" << "\r";
    cout << "Choose a column. (x-axis) \n>> ";
    cin >> row;
    tileNum += (row-1)*3;
    cout << "\x1b[1A" << "\x1b[2K" << "\x1b[1A" << "\x1b[2K" << "\r";
 
    return tileNum;
};
 
void showGrid(string grid[3][3]) {
    cout << "\x1B[2J\x1B[H";  // Clears the entire terminal screen, and sets cursor position to top left corner
    cout << "\x1b[4m" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "\n";
    cout << "\x1b[4m" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\n";
    cout << "\x1b[0m" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\n";
}
 
 
int main() {
    
    string grid[3][3] = {
        {" ", " ", " "}, 
        {" ", " ", " "}, 
        {" ", " ", " "}
    };  // 2-dimensional array for the grid
 
    cout << "Welcome to Tic Tac Terminal++ \n";
    cout << "\x1b[4m" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "\n";
    cout << "\x1b[4m" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\n";
    cout << "\x1b[0m" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\n";

    int tile = chooseTile();
    showGrid(grid); // Shows grid
    getch();  // Waits for user input
    return 0;
}
