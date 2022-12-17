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
		string line1 = "";
        string line2 = "";
        string line3 = "";
		string comp1 = "";
		string comp2 = "";
		bool is_found = false;
		int total_priority = 0;
		while (std::getline(ifs, line1)) {
            std::getline(ifs, line2);
            std::getline(ifs, line3);
			
			is_found = false;
			for (int i = 0; i < line1.length(); i++) {
				for (int j = 0; j < line2.length(); j++) {
                    for (int k = 0; k < line3.length(); k++) {
                        if ( (line1[i] == line2[j]) && (line2[j] == line3[k]) ) {
                            is_found = true;
                            total_priority += get_priority(line1[i]);
                            break;
                        }
                    }
                    if (is_found) break;
				}
				if (is_found) break;
			}
		}
		cout << "Total priority: " << total_priority << endl;
	}
	return 0;
}
