#include "MatrixGenerator.h"

MatrixGenerator::MatrixGenerator() {
	int j = 1;
	for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
		if (j > MAP_SIZE) {
			j = 1;
		}
		gen_matrix[i] = j;
		j++;
	}
}

void MatrixGenerator::generate(ostream & out) {
	Board map;
    int count = 0;
	int row = -1;
	int col = 0;
    do {
		for (int i = 0; i < (MAP_SIZE * MAP_SIZE); i++) { // loop to put the values in matrix inside a two-dimensional array
			if ( i % MAP_SIZE == 0) {
				row ++;
				col = 0;
			}
			map.matrix[row][col] = gen_matrix[i];
			col ++;
		}
		row = -1;
		col = 0;
        if (map.is_latin()) {
            cout << count << " : ";
            for ( int i = 0 ; i < (MAP_SIZE * MAP_SIZE) ; i++ ) {
                cout << gen_matrix[i] <<" ";
			}
            cout <<"\n";
			latin_squares.insert(map, latin_squares.getSize());
        }
        count++;
    } while ( next_permutation( gen_matrix, gen_matrix + (MAP_SIZE * MAP_SIZE) ) );

    cout << count <<" permutations were tested\n";
	cout << "There are " << latin_squares.getSize() << " latin squares of order " << MAP_SIZE << "\n";
	//latin_squares.display(out);

	return;
}
