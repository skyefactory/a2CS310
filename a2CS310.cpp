#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const int MISSING_SQUARE = -1;
const int ARRAY_MAX_SIZE = 2048;

unsigned int tCount;

int board[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];


void initBoard(int arrSize);
void printBoard(int arrSize);
void placeTriomino(unsigned int x1, unsigned int x2, unsigned int x3, unsigned int y1, unsigned int y2, unsigned int y3);
int fillBoard(int arrSize, int missx, int missy);

int main()
{
    //n: board size; mx: missing square row; my: missing square row; bSize = value of 2^n
    int n, mx, my, bSize;
    //user input for n & missing square coordinates.
    cout << "Enter input (n): ";
    cin >> n;
    cout << "Enter Input (missing square row & missing square column) seperated by a space: ";
    cin >> mx >> my;

    //calculate size of board, check if the missing square coordinates are out of bounds.
    bSize = pow(2, n);
    assert(mx <= bSize && my <= bSize);
    cout << "Board is size " << bSize << endl;

    //fill board with zero, set missing square location to -1
    initBoard(bSize);
    board[mx][my] = MISSING_SQUARE;

    //print board, fill board, print board.
    printBoard(bSize);
    cout << "Filling Board..." << endl;;
    fillBoard(bSize, 0, 0);
    printBoard(bSize);

}

void initBoard(int arrSize) {
    for (int i = 0; i < arrSize;i++)
        for (int j = 0; j < arrSize;j++)
            board[i][j] = 0;
    cout << "Init Board Completed: Board is Initialized\n";
}

void printBoard(int arrSize)
{   
    for (int i = 0; i < arrSize;i++) {
        for (int j = 0; j < arrSize;j++) {
            cout <<setw(3)<< board[i][j];
        }
        cout << endl;
    }
        

}

void placeTriomino(unsigned int x1, unsigned int x2, unsigned int x3, unsigned int y1, unsigned int y2, unsigned int y3)
{
    // Fill 3 cells with given x & y values. Increment tCount as a whole Triomino is being placed.
    tCount++;
    board[x1][y1] = tCount;
    board[x2][y2] = tCount;
    board[x3][y3] = tCount;

}

void placeSingleCell(unsigned int x, unsigned int y) {
    // Do not increment tCount , not placing a whole Triomino.
    board[x][y] = tCount;
}

int fillBoard(int arrSize, int startX, int startY)
{
    int row, column;
    //FIND MISSING SQUARE. LOOK FOR -1 ON BOARD.
    for (int i = 0; i < startX + arrSize; i++) {
        for (int j = 0; j < startX + arrSize; j++) {
            if (board[i][j] != 0) {
                row = i; column = j;
            }
        }
    }

    //BASE CASE: n = 2; 1 Triomino and 1 missing square.
    if (arrSize == 2) {
        tCount++;
        for (int i = 0; i < startX + arrSize; i++) {
            for (int j = 0; j < startX + arrSize; j++) {
                if (board[startX + i][startY + j] == 0) {
                    placeSingleCell(startX + i, startY + j);
                }
            }
        }
    } 
    /*RECURSIVE CASE: n > 2;
    Let T(n) represent the number of Triominoes that will fit in a 2^n x 2^n checkerboard.
    T(n) = floor(n^2/3). (i.e. T(8): A 8x8 (2^3 x 2^3) board has (8^2) 64 cells, 64 / 3 (amount of squares 1 Triomino takes up) = 21 Triominoes. So a 2^n x 2^n board has T(n) Triominoes and 1 missing square.
    */

    //find T(n)
    int T = floor((pow(arrSize, 2) / 3));
    
    return 0;
}