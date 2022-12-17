#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cout, std::endl, std::string, std::ifstream, std::getline;

const string INPUT = "input.txt";

int main() {
	ifstream ifs;
	ifs.open(INPUT);
	if (ifs.is_open()) {
		string tmp;
		int first_range_low;
		int first_range_high;
		int second_range_low;
		int second_range_high; 
		int complete_overlap_counter = 0;
		int partial_overlap_counter = 0;

		while (getline(ifs, tmp, '-')) {
			first_range_low = stoi(tmp);
			getline(ifs, tmp, ',');
			first_range_high = stoi(tmp);
			getline(ifs, tmp, '-');
			second_range_low = stoi(tmp);
			getline(ifs, tmp);
			second_range_high = stoi(tmp);

			if ((first_range_high - first_range_low) < (second_range_high - second_range_low)) {
				if ((first_range_low >= second_range_low) && (first_range_high <= second_range_high)) {
					complete_overlap_counter += 1;
				}
			}
			else {
				if ((first_range_low <= second_range_low) && (first_range_high >= second_range_high)) {
					complete_overlap_counter += 1;
				}
			}
			if (((first_range_high >= second_range_low) && (first_range_low <= second_range_low)) || ((second_range_high >= first_range_low) && (second_range_low <= first_range_low))) {
				partial_overlap_counter += 1;
			}
		}
		cout << "Complete overlap counter: " << complete_overlap_counter << endl;
		cout << "Partial overlap counter: " << partial_overlap_counter << endl;
	}
	return 0;
}