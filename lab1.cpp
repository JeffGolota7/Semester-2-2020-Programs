#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct candidate {
    string name;
    int voteCount = 0;
    bool running = false;
};
bool sortVotes (candidate a, candidate b) {
        if(a.voteCount > b.voteCount){
            return 1;
        }
        else {
            return 0;
        }
}
int main() {
    candidate list [10];
    ifstream input;
    string currentName;
    ofstream output;
    bool found = false;
    int count = 0;
    input.open("votes.txt");

    while (input.good()) {
        input >> currentName;
        for (int i =0; i < 10; ++i) {
            if (currentName == list[i].name) {
                found = true;
                list[i].voteCount++;
                break;
            }
        }
        if (found == false) {
            list[count].name = currentName;
            ++list[count].voteCount;
            ++count;
            list[count].running = true;
        }
        found = false;
    }
    output.open("results.txt");
    for (int i = 0; i < 10; ++i) {
        if (list[i].voteCount == 0) {
            list[i].running = false;
        }
    }
    sort (list, list+10, sortVotes);
    output << "Winner: ";
    for (int i = 0; i < 10; ++i) {
        if (list[i].running == true) {
            output << list[i].name << endl;
            output << "Votes: " << list[i].voteCount << endl;
            output << "--------------------------------" << endl;
        }
    }

    return 0;
}