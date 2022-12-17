#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cout, std::endl, std::string;

const string INPUT = "input.txt";

// A/X = Rock
// B/Y = Paper
// C/Z = Scissors

int rps_selection(char result, char their_pick) {
    int total_val = 0;
    int theirs = 0;
    
    if (their_pick == 'A') { theirs = 1; }
    else if (their_pick == 'B')  { theirs = 2; }
    else if (their_pick == 'C') { theirs = 3; }
    else { cout << "Something went wrong lmao" << endl; }

    if (result == 'X') { // lose
        total_val += (((theirs - 1) - 1 + 6) % 3) + 1;
    }
    else if (result == 'Y') { //draw
        total_val += theirs;
        total_val += 3;
    }
    else if (result == 'Z') { // win
        total_val += (((theirs - 1) + 1 + 6) % 3) + 1;
        total_val += 6;
    }
    else {
        cout << "Something weird happened" << endl;
    }
    cout << total_val << endl;
    return total_val;
}

int main() {
    std::ifstream ifs;
    ifs.open(INPUT);

    if (ifs.is_open()) {
        string next_line;
        std::stringstream s;
        char their_pick;
        char result;
        int total_score = 0;
        int curr_score;
        while (std::getline(ifs, next_line)) {
            s << next_line;
            s >> their_pick >> result;
            cout << their_pick << " " << result << endl;
            
            curr_score = rps_selection(result, their_pick);
            total_score += curr_score;
        }

        cout << "Total score: " << total_score << endl;
    }

    return 0;
}