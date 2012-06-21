/****************************************************************************************
*	SKYSCRAPERS	CLASS																	*
*																						*
*	The following creates a SkyscrapersBoard class that holds information about a		*
*	Skycrapers map.																		*
*																						*
*	The maximum building size is MAP_SIZE.												*
****************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include"LList.h"
#include"Board.h"

#ifndef SKYSCRAPERBOARD
#define SKYSCRAPERBOARD

class SkyscraperBoard
{
private:
	int left[MAP_SIZE];				// conditions for left side
	int top[MAP_SIZE];				// conditions for top side
	int right[MAP_SIZE];			// conditions for right side
	int bottom[MAP_SIZE];			// conditions for bottom side

public:
	LList<Board> solutions; // linked list to hold the board's possible solutions

	SkyscraperBoard();
	SkyscraperBoard(SkyscraperBoard & original);
	//bool valid_borders();
	void set(string s);
	bool add(Board b);
	void print(ostream & out) const;
	int num_solutions();

	const SkyscraperBoard& SkyscraperBoard::operator= (const string &s);
	const SkyscraperBoard& SkyscraperBoard::operator= (const SkyscraperBoard &rhs);
};

#endif