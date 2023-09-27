#include <iostream>
#include <conio.h>  // Library for getch()

using namespace std;

int chooseTile() {

    int tileNum;
    int column;

    cout << "Choose a column. (x-axis) \n>> ";
    cin >> tileNum;
    cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";
    cout << "Choose a row. (y-axis) \n>> ";
    cin >> column;
    tileNum += (column-1)*3;
    cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";

    return tileNum;
};

void showGrid(char grid[3][3], char currentTurn, bool clearScreen) {  // Function for displaying the grid and its contents
    
    if (clearScreen) {
        cout << "\033[2J\033[H";  // Clears the entire terminal screen, and sets cursor position to top left corner
    };
    
    cout << "\033[1mTic Tac Terminal++\033[0m \n";
    cout << "\033[4m" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "\n";
    cout << "\033[4m" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\n";
    cout << "\033[0m" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\n";
};

char changeTurn(char turn) {
    
    if (turn == 'X') {
        return 'O';
    }

    return 'X';
};

int main() {
    
    char grid[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };  // 2-dimensional array for the grid
    
    int availableTiles = 9;
    char currentTurn = 'X';

    showGrid(grid, currentTurn, false);
    
    while (availableTiles > 0) {
        int tile = chooseTile();
        // "unpacking" the tile number to grid indeces (don't know why the column one needs -4, but we move)
        int row = (tile-1) / 3;
        int column = tile - (row-1)*3 - 4;
        
        grid[row][column] = currentTurn;
        currentTurn = changeTurn(currentTurn);
        
        showGrid(grid, currentTurn, true); // Shows grid
        availableTiles--;
    }

    
    getch();  // Waits for user input, just so window doesn't close immediately
    return 0;
}
