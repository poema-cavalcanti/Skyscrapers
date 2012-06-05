#include "MatrixGenerator.h"

MatrixGenerator::MatrixGenerator() {
	int j = 1;
	for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
		if (j > MAP_SIZE) {
			j = 1;
		}
		matrix[i] = j;
		j++;
	}
}

void MatrixGenerator::generate() {
    int count = 0;
    do
    {
        if (board.add(matrix))
        {
            cout <<count << " : ";
            for ( int i = 0 ; i < (MAP_SIZE * MAP_SIZE) ; i++ ) {
                cout << matrix[ i ] <<" ";
			}
            cout <<"\n";
        }
        count++;
    } while ( next_permutation( matrix, matrix + (MAP_SIZE * MAP_SIZE) ) );

    cout <<count <<" permutations were tested\n";

	return;
}

void MatrixGenerator::set_board(SkyscraperBoard b) {
	board = b;
}