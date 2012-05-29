/*********************************************************************************************************************
*	Title: Skyscraper
*	Abstract: This program simulates the game Skyscrapers. For a given border configuration, the program will
*			  use the rules to complete the puzzles. If there is more than one possible solution, the program
*			  outputs all answers.
*			  
*			  Rules
*			  - Every square contains a skyscraper.
*			  - Complete the grid such that every row and column contains the numbers 1 to the size of the grid.
*			  - Every row/column contains each number exactly once.
*			  - The numbers (referred to as conditions) around the grid tell you how many skyscrapers you can see.
*			  - You can't see a shorter skyscraper behind a taller one.
			  
			  The cases which produce multiple answers in 4x4 matrices are described below:

			  Multiple 4 and 3 solutions
			  When the conditions around the grid are like so:
			    X 2 2 X
			  X			X
			  2			2
			  2			2
			  X			X
			    X 2 2 X
			  Then four possible solutions are:
			  1.				2.				3.				4.
			    X 2 2 X			  X 2 2 X		  X 2 2 X		  X 2 2 X	
			  X|	   |X		X|	     |X		X|	     |X		X|	     |X
			  2|3 4    |2		2|  4   3|2		2|3   4  |2		2|    4 3|2
			  2|    4 3|2		2|3   4  |2		2|  4   3|2		2|3 4    |2
			  X|	   |X		X|	     |X		X|	     |X		X|	     |X
			    X 2 2 X			  X 2 2 X		  X 2 2 X		  X 2 2 X	
			  With the empty spaces on the grid to be filled out according to the values of X.

*	Author: Poema Cavalcanti
*	Date: 30/05/2012
**********************************************************************************************************************/

#include <iostream>
#include <list>
using namespace std;

const int MAP_SIZE = 4; // global variable for the number of rows and columns
						// MAP_SIZE also determines how tall the tallest building can be

/****************************************************************************************
*	SKYSCRAPERS	CLASS																	*
*																						*
*	The following creates a class called Skyscrapers that holds information about a		*
*	Skycrapers map. The class will have whether the map has been solved, and what		*
*	values the buildings on the map have.												*
*																						*
*	"Empty" map locations will have a value of zero.									*
*	The maximum building size is MAP_SIZE.												*
****************************************************************************************/
class Skyscrapers {
private:
	bool is_solved;					// solution status
	int left[MAP_SIZE];				// conditions for left side
	int top[MAP_SIZE];				// conditions for top side
	int right[MAP_SIZE];			// conditions for right side
	int bottom[MAP_SIZE];			// conditions for bottom side
	int map[MAP_SIZE][MAP_SIZE];	// a two-dimensional array that holds the "map" of the skyscraper positions
public:
	// CONSTRUCTOR
	Skyscrapers() {
		is_solved = false; // sets map status to not solved
		for (int i = 0; i < MAP_SIZE; i++) {		// loop through rows
			for (int j = 0; j < MAP_SIZE; j++) {	// loop through columns
				map[i][j] = 0;				// set to zero
			}
			left[i] = 0; // initialize left conditions array to 0
			top [i] = 0; // initialize top conditions array to 0
			right[i] = 0; // initialize right conditions array to 0
			bottom[i] = 0; // initialize bottom conditions array to 0
		}
	}

	// SET VALUE
	void set_value(int a, int b, int value);

	// SOLVE NEXT
	bool solve_next(int num); // returns true after solving OR false if the number to be solved is already solved

	// FINISH SOLVING
	bool finish_solving(); // if possible, completes the map and returns true OR false otherwise

	// SPLIT
	friend Skyscrapers split (Skyscrapers branch);
};

void Skyscrapers::set_value(int a, int b, int value)
{
	map[a][b] = value;
}

bool Skyscrapers::solve_next(int num)
{
	if (num <= 0 || num > MAP_SIZE) {
		cout << "Input is not a valid building size." << endl;
		return false;
	}

	switch(num) {
	case MAP_SIZE :
		for (int i=1; i <= MAP_SIZE; i++) {
			if (left[i] == 1) {
				map[i][0] = MAP_SIZE;
			}
		}
	case 1 :

	default:

	}

}