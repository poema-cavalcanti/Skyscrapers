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
*			  
*			  The cases which produce multiple answers in 4x4 matrices are described below:
*
*			  Multiple 4 and 3 solutions
*			  When the conditions around the grid are like so:
*			    X 2 2 X
*			  X			X
*			  2			2
*			  2			2
*			  X			X
*			    X 2 2 X
*			  Then four possible solutions are:
*			  1.				2.				3.				4.
*			    X 2 2 X			  X 2 2 X		  X 2 2 X		  X 2 2 X	
*			  X|	   |X		X|	     |X		X|	     |X		X|	     |X
*			  2|3 4    |2		2|  4   3|2		2|3   4  |2		2|    4 3|2
*			  2|    4 3|2		2|3   4  |2		2|  4   3|2		2|3 4    |2
*			  X|	   |X		X|	     |X		X|	     |X		X|	     |X
*			    X 2 2 X			  X 2 2 X		  X 2 2 X		  X 2 2 X	
*			  With the empty spaces on the grid to be filled out according to the values of X.
*
*	Author: Poema Cavalcanti
*	Date: 06/06/2012
**********************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "SkyscraperBoard.h"
#include "MatrixGenerator.h"

int main() {
	MatrixGenerator gen;
	gen.generate(cout);

	string line;
	int expected_size;
	SkyscraperBoard board[438];
	int k = 0;

	ifstream myfile;
	myfile.open("borders.txt", ifstream::in);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> line >> expected_size;
			board[k].set(line);
			cout << line << " " << expected_size;

			for(int i = 0; i < gen.latin_squares.getSize(); i++) {
				board[k].add(gen.latin_squares.get_element_data(i));
			}

			if(expected_size != board[k].solutions.getSize()) {
				cout << "Error with board " << line
					 << " expected " << expected_size 
					 << " but found " << board[k].solutions.getSize()
					 << " solutions." << endl;
				break;
			}

			k++;
		}
		myfile.close();
	}
    else {
		cout << "Unable to open file";
	}

	ofstream outfile;
	outfile.open("boards.txt", fstream::out);

	if (outfile.is_open())
	{
		while (outfile.good())
		{
			for (int i = 0; i < 438; i++) {
				board[i].print(outfile);
			}
			break;
		}
		outfile.close();
	}
    else {
		cout << "Unable to open file";
	}


	return 0;
}