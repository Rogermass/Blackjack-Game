#include "Header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using std::cout; using std::cin; using std::endl;

extern int PCard1;
extern int PCard2;
extern int PHand1, PHand2;
extern std::vector<int> cards;
extern int wager, balance;
extern int DCard1, DCard2, DCardT;
extern int standh1;
extern std::string FirstH, SecondH;
extern int t, x;
extern std::string NextPlay1, NextPlay2;
extern int wager1, wager2;

void HitH2() {
    
     

    PHand2 = HitforHand(wager2, PHand2, SecondH);
    
    if (PHand2 == 21) {
        
        if (standh1 == 1) {
            t = 0; x = 1;
            StandforHand(wager1, PHand1, FirstH);
            t = 1; x = 0;
            StandforHand(wager2, PHand2, SecondH);

        }
        else {

            StandforHand(wager2, PHand2, SecondH);
        }
    }
    else if (PHand2 > 21) {
        
        if (standh1 == 1) {
            
            t = 0; x = 1;
            StandforHand(wager1, PHand1, FirstH);
            
            t = 1; x = 0;
            
            StandforHand(wager2, PHand2, SecondH);
            

        }
        else {

            StandforHand(wager2, PHand2, SecondH);
        }
    }
    else {
        extern std::string NextPlay;

        NextPlay = " ";

        while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "surrender" && NextPlay != "double down") {
            cout << "Choose what to do next to your second hand, 'Stand', 'Hit', 'Double Down' or 'Surrender': ";
            getline(cin, NextPlay);

            std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
                [](unsigned char c) { return std::tolower(c); });
        }
        if (NextPlay == "stand") {

            if (standh1 == 1) {
                t = 0;
                StandforHand(wager1, PHand1, FirstH);
                StandforHand(wager2, PHand2, SecondH);

            }
            else {
                t = 1; x = 1;
                StandforHand(wager2, PHand2, SecondH);
            }
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
    


}