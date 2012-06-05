#include"SkyscraperBoard.h"

SkyscraperBoard::SkyscraperBoard() {
	//is_solved = false; // sets map status to not solved
	for (int i = 0; i < MAP_SIZE; i++) {		
		left[i] = 0; // initialize left conditions array to 0
		top [i] = 0; // initialize top conditions array to 0
		right[i] = 0; // initialize right conditions array to 0
		bottom[i] = 0; // initialize bottom conditions array to 0
	}
}

SkyscraperBoard::SkyscraperBoard(SkyscraperBoard & original) {
	for (int i = 0; i < MAP_SIZE; i++) {		
		left[i] = 0; 
		top [i] = 0; 
		right[i] = 0; 
		bottom[i] = 0; 
	}
}

bool SkyscraperBoard::is_latin(int matrix[MAP_SIZE][MAP_SIZE]) {
	int counter = 0;
	int building = 1;
	while (building <= MAP_SIZE) {
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				if (matrix[i][j] == building) {   // i-th row
					counter ++;
				}
				if (matrix[j][i] == building) {   // i-th column
					counter ++;
				}
			}
			if (counter != 1) {
				return false;
			}
			counter = 0;
		}
	}
	return true;
}

bool SkyscraperBoard::is_solution(int matrix[MAP_SIZE][MAP_SIZE]) {
	// Check rows
	for (int i = 0; i < MAP_SIZE; i++) {
		if (left[i] == 1) {
			if (matrix[i][0] != MAP_SIZE) {
				return false;
			}
			if (matrix[i][(MAP_SIZE - 1)] != (MAP_SIZE - (right[i] -1))) {
				return false;
			}
		}
		
		else if ((left[i] == MAP_SIZE) || (right[i] == MAP_SIZE)) {
			if (left[i] == MAP_SIZE) {
				for (int j = 0; j < MAP_SIZE; j++) {
					if (matrix[i][j] != (j+1)) {
						return false;
					}
				}
			}
			else {
				for (int j = MAP_SIZE - 1; j >=0; j--) {
					if (matrix[i][j] != (j+1)) {
						return false;
					}
				}
			}
		}

		else {
			int tallest_index = 0;
			int count_smaller = 0;
			int max = 0;
			
			for (int j = 0; j < MAP_SIZE; j++) {
				if (matrix[i][j] == MAP_SIZE) {
					tallest_index = j;
					break;
				}
			}

			if ((tallest_index < (left[i] - 1)) || (tallest_index > (MAP_SIZE - right[i]))) {
				return false;
			}

			for (int j = 0; j < tallest_index; j++) {
				if (matrix[i][j] > max) {
					count_smaller ++;
					max = matrix[i][j];
				}
			}

			if (count_smaller != (left[i] - 1)) {
				return false;
			}

			count_smaller = 0;

			for (int j = (MAP_SIZE - 1); j > tallest_index; j--) {
				if (matrix[i][j] > max) {
					count_smaller ++;
					max = matrix[i][j];
				}
			}

			if (count_smaller != (right[i] - 1)) {
				return false;
			}

			count_smaller = 0;
		}
	}
}

bool SkyscraperBoard::valid_borders() {

}

bool SkyscraperBoard::add(int matrix[MAP_SIZE]) {

}