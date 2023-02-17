# a2CS310

This program tiles a 2^n x 2^n checkerboard with right triominoes with 1 cell missing. 

TO RUN & USE PROGRAM: 
<1> g++ q8.cpp -o output
<2> ./output
<3> enter inputs when prompted

Input given is n, and the row and column of the missing square.
Output is a tiling of the 2^n x 2^n checkerboard with right triominoes and 1 cell missing.


We have a base case of 2^1 * 2^1 = 4 cell checker board which can fit 1 triomino and 1 missing square.
	0    0  can be tiled like  -1    1
	0    0                      1    1
	
	
Our recursive case is when we have anything bigger than a 4 cell checker board:
	o - We first split our checker board into 4 quadrants; 1, 2, 3, and 4. (top left, top right, bottom left, and bottom right respectively)
	o - Then we check which quadrant our missing square is in.
	o - Depending on what quadrant the missing square is, we want to place a triomino in the centre of our 4 quadrants such that each cell of the triomino covers a corner of the quadrant except
	for the one that contains the missing square.
	o - an example
		
	    n = 3, mx = 1, my = 1
	    -------------------------------------
	    0    0    0    0    0    0    0    0
	    0   -1    0    0    0    0    0    0
	    0    0    0    0    0    0    0    0
	    0    0    0    0    1    0    0    0
	    0    0    0    1    1    0    0    0
	    0    0    0    0    0    0    0    0
	    0    0    0    0    0    0    0    0
	    0    0    0    0    0    0    0    0
	
	o - In the example since the square is in the top left (first) quadrant, we place our triomino so that it covers the corners of the quadrants besides quadrant 1.
	o - After we place our triomino in the centre, we call fillBoard again on each one of our quadrants.
	o - In each recursion, the quadrant is divided into 4 more quadrants, untill the size of each is 4 cells.
	o - when the size of a sub quadrant is 4, we run our base case , fill the last portion, and return.
	o - finally when all four recursive calls are finished, our board is finished.

**FOR N > 12, CONSTANT ARRAY_MAX_SIZE in Q8.h MUST BE SET TO A LARGER VALUE THAN 4096.**
So if input n = 13 (for example), MAX_ARRAY_SIZE >= 8192.


Idea based on this proof:
	https://jcsites.juniata.edu/faculty/kruse/cs315/Triominoes.pdf
