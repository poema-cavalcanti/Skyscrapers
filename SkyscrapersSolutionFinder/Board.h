#include <iostream>
using namespace std;

#ifndef BOARD
#define BOARD

const int MAP_SIZE = 4; // global constant for the number of rows and columns
						// MAP_SIZE also determines how tall the tallest building can be

class Board {					// class to hold the board matrix in order to use list
public:
	int matrix[MAP_SIZE][MAP_SIZE];  // array in which 2d array will be stored
	Board();
	Board(Board & original);
	bool is_latin();
	bool is_solution(int top[MAP_SIZE], int bottom[MAP_SIZE], int left[MAP_SIZE], int right[MAP_SIZE]);

	const Board & operator=(const Board & rightHandSide);

	friend ostream& operator<< (ostream &out, const Board &b);		// '<<' operator overload (to use for the display function in llist)		

	bool operator==(const Board &b2);		// '==' operator overload

	bool operator!=(const Board &b2);		// '!=' operator overload

};

#endif