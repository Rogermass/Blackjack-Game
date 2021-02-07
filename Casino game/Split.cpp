#include "Header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using std::cout; using std::cin; using std::endl;

void Split() {

    extern int PCard1;
    extern int PCard2;
    extern int PHand1, PHand2; 
    extern std::vector<int> cards;
    extern int wager, balance; 
    extern int DCard1, DCard2; 

    if (PCard1 == PCard2) {

        int wager1, wager2; 

        wager1 = wager; 
        wager2 = wager; 

        srand((unsigned)time(0));
        
        int PHCardEx1 = cards[rand() % 13];
        int PHCardEx2 = cards[rand() % 13];

        PHand1 = PHCardEx1 + PCard1; 
        PHand2 = PHCardEx2 + PCard2; 

        cout << "Your first hand's first card is " + std::to_string(PCard1) + ", your second card in the hand is " + std::to_string(PHCardEx1) + "\n";
        cout << "Your second hand's first card is " + std::to_string(PCard2) + ", your second card in the hand is " + std::to_string(PHCardEx2) + "\n";

        if (PHand1 == 21) {
            wager1 *= 3;
            balance += wager1;
            cout << "Congratulations! Your first hand won a blackjack! ";
            cout << "Your first hand won " + std::to_string(wager1) + " credits"; 
        }
        else if (PHand1 > 21) {
            balance -= wager1;
            cout << "Bust!, you've lost your entire wager, your first hands total was " + std::to_string(PHand1) + "\n";

        }
        if (PHand2 == 21) {
            wager2 *= 3;
            balance += wager2;
            cout << "Congratulations! Your first hand won a blackjack! ";
            cout << "Your first hand won " + std::to_string(wager2) + " credits";
        }
        else if (PHand2 > 21) {
            balance -= wager2;
            cout << "Bust!, you've lost your entire wager, your first hands total was " + std::to_string(PHand2) + "\n";

        }
        
        if (PHand1 < 21) {
            
            cout << "Chose what you want to do with your first hand\n";
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
                    Split();
                }
                else if (NextPlay == "surrender") {
                    Surrender();
                }

            }

        }
            

    }
    else {
        cout << "You can't split because your two cards aren't the same";
        ChooseNextMove();

    }


}