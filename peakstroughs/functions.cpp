#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	if (a < 10 || a > b || b >= 10000) {//validation
		return false;
	}
	else {
		return true;
	}
}

char classify_pt_range_type(int number) {
	//returns 'P' if number has /\/\ pattern,
	//returns 'T' if number has \/\/ pattern, and return 'N' otherwise
	int count = 0;
	int num = number;
	while (num > 0) {
		count += 1;
		num /= 10;
	}
	num = number;
	int previous;
	int current;
	previous = num%10;
	count -= 1;
	num /= 10;
	current = num%10;
	bool direction;
	if (current > previous) {
		direction = true;
	} 
	if (current < previous) {
		direction = false;
	}
	if (current == previous) {
		return 'N';
	}
	bool newdir;
	while (count > 1) {	
		num /= 10;
		previous = current;
		current = num%10;
		if (current == previous) {
			return 'N';
		}
		if (current > previous) {
			newdir = true;
		} 
		if (current < previous) {
			newdir = false;
		}
		if (newdir == direction) {
			return 'N';
		}
		direction = newdir;
		count -= 1;
	}
	if (!direction) {
		return 'P';
	}
	if (direction) {
		return 'T';
	}
	return 'N';
}

void count_valid_pt_numbers(int a, int b) {
	int i;
	int peaks = 0;
	int troughs = 0;

	for (i=a; i<b+1; ++i) {
		if (classify_pt_range_type(i) == 'P') {
			peaks += 1;
		}
		else if (classify_pt_range_type(i) == 'T') {
			troughs += 1;
		}
	}
	cout << "There are " << peaks << " peaks and " << troughs << " troughs between " << a <<" and " << b <<"." << endl;
}
