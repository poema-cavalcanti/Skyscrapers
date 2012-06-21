/******************************************************************************
  Title: MatrixGenerator.h
  Abstract: Generates all permutations of placing numbers 1 through n inside
			of an n x n matrix.
  Author: Poema Cavalcanti
*******************************************************************************/

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#include"LList.h"
#include"SkyscraperBoard.h"
#include"Board.h"

#ifndef MATRIXGENERATOR
#define MATRIXGENERATOR

class MatrixGenerator {
private:
	int gen_matrix[MAP_SIZE * MAP_SIZE];

public:
	LList<Board> latin_squares;
	MatrixGenerator();
	void generate(ostream & out);
};

#endif