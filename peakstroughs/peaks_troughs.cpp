#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int a = 0;
	int b = 0;
	while (!is_valid_range(a,b)) {
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	cin >> a >> b;

	if (!is_valid_range(a,b)) {
		cout << "Invalid Input" << endl;
	}
}
	classify_pt_range_type(a);
	count_valid_pt_numbers(a,b);
	//cout<<classify_pt_range_type(554);
	return 0;
}