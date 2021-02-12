#include <iostream>
#include <string>
#include "Header.h"
#include <algorithm>

extern int wager, balance; 

using std::cout; using std::cin; using std::endl;

void ChooseNextMove() {

    extern std::string NextPlay;

    NextPlay = " ";
    //TODO broken if wrong once
    
    while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "double down" && NextPlay != "split" && NextPlay != "surrender") {

        cout << "Choose 'Stand', 'Hit', 'Double Down', 'Split' or 'Surrender': ";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(cin, NextPlay);

        std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(), [](unsigned char c) { return std::tolower(c); });


        if (NextPlay == "stand") {
            Stand();
        }
        else if (NextPlay == "hit") {
            Hit();
        }
        else if (NextPlay == "double down") {
            DoubleDown();
        }
        else if (NextPlay == "split") {
            if (wager > (balance / 2)) {
                cout << "Not enough credits availble to split\n";
                ChooseNextMove(); 
            } 
            else {
                Split();
            }
            
        }
        else if (NextPlay == "surrender") {
            Surrender();
        }
        
    }

}
