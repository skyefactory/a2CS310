/*
 * Dylan Ostapa
 * ID# 200463707
 * University of Regina | CS310 Assignment 2 Question 8 | Professor Boting Yang.
 * Feb 15th, 2022
 */


#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>

#include "q8.h"
using namespace std;



void initBoard(int arrSize) {
    /*
     * Params: <1>: int arrSize - max index to initialize.
     * Pre-conditions: arrSize is greater than zero.
     * Post-conditions: None
     * Side Effects: board has indexes [0 to arrSize][0 to arrSize] set to zero.
     */

    assert(arrSize > 0);
    for (int i = 0; i < arrSize;i++)
        for (int j = 0; j < arrSize;j++)
            board[i][j] = 0;
    cout << "Init Board Completed: Board is Initialized\n";
}

void printBoard(int arrSize)
{
    /*
    * Params: <1>: int arrSize - max index to print.
    * Pre-conditions: None
    * Post-conditions: None
    * Side Effects: A formatted board is outputted to the console.
    */
    for (int i = 0; i < arrSize;i++) {
        for (int j = 0; j < arrSize;j++) {
            cout <<setw(5)<< board[i][j];
        }
        cout << endl;
    }


}

void placeTriomino(unsigned int x1, unsigned int x2, unsigned int x3, unsigned int y1, unsigned int y2, unsigned int y3)
{
    /*
    * Params: 3 pairs of x,y coordinates. Each an unsigned int.
    * Pre-conditions: board[x1][y1] == 0 and board[x2][y2] == 0 and board[x3][y3] == 0
    * Post-conditions: None
    * Side Effects: tCount incremented. Board has indexes [x1][y1] & [x2][y2] & [x3][y3] set to tCount.
    */
    assert(board[x1][y1] == 0 && board[x2][y2] == 0 && board[x3][y3] == 0);
    // Fill 3 cells with given x & y values. Increment tCount as a whole Triomino is being placed.
    //cout<<"Placing full triomino with value: "<<tCount<<endl;
    tCount++;
    board[x1][y1] = tCount;
    board[x2][y2] = tCount;
    board[x3][y3] = tCount;
}


int fillBoard(int arrSize, int startX, int startY) {
    int row, column, mid = (arrSize/2);
    /*
    * Params:
     * <1> int arrSize - max index to use
     * <2> int startX - row to start from
     * <3> int startY - column to start by
    * Pre-conditions: Board is initialized
    * Post-conditions: Returns 0
    * Side Effects: Recursively fill board with L triominoes and one missing square.
    */


    //BASE CASE: n = 2; 1 Triomino and 1 missing square.
    if (arrSize == 2) {
        //cout<<"-------------------------------"<<endl;

        //increment our triomino count
        tCount++;
        //int sCount = 0;

        // in a 4 cell (2x2) case, we can fit exactly one triomino and one missing square.
        // so, check if each cell's value is 0, if it is, replace that cell with tCount.
        // This should set 3 cells to tCount, and 1 cell will already have a value (missing cell or another triomino)
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {
                if (board[startX + i][startY + j] == 0) {
                    //cout << "Placing single cell with value: " << tCount << endl;
                    //sCount++;
                    board[startX + i][startY + j] = tCount;
                }
            }
        }
        //if(sCount < 3){cout<<"4 SINGLE CELLS PLACED - BIG ERROR HERE"<<endl;}
        // No need to continue to the rest of the function. We have reached base case.
        return 0;
    }

    //This searches for the missing square. Missing square is set in main from user input.
    for (int i = startX; i < startX + arrSize; i++) {
        for (int j = startY; j < startY + arrSize; j++) {
            if (board[i][j] != 0) {
                row = i; column = j;
            }
        }
    }

    /*RECURSIVE CASE: n > 2;
    * Let T(n) represent the number of Triominoes that will fit in a 2^n x 2^n checkerboard.
    * T(n) = floor(n^2/3). (i.e. T(8): A 8x8 (2^3 x 2^3) board has (8^2) 64 cells, floor(64 / 3(amount of squares 1 Triomino takes up)) = 21 Triominoes.
    * So a 2^n x 2^n board has T(n) Triominoes and 1 missing square.
    * We split our board into 4 pieces, and depending on where the missing tile is (first, second, third, or fourth quadrant), place a triomino in the center.
    * Our quadrants are:
    * [1 , 2]
    * [3 , 4]
     *
    * First step is to determine what quadrant the missing square is a part of.
    * Quadrant 1 has bounds [0 to arrSize/2][0 to arrSize/2]. So we would place a triomino in the center such that it
    * covers every quadrant EXCEPT for quadrant 1, because quadrant 1 already has a missing square.
    * if not quadrant 1, check if quadrant 2, 3 , or 4.
    * after this step, recurse 4 times from original function, each one with params representing the 4 different
    * quadrants. After each one reaches its base case, the board is completely filled with triominoes.
    */

    /*1st quadrant. Check to see if startX+row and column are less than startY+arrSize/2.
     * This means the missing square must be somewhere in the top left (first) quadrant.
    */
    if(row < startX + mid && column < startY + mid )
    {
        //Places a triomino that covers corners of sections 2, 3, and 4.
        placeTriomino(startX + (mid), startX + (mid), startX + (mid) - 1 ,
                      startY + (mid) -1, startY + (mid), startY + (mid));
    }

    /*2nd quadrant. Check to see if row is less than startX + arrSize/2 and column is greater than or equal to startY + mid.
     * This means the missing square must be somewhere in the top right (second) quadrant.
    */
    else if(row < startX + (mid) && column >= startY + (mid))
    {
        //Places a triomino that covers corners of sections 1, 3, and 4.
        placeTriomino(startX + (mid), startX + (mid), startX + (mid) - 1 ,
                      startY + (mid) -1, startY + (mid) , startY + (mid) - 1);
    }

    /*3rd quadrant. Check to see if row is greater than or equal to startX + arrSize/2 and column is less than startY + arrSize/2
    *  This means the missing square must be somewhere in the bottom left (third) quadrant
    */
    else if(row >= startX + (mid) && column < startY + (mid))
    {
        //Places a triomino that covers corners of sections 1, 2, and 4.
        placeTriomino(startX + (mid) - 1,startX + (mid), startX + (mid) -1,
                      startY + (mid), startY + (mid),startY + (mid) -1) ;
    }

    /*4th quadrant. Check to see if row is greater than or equal to startX + arrSize/2 and column is greater than or equal to startY + arrSize/2
    *  This means the missing square must be somewhere in the bottom right (fourth) quadrant
    */
    else if(row >= startX + (mid) && column >= startY + (mid))
    {
        //Places a triomino that covers corners of sections 1, 2, and 3.
        placeTriomino(startX + (mid) - 1, startX + (mid), startX + (mid) - 1,
                      startY + (mid), startY + (mid) - 1, startY + (mid) - 1);
    }
    else
    {
        cout<<"Something went wrong, please try again...\n";
        return -1;
    }
    //Calls fillBoard for the first quadrant.
    fillBoard(mid, startX, startY);
    //Calls fillBoard for the second quadrant.
    fillBoard(mid, startX, startY + mid);
    //Calls fillBoard for the third quadrant.
    fillBoard(mid, startX + mid, startY);
    //Calls fillBoard for the fourth quadrant.
    fillBoard(mid, startX + mid, startY + mid);

    //After the 4 fillBoard calls return, the board is filled.  We are done.
    return 0;
}
int main()
{
    int n, mx, my;
    /*
     * n: user input for board size
     * mx: missing square row
     * my: missing square column
     */

    // user input for n & missing square coordinates.
    cout << "Enter Input (n): ";
    cin >> n;
    cout << "Enter Input (missing square row & missing square column) separated by a space: ";
    cin >> mx >> my;
    cout<<"---------------------------------------"<<endl;

    //calculate size of board, check if the missing square coordinates are out of bounds, tell user board size.
    int bSize = int(pow(2, n));
    assert(mx < bSize && my < bSize);
    cout << "Board is size " << bSize << endl;

    //fill board with zero, set missing square location to -1
    initBoard(bSize);
    board[mx][my] = MISSING_SQUARE;

    //print board, ask user to continue
    printBoard(bSize);
    cout<<"Enter y to continue, anything else to quit: ";
    char temp; cin>>temp;

    // if user continues, calculate num of triominoes required, call fillBoard to fill board with triominoes, and print board again.
    if(temp == 'y' || temp == 'Y'){
        cout << "Filling Board..."<< endl;;
        int T = floor((pow(bSize, 2) / 3));
        cout<<"Total triominoes required: "<<T<<endl;
        fillBoard(bSize, 0, 0);
        if(T == tCount){
            printBoard(bSize);
            cout<<"The "<<"2^"<<n<<" x "<<"2^"<<n<<" board is successfully filled with "<<tCount<<" triominoes and 1 missing square."<<endl;
        }
        else
            cout<<"Board was not successfully filled with triominoes. Expected "<<T<<" triominoes but got "<<tCount<<" triominoes instead"<<endl;
    }else{
        //else if user does not continue, return and quit program.
        return 0;
    }


}

