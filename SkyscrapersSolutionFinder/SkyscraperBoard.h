/****************************************************************************************
*	SKYSCRAPERS	CLASS																	*
*																						*
*	The following creates a SkyscrapersBoard class that holds information about a		*
*	Skycrapers map. The class will have whether the map has been solved, and what		*
*	values the buildings on the map have.												*
*																						*
*	"Empty" map locations will have a value of zero.									*
*	The maximum building size is MAP_SIZE.												*
****************************************************************************************/

#include <iostream>
using namespace std;

#include"LList.h"

const int MAP_SIZE = 4; // global variable for the number of rows and columns
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
	LList<int[][]> solutions;

public:
	SkyscraperBoard();
	SkyscraperBoard(SkyscraperBoard & original);
	bool is_latin(int matrix[MAP_SIZE][MAP_SIZE]);
	bool is_solution(int matrix[MAP_SIZE][MAP_SIZE]);
	bool valid_borders();
	bool add(int matrix[MAP_SIZE]);
};

#endif