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
#include <list>
using namespace std;

