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

#ifndef MATRIXGENERATOR
#define MATRIXGENERATOR

class MatrixGenerator {
private:
	int matrix[MAP_SIZE * MAP_SIZE];
	SkyscraperBoard board;

public:
	MatrixGenerator();
	void generate(ostream & out);
	void set_board (SkyscraperBoard b);
};

#endif