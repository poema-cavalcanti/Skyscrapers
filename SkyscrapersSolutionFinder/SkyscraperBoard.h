/****************************************************************************************
*	SKYSCRAPERS	CLASS																	*
*																						*
*	The following creates a SkyscrapersBoard class that holds information about a		*
*	Skycrapers map.																		*
*																						*
*	The maximum building size is MAP_SIZE.												*
****************************************************************************************/

#include <iostream>
using namespace std;

#include"LList.h"

const int MAP_SIZE = 4; // global constant for the number of rows and columns
						// MAP_SIZE also determines how tall the tallest building can be

#ifndef SKYSCRAPERBOARD
#define SKYSCRAPERBOARD

class SkyscraperBoard
{
private:
	int left[MAP_SIZE];				// conditions for left side
	int top[MAP_SIZE];				// conditions for top side
	int right[MAP_SIZE];			// conditions for right side
	int bottom[MAP_SIZE];			// conditions for bottom side

	class Board {					// class to hold the board matrix in order to use list
	public:
		int matrix[MAP_SIZE][MAP_SIZE];  // array in which 2d array will be stored
		friend ostream& operator<< (ostream &out, Board &cBoard) {		// '<<' operator overload for the display function in llist
			out << "\n---------------\n" ;
			for (int i = 0; i < MAP_SIZE; i++) { 
				for (int j = 0; j < MAP_SIZE; j++) 
				{ out << cBoard.matrix[i][j] << " " ; }
				out << "\n" ; }
			out << "\n---------------\n" ;
		}
	};

	LList<Board> solutions; // linked list to hold the board's possible solutions

public:
	SkyscraperBoard();
	SkyscraperBoard(int t[MAP_SIZE], int b[MAP_SIZE], int l[MAP_SIZE], int r[MAP_SIZE]);
	SkyscraperBoard(SkyscraperBoard & original);
	bool is_latin(int matrix[MAP_SIZE][MAP_SIZE]);
	bool is_solution(int matrix[MAP_SIZE][MAP_SIZE]);
	//bool valid_borders();
	bool add(int matrix[MAP_SIZE * MAP_SIZE]);
	void print(ostream & out) const;
};

#endif