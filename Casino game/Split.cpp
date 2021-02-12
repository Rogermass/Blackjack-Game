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
    extern int standh1; 
    extern std::string FirstH, SecondH; 
    extern int t, x; 
    extern std::string NextPlay1; std::string NextPlay2;
      standh1 = 0; 

      //TODO disproportionate amount of 10s; 

    if (PCard1 == PCard2) {

        extern int wager1, wager2;

        wager1 = wager; 
        wager2 = wager; 

        srand((unsigned)time(0));
        
        int PHCardEx1 = cards[rand() % 13];
        int PHCardEx2 = cards[rand() % 13];
        //TODO chose wether 11 or 1
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

            NextPlay1 = " ";
            //TODO broken if wrong once

            if (PHand2 > 21) {
                
                NextPlay1 = " ";

                while (NextPlay1 != "stand" && NextPlay1 != "hit" && NextPlay1 != "double down"  && NextPlay1 != "surrender") {



                    cout << "Choose what you want to do with your first hand, choose 'Stand', 'Hit', 'Double Down' or 'Surrender': ";



                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(cin, NextPlay1);

                    std::transform(NextPlay1.begin(), NextPlay1.end(), NextPlay1.begin(), [](unsigned char c) { return std::tolower(c); });


                    if (NextPlay1 == "stand") {
                        t = 1; x = 1; 
                        StandforHand(wager1, PHand1, FirstH);
                    }
                    else if (NextPlay1 == "hit") {
                        HitH1();
                    }
                    else if (NextPlay1 == "double down") { 
                        // DoubleDown();
                    }
                    else if (NextPlay1 == "surrender") {
                        //SurrenderforHand(wager1, PHand1);
                    }

                }


            }
            
            else if (PHand2 < 21) {
                
                NextPlay1 = " ";



                while (NextPlay1 != "hit" && NextPlay1 != "double down" && NextPlay1 != "stand") {


                    cout << "Choose what you want to do with your first hand, choose 'Hit', 'Double Down', 'Surrender' or 'Stand': ";


                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(cin, NextPlay1);

                    std::transform(NextPlay1.begin(), NextPlay1.end(), NextPlay1.begin(), [](unsigned char c) { return std::tolower(c); });


                    if (NextPlay1 == "stand") {
                        standh1 = 1;
                    }
                    else if (NextPlay1 == "hit") {
                        HitH1();
                    }
                    else if (NextPlay1 == "double down") {
                        // DoubleDown();
                    }
                }

            }
                
            

        }

        if (PHand2 < 21) {

            //TODO add bust if after hitting over 21
            

            NextPlay2 = " ";
            //TODO broken if wrong once

            while (NextPlay2 != "stand" && NextPlay2 != "hit" && NextPlay2 != "double down" && NextPlay2 != "surrender") {
                
                cout << "Choose what you want to do with your second hand, choose 'Hit', 'Double Down', 'Surrender' or 'Stand': ";
                    
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(cin, NextPlay2);

                std::transform(NextPlay2.begin(), NextPlay2.end(), NextPlay2.begin(), [](unsigned char c) { return std::tolower(c); });
                

                if (NextPlay2 == "hit") {
                    HitH2();
                }
                
                else if (NextPlay2 == "stand") {
                    
                    if (standh1 == 1) {
                        cout << "standh1 run" << endl; 
                        t = 0; x = 1;
                        StandforHand(wager1, PHand1, FirstH);
                        t = 1; x = 0; 
                        StandforHand(wager2, PHand2, SecondH);

                    }
                    else {
                        
                        StandforHand(wager2, PHand2, SecondH);
                    }
                }
                else if (NextPlay2 == "double down") {
                    // DoubleDown();
                }
                else if (NextPlay2 == "surrender") {

                }

            }

        }

        if (PHand2 > 21 && PHand1 > 21) {

        }

        

    }
    



    else {
        cout << "You can't split because your two cards aren't the same. ";
        ChooseNextMove();

    }


}