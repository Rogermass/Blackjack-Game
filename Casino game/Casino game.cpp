
#include <iostream>
#include "Header.h"
#include <cstdlib>
#include <string>
#include <vector>



int balance = 1000;
int wager; 
int i, t; 
int PlayorNot;
int PTotalCard;
int DCard1, DCard2;
int PCard1, PCard2;
int DCardT, DCardEx;
std::string NextPlay1; std::string NextPlay2;
char NextPlayA [];
int PHand1, PHand2;
std::string NextPlay; 
using std::cout; using std::cin;
int wager1, wager2;
int standh1; 
std::string FirstH = "first"; std::string SecondH = "second";
int x = 1;
std::vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 11, 10, 10, 10, 10 };



int main()
{

    
    cout << "Sir this is a casino and you're Playing Blackjack!\n"; 
    
        
        WagerAmmount();

        GenerateCards();

        ChooseNextMove();

}

