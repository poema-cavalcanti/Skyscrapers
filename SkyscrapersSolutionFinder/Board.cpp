#include "Board.h"

Board::Board() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			matrix[i][j] = 0;
		}
	}
}

Board::Board(Board & original) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			matrix[i][j] = original.matrix[i][j];
		}
	}
}

/**************************
* BOOL IS_LATIN (INT[][]) *
**************************/
bool Board::is_latin() {
	int counter = 0; // counter to keep track of the number of building of a particular height are in a row or column
	int building = 1; // the building height being searched for

	// To check for all building heights from 1 to MAP_SIZE
	while (building <= MAP_SIZE) { 
		for (int i = 0; i < MAP_SIZE; i++) { // main loop that uses i to count from 0 to MAP_SIZE
			for (int j = 0; j < MAP_SIZE; j++) { // inside loop that uses i as the row index and j as the column index
				if (matrix[i][j] == building) {   // count how many of the building type are in the i-th row
					counter ++;
				}
			}
			if (counter != 1) { // if the count is not equal to one, the square is not latin and the function returns false
				return false;
			}
			counter = 0; // return count to 0

			for (int j = 0; j < MAP_SIZE; j++) { // inside loop that uses j as the row index and i as the column index
				if (matrix[j][i] == building) {   // count how many of the building type are in the i-th column
					counter ++;
				}
			}
			if (counter != 1) { // if the count is not equal to one, the square is not latin and the function returns false
				return false;
			}
			counter = 0; // return count to 0
		}
		building ++; // increase the height of the building to check for
	}

	return true; // if the function reaches this point the square must be latin and the funstion returns true
}

/*****************************
* BOOL IS_SOLUTION (INT[][]) *
*****************************/
bool Board::is_solution(int top[MAP_SIZE], int bottom[MAP_SIZE], int left[MAP_SIZE], int right[MAP_SIZE]) {
	int tallest_index = 0; // index to store the location of the MAP_SIZE tall building
	int count_smaller = 0; // used to count the number of smaller buildings that can be seen from a vantage point
	int max = 0; // used to store the height of the buildings to help determine count_smaller

	// LOOP TO CHECK THAT THE BOUNDRY CONDITIONS FOR THE ROWS ARE BEING MET
	for (int i = 0; i < MAP_SIZE; i++) {
		/*
		// CHECK ROW CONDITIONS OF 1
		if ((left[i] == 1) || (right[i] == 1)) { 
			if (left[i] == 1) { // if the left condition is one
				if (matrix[i][0] != MAP_SIZE) { // but the building in front of that vantage point is not MAP_SIZE tall
					return false; // the conditions are not being met and the function returns false
				}
			}
			else { // if the right condition is one
				if (matrix[i][(MAP_SIZE - 1)] != MAP_SIZE) { // but the building in front of that vantage point is not MAP_SIZE tall
					return false; // the conditions are not being met and the function returns false
				}
			}
		}

		// CHECK ROW CONDITIONS OF MAP_SIZE
		if ((left[i] == MAP_SIZE) || (right[i] == MAP_SIZE)) { 
			if (left[i] == MAP_SIZE) { // if the left condition is MAP_SIZE
				for (int j = 0; j < MAP_SIZE; j++) { // loop through the row and check that each building is increasing
													 // in order from the left from 1 to MAP_SIZE
					if (matrix[i][j] != (j+1)) { // if a building is not the correct height
						return false; // conditions are not being met and the function returns false
					}
				}
			}
			else {
				for (int j = MAP_SIZE - 1; j >=0; j--) { // loop through the row and check that each building is increasing
													     // in order from the right from 1 to MAP_SIZE
					if (matrix[i][j] != (MAP_SIZE - j)) { // if a building is not the correct height
						return false; // conditions are not being met and the function returns false
					}
				}
			}
		}
		*/
		// ALL OTHER ROW CONDITIONS
		
		for (int j = 0; j < MAP_SIZE; j++) { // find the location of the MAP_SIZE building in the row
			if (matrix[i][j] == MAP_SIZE) {
				tallest_index = j; // and assign the value to tallest_index
				break;
			}
		}
		/*
		if ((tallest_index < (left[i] - 1)) || (tallest_index > (MAP_SIZE - right[i]))) { // if the MAP_SIZE building is
							// too close to the left to fulfil the boundry condition for the left-hand-side vantage point or
							// too close to the right to fulfil the boundry condition for the right-hand-side vantage point
			return false; // the conditions are not being met and the function returns false
		}
		*/
		for (int j = 0; j <= tallest_index; j++) { // going from left to right and not excluding the MAP_SIZE tall building
			if (matrix[i][j] > max) { // if a building is taller than the one before it 
				count_smaller ++; // increase the counter of how many buildings can be seen
				max = matrix[i][j]; // and assign the height to max in order to determine if another building can be seen
			}
		}

		if (count_smaller != left[i]) { // if the count of building that can be seen from the left does not match the left condition
			return false; // the function returns false
		}

		count_smaller = 0; // return count_smaller to 0
		max = 0; // return max to 0

		for (int j = (MAP_SIZE - 1); j >= tallest_index; j--) { // going from right to left and not excluding the MAP_SIZE tall building
			if (matrix[i][j] > max) { // if a building is taller than the one before it
				count_smaller ++; // increase the counter of how many buildings can be seen
				max = matrix[i][j]; // and assign the height to max in order to determine if another building can be seen
			}
		}

		if (count_smaller != right[i]) { // if the count of building that can be seen from the right does not match the right condition
			return false; // the function returns false
		}

		count_smaller = 0; // return count_smaller to 0
		max = 0; // return max to 0
		
//	}

	// LOOP TO CHECK THAT THE BOUNDRY CONDITIONS FOR THE COLUMNS ARE BEING MET
//	for (int i = 0; i < MAP_SIZE; i++) {
		/*
		// CHECK COLUMN CONDITIONS OF 1
		if ((top[i] == 1) || (bottom[i] == 1)) { 
			if (top[i] == 1) { // if the top condition is one
				if (matrix[0][i] != MAP_SIZE) { // but the building in front of that vantage point is not MAP_SIZE tall
					return false; // the conditions are not being met and the function returns false
				}
			}
			else { // if the bottom condition is one
				if (matrix[(MAP_SIZE - 1)][i] != MAP_SIZE) { // but the building in front of that vantage point is not MAP_SIZE tall
					return false; // the conditions are not being met and the function returns false
				}
			}
		}
		
		// CHECK COLUMN CONDITIONS OF MAP_SIZE
		if ((top[i] == MAP_SIZE) || (bottom[i] == MAP_SIZE)) { 
			if (top[i] == MAP_SIZE) { // if the top condition is MAP_SIZE
				for (int j = 0; j < MAP_SIZE; j++) { // loop through the column and check that each building is increasing
													 // in order from top to bottom from 1 to MAP_SIZE
					if (matrix[j][i] != (j+1)) { // if a building is not the correct height
						return false; // conditions are not being met and the function returns false
					}
				}
			}
			else { // if the bottom condition is MAP_SIZE
				for (int j = MAP_SIZE - 1; j >=0; j--) { // loop through the column and check that each building is increasing
													     // in order from bottom to top from 1 to MAP_SIZE
					if (matrix[j][i] != (MAP_SIZE - j)) { // if a building is not the correct height
						return false; // conditions are not being met and the function returns false
					}
				}
			}
		}
		*/
		// ALL OTHER COLUMN CONDITIONS
		
		for (int j = 0; j < MAP_SIZE; j++) { // find the location of the MAP_SIZE building in the column
			if (matrix[j][i] == MAP_SIZE) {
				tallest_index = j; // and assign the value to tallest_index
				break;
			}
		}
		/*
		if ((tallest_index < (top[i] - 1)) || (tallest_index > (MAP_SIZE - bottom[i]))) { // if the MAP_SIZE building is
							// too close to the top to fulfil the boundry condition for the top-side vantage point or
							// too close to the bottom to fulfil the boundry condition for the bottom-side vantage point
			return false; // the conditions are not being met and the function returns false
		}
		*/
		for (int j = 0; j <= tallest_index; j++) { // going from top to bottom and not excluding the MAP_SIZE tall building
			if (matrix[j][i] > max) { // if a building is taller than the one before it 
				count_smaller ++; // increase the counter of how many buildings can be seen
				max = matrix[j][i]; // and assign the height to max in order to determine if another building can be seen
			}
		}

		if (count_smaller != top[i]) { // if the count of building that can be seen from the top does not match the top-side condition
			return false; // the function returns false
		}

		count_smaller = 0; // return count_smaller to 0
		max = 0; // return max to 0

		for (int j = (MAP_SIZE - 1); j >= tallest_index; j--) { // going from bottom to top and not excluding the MAP_SIZE tall building
			if (matrix[j][i] > max) { // if a building is taller than the one before it
				count_smaller ++; // increase the counter of how many buildings can be seen
				max = matrix[j][i]; // and assign the height to max in order to determine if another building can be seen
			}
		}

		if (count_smaller != bottom[i]) { // if the count of building that can be seen from the bottom does not match the bottom-side condition
			return false; // the function returns false
		}

		count_smaller = 0; // return count_smaller to 0
		max = 0; // return max to 0
		
	}

	// Boundry conditions on all four sides are being met
	return true; // so function returns true
}

const Board & Board::operator=(const Board & rhs) {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			matrix[i][j] = rhs.matrix[i][j];
		}
	}
	return *this;
}

ostream& operator<< (ostream &out, const Board &b){		// '<<' operator overload (to use for the display function in llist)
	for (int i = 0; i < MAP_SIZE; i++) { 
		for (int j = 0; j < MAP_SIZE; j++){ 
			out << b.matrix[i][j] << " " ;
		}
		out << "\n" ; 
	}
	out << "\n---------------\n" ;
	return out;
}		

bool Board::operator==(const Board &b2){		// '==' operator overload
	for (int i = 0; i < MAP_SIZE; i++) { 
		for (int j = 0; j < MAP_SIZE; j++) { 
			if (matrix[i][j] != b2.matrix[i][j])
				return false;
		}
	}
	return true;
}

bool Board::operator!=(const Board &b2){		// '!=' operator overload
	return !(*this == b2);
}