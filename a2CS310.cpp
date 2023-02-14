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
    //n: board size; mx: missing square row; my: missing square row
    int n, mx, my, bSize;
    //user input for n & missing square coordinates.
    cout << "Enter input (n): ";
    cin >> n;
    cout << "Enter Input (missing square row & missing square column) seperated by a space: ";
    cin >> mx >> my;
    bSize = pow(2, n);
    assert(mx <= bSize && my <= bSize);
    initBoard(bSize);
    board[mx][my] = MISSING_SQUARE;
    printBoard(bSize);
    cout << "Filling Board...";

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
    tCount++;
    board[x1][y1] = tCount;
    board[x2][y2] = tCount;
    board[x3][y3] = tCount;

}

int fillBoard(int arrSize, int missx, int missy)
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
    return 0;
}
