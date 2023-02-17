/*
 * Dylan Ostapa
 * ID# 200463707
 * University of Regina | CS310 Assignment 2 Question 8 | Professor Boting Yang.
 * Feb 15th, 2022
 */

#pragma once
const int MISSING_SQUARE = -1;

//ADJUST THIS VALUE IF N IS > 12. 4096 works for 0 <= n <= 12
const int ARRAY_MAX_SIZE = 4096;
int board[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
int tCount = 0;

//function prototypes

// Sets all cells (0 to arrSize rows and columns) to 0
void initBoard(int arrSize);
// Outputs the current board (0 to arrSize rows and columns) to the console
void printBoard(int arrSize);
// places a single triomino at the given rows and columns.
void placeTriomino(unsigned int x1, unsigned int x2, unsigned int x3, unsigned int y1, unsigned int y2, unsigned int y3);


/*
 * recursive function that fills the board with triominoes.
 * base case: arrSize = 2, so that means we can have 1 triomino and 1 missing square.
 * recursive case: arrSize > 2, so that means we need more than one triomino.
 * Depending on where the missing square is, place a triomino at the center of the board in a way that each cell covers
 * 1 cell in the corners of each quadrant besides the one with the cell missing.
 * This means that we get 4 sub-boards each with 1 square missing.
 * call fillBoard again for each of the 4 subBoards.
 * function recurse, placing a triomino at the center of each quadrant, and again until arrSize = 2.
 * When arrSize = 2 that means the whole board is filled besides our base case, which we run and then quadrant is filled.
 * after 1 quadrant is filled, return to original function call, and call the next recursion for the next quadrant
 * this continues until all 4 quadrants are filled.
 */
int fillBoard(int arrSize, int startX, int startY);
