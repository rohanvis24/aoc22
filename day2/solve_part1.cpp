#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cout, std::endl, std::string;

const string INPUT = "input.txt";

// A/X = Rock
// B/Y = Paper
// C/Z = Scissors

int rps_decision(char our_pick, char their_pick) {
    int total_val = 0;
    int ours;
    int theirs;
    if (our_pick == 'X') { total_val += 1; ours = 1; }
    else if (our_pick == 'Y') { total_val += 2; ours = 2; }
    else if (our_pick == 'Z') { total_val += 3; ours = 3; }
    else { cout << "Something went wrong lmao" << endl; }

    if (their_pick == 'A') { theirs = 1; }
    else if (their_pick == 'B')  { theirs = 2; }
    else if (their_pick == 'C') { theirs = 3; }
    else { cout << "Something went wrong lmao" << endl; }

    if (ours == theirs) total_val += 3;
    else if ( (ours == 1) && (theirs == 3) || 
              (ours == 2) && (theirs == 1) ||
              (ours == 3) && (theirs == 2)) { total_val += 6; }

    return total_val;
}

int main() {
    std::ifstream ifs;
    ifs.open(INPUT);

    if (ifs.is_open()) {
        string next_line;
        std::stringstream s;
        char our_pick;
        char their_pick;
        int total_score = 0;
        int curr_score;
        while (std::getline(ifs, next_line)) {
            s << next_line;
            s >> their_pick >> our_pick;
            
            curr_score = rps_decision(our_pick, their_pick);
            total_score += curr_score;
        }

        cout << "Total score: " << total_score << endl;
    }

    return 0;
}