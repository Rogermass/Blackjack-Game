#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Header.h"

using std::cout; using std::cin; using std::endl;

extern int PCard1;
extern int PCard2;
extern int PHand1, PHand2;
extern std::vector<int> cards;
extern int wager, balance;
extern int DCard1, DCard2;
extern int standh1;
extern std::string FirstH, SecondH, NextPlay; 
extern int t;
//extern std::string NextPlay1, NextPlay2;
extern int wager1; 

void HitH1() {

    

    PHand1 = HitforHand(wager1, PHand1, FirstH);

    extern std::string NextPlay;

    NextPlay = " ";

    while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "surrender") {
        cout << "Choose 'Stand', 'Hit', or 'Surrender': ";
        getline(cin, NextPlay);

        std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
            [](unsigned char c) { return std::tolower(c); });
    }
    if (NextPlay == "stand") {

        standh1 = 1; 
    }
    else if (NextPlay == "hit") {
        HitH2();
    }
    else if (NextPlay == "double down") {
        // DoubleDown();
    }
    else if (NextPlay == "surrender") {

    }
    
}