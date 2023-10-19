#include <iostream>
#include <conio.h>  // Library for getch()

using namespace std;

// Returns a number between 1 and 9 (tile)
int chooseTile() {

    int tileNum;
    int row;
    bool isValid = true;

    cout << "Choose a column. (x-axis) \n>> ";
    cin >> tileNum;

    // The line "cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";" is used to clear 2 lines, to erase text from previous prompt

    // Forcing user to input numbers between 1 and 3
    isValid = (1 <= tileNum && tileNum <= 3);
    while (!isValid) {
        cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";
        cout << "Choose a column. (x-axis) \n(between 1 and 3) >> ";
        cin >> tileNum;
        isValid = (1 <= tileNum && tileNum <= 3);
    }

    cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";
    cout << "Choose a row. (y-axis) \n>> ";
    cin >> row;

    isValid = (1 <= row && row <= 3);
    while (!isValid) {
        cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";
        cout << "Choose a row. (y-axis) \n(between 1 and 3) >> ";
        cin >> row;
        isValid = (1 <= row && row <= 3);
    }
    tileNum += (row-1)*3;
    cout << "\033[1A" << "\033[2K" << "\033[1A" << "\033[2K" << "\r";

    return tileNum;
};

// Outputs the grid to the console with some extra information (which numbers correspond to tiles)
void showGrid(char grid[3][3], char currentTurn, bool clearScreen) {
    
    if (clearScreen) {
        cout << "\033[2J\033[H";  // Clears the entire terminal screen, and sets cursor position to top left corner
    };
    
    // The recurring \033 statements are ANSI escape sequences, where [4m is used to make text underline, [3m is used to make text cursive and [0m resets text effects
    cout << "\033[1mTic Tac Terminal++\033[0m \n";
    cout << "\033[4m" << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "\033[0m\033[3m 3 \033[0m" << "\n";
    cout << "\033[4m" << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\033[0m\033[3m 2 \033[0m" << "\n";
    cout << "\033[0m" << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\033[0m\033[3m 1" << "\n";
    cout << "1 2 3 \033[0m \n";
};

// Changes turn
char changeTurn(char turn) {
    
    if (turn == 'X') {
        return 'O';
    }

    return 'X';
};

// Returns whether the given array consists of the same elements (except ' ')
bool isEqual(char array[3]) {  // Could make the array variable in size, but getting the size is a bit forked

    char controlChar = array[0];  // Uses the first item in the array as the control
    if (controlChar == ' ') {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (array[i] != controlChar) {
            return false;
        }
    }
    return true;
};

// Checks if a winning combination has been played by either party
bool checkWinner(char grid[3][3]) {

    // Horizontal
    for (int i = 0; i < 3; i++) {
        char tiles[3];
        for (int j = 0; j < 3; j++) {
            tiles[j] = grid[i][j];
        }
        if (isEqual(tiles)) {
            return true;
        }
    }
    
    // Vertical
    for (int i = 0; i < 3; i++) {
        char tiles[3];
        for (int j = 0; j < 3; j++) {
            tiles[j] = grid[j][i];
        }
        if (isEqual(tiles)) {
            return true;
        }
    }
    
    // Diagonal
    char diagonalTiles[3];
    for (int i = 0; i < 3; i++) {
        diagonalTiles[i] = grid[i][i];
    }
    if (isEqual(diagonalTiles)) {
        return true;
    }
    
    // Reverse Diagonal
    char revDiagonalTiles[3];
    for (int i = 0; i < 3; i++) {
        revDiagonalTiles[i] = grid[i][2-i];
    }
    if (isEqual(revDiagonalTiles)) {
        return true;
    }

    return false;
}

int main() {

    char grid[3][3] = {   // Corresponding tile numbers:
        {' ', ' ', ' '},  //  7  8  9
        {' ', ' ', ' '},  //  4  5  6
        {' ', ' ', ' '}   //  1  2  3
    };  // 2-dimensional array for the grid
    
    int availableTiles = 9;
    char currentTurn = 'X';
    bool isWinner = false;

    showGrid(grid, currentTurn, false);  // Need to avoid clearing console immediately, as program doesn't run in terminal window otherwise
    
    // Game loop, only runs 9 times as there only are 9 tiles on the board
    while (availableTiles > 0) {
        int tile = chooseTile();
        // "unpacking" the tile number to grid indeces (don't know why the column one needs -4, but we move)
        int row = (tile-1) / 3;
        int column = tile - (row-1)*3 - 4;

        int selectedIsEmpty = (grid[row][column] == ' ');  // Checking if the selected tile is empty, and requiring a new tile selected in such a case
        while (!selectedIsEmpty) {
            cout << "Selected tile already occupied. \n>> ";
            getch();
            cout << "\033[1A" << "\033[2K" << "\r";
            int tile = chooseTile();
            int row = (tile-1) / 3;
            int column = tile - (row-1)*3 - 4;
            selectedIsEmpty = (grid[row][column] == ' ');
        }
        
        grid[row][column] = currentTurn;
        isWinner = checkWinner(grid);

        showGrid(grid, currentTurn, true); // Shows grid
        if (isWinner) {
            break;
        }
        currentTurn = changeTurn(currentTurn);
        availableTiles--;
    }
    
    if (!isWinner) {
        cout << "It was a draw!";
        getch();
        return 0;
    }
    cout << currentTurn << " has won!!";
    
    getch();  // Waits for user input, just so window doesn't close immediately

    return 0;
}
