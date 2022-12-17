#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cout, std::endl, std::string;

const string INPUT = "input.txt";

int get_priority(char val) {
	int total_priority = 0;

	if (val >= 'a') { //lowercase
		total_priority += int(val) - int('a') + 1;
	}
	else { //uppercase
		total_priority += 26 + int(val) - int('A') + 1;
	}

	return total_priority;
}

int main() {
	std::ifstream ifs;
	ifs.open(INPUT);
	if (ifs.is_open()) {
		string next_line = "";
		string comp1 = "";
		string comp2 = "";
		bool is_found = false;
		int total_priority = 0;
		while (std::getline(ifs, next_line)) {
			comp1 = next_line.substr(0, next_line.length() / 2);
			comp2 = next_line.substr(next_line.length() / 2, next_line.length() / 2);
			
			is_found = false;
			for (int i = 0; i < comp1.length(); i++) {
				for (int j = 0; j < comp2.length(); j++) {
					if (comp1[i] == comp2[j]) {
						is_found = true;
						total_priority += get_priority(comp1[i]);
						break;
					}
				}
				if (is_found) break;
			}
		}
		cout << "Total priority: " << total_priority << endl;
	}
	return 0;
}
