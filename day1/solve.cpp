#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using std::cout, std::endl, std::string;

const string INPUT = "input.txt";

int main() {
	std::ifstream ifs;
	ifs.open(INPUT);
	
	if (ifs.is_open()) {
		std::string next_line;
		int max_calories[3] = {0, 0, 0};
		int curr_total = 0;
		
		while (std::getline(ifs, next_line)) {
			// empty line means the end of the 
			// current elf's items
			if (next_line == "") {
				if (curr_total > max_calories[0]) {
					max_calories[0] = curr_total;
					std::sort(max_calories, max_calories+3);
				}
				
				curr_total = 0;
			}
			else {
				curr_total += stoi(next_line);
			}
		}

		int total_sum = 0;
		for (int i = 0; i < 3; i++) {
			cout << "Max calories " << i << ": " << max_calories[i] << endl;
			total_sum += max_calories[i];
		}
		cout << "Total sum: " << total_sum << endl;
	}
		
	return 0;
}
