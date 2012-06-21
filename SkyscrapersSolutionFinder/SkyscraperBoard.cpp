#include"SkyscraperBoard.h"

/***************************************
* SKYSCRAPER BOARD DEFAULT CONSTRUCTOR *
***************************************/
SkyscraperBoard::SkyscraperBoard() {
	for (int i = 0; i < MAP_SIZE; i++) {		
		left[i] = 0; 
		top [i] = 0; 
		right[i] = 0; 
		bottom[i] = 0; 
	}
}

/********************
* SET (STRING, INT) *
*********************/
void SkyscraperBoard::set(string s) {
	int j = 0;
	for (int i = 0; i < MAP_SIZE; i++) { 
		left[j] = (int) s[i] - 48;
		j++;
	}
	j = 0;
	for (int i = MAP_SIZE; i < (2 * MAP_SIZE); i++) { 
		right[j] = (int) s[i] - 48;
		j++;
	}
	j = 0;
	for (int i = (2 * MAP_SIZE); i < (3 * MAP_SIZE); i++) { 
		top[j] = (int) s[i] - 48;
		j++;
	}
	j = 0;
	for (int i = (3 * MAP_SIZE); i < (4 * MAP_SIZE); i++) { 
		bottom[j] = (int) s[i] - 48;
		j++;
	}
}


/************************************
* SKYSCRAPER BOARD COPY CONSTRUCTOR *
************************************/
SkyscraperBoard::SkyscraperBoard(SkyscraperBoard & original) {
	for (int i = 0; i < MAP_SIZE; i++) {		
		left[i] = original.left[i]; // copy left conditions array
		top [i] = original.top[i]; // copy top conditions array
		right[i] = original.right[i]; // copy right conditions array
		bottom[i] = original.bottom[i]; // copy bottom conditions array
	}
}



/****************************
* BOOL VALID_BORDERS (VOID) *
* incomplete				*
****************************/
//bool SkyscraperBoard::valid_borders() { }

/*******************
* BOOL ADD (BOARD) *
*******************/
bool SkyscraperBoard::add(Board b) {
	if (b.is_solution(top, bottom, left, right)) { // if the map is a solution
		solutions.insert(b, solutions.getSize()); // insert into solutions list
		return true; // and return true because the map was successfully added
	}

	else {
		return false; // otherwise, return false
	}
}

/***********************
* VOID PRINT (OSTREAM) *
***********************/
void SkyscraperBoard::print(ostream & out) const {
	out << "*************************************\nThe solution(s) for the border conditions\n  " ;
	for (int i = 0; i < MAP_SIZE; i++) {
		out << top[i] << " " ;
	}
	out << "\n";
	for (int i = 0; i < MAP_SIZE; i++) {
		out << left[i] << " " ;
		for (int j = 0; j < MAP_SIZE; j++) {
			out << "  " ;
		}
		out << right[i] << "\n" ;
	}
	out << "  " ;
	for (int i = 0; i < MAP_SIZE; i++) {
		out << bottom[i] << " " ;
	}
	out << "\n\n" ;
	solutions.display(out);
}

int SkyscraperBoard::num_solutions() {
	return (solutions.getSize());
}

const SkyscraperBoard& SkyscraperBoard::operator= (const string &s) {
	int j = 0;
	for (int i = 0; i < MAP_SIZE; i++) {
		top[i] = s[j];
		j++;
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		bottom[i] = s[j];
		j++;
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		left[i] = s[j];
		j++;
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		right[i] = s[j];
		j++;
	}

	return *this;
}

const SkyscraperBoard& SkyscraperBoard::operator= (const SkyscraperBoard &rhs) {
	for (int i = 0; i < MAP_SIZE; i++) {		
		left[i] = rhs.left[i]; 
		top [i] = rhs.top[i]; 
		right[i] = rhs.right[i]; 
		bottom[i] = rhs.bottom[i];
	}
	return *this;
}