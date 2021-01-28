
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>


using std::cout; using std::cin; using std::endl; 

void Surrender();
void Hit();
void Stand();
void DoubleDown();
void Split();
void PlayorNoPlay();
void ChooseNextMove();


int WagerAmmount() {
    extern int wager;
    extern int balance;


    if (balance == 0) {
        cout << "Sorry no credits available";
        exit(EXIT_SUCCESS);

    }
    else {
        std::cout << "Current credit balance " + std::to_string(balance) + "\n"; std::cout << "Enter wagering amount: ";
        std::cin >> wager;
    }
    

   

        while (wager > balance) {
            std::cout << "Not enough credits available\n";
            std::cout << "Enter wagering amount: ";
            std::cin >> wager;
        }
 

    return wager;
}

int PCard1; int PCard2;
int DCard1; int DCard2;
std::vector<int> cards = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 10, 10, 10 }; // TODO fix ace for computer

void AcePossible() {

    srand((unsigned)time(0));


    PCard1 = cards[rand() % 13];
    PCard2 = cards[rand() % 13];
    DCard1 = cards[rand() % 13];
    DCard2 = cards[rand() % 13];


    if (PCard1 == 11 && PCard2 == 11) {

        cout << "Your two cards are aces choose if you want the first one to be worth 11 or 1: " << endl;
        cin >> PCard1;
        cout << "Choose if you want the second one to be worth 11 or 1: ";
        cin >> PCard2;

    }
    else if (PCard1 == 11 && PCard2 != 11) {

        cout << "Your first cards is " + std::to_string(PCard2) + ", ";
        cout << "your second card is an Ace, do you want it to be worth 11 or 1? ";
        cin >> PCard1;

    }
    else if (PCard2 == 11 && PCard1 != 11) {

        cout << "Your first cards is " + std::to_string(PCard1) + ", ";
        cout << "your second card is an Ace, do you want it to be worth 11 or 1? ";
        cin >> PCard2;

    }

    else {

        cout << "Your first cards is " + std::to_string(PCard1) + " your second card is " + std::to_string(PCard2) << endl;
        cout << "The dealers shown card is " + std::to_string(DCard1) << endl;
    }
}

void GenerateCards() {
   
    std::string DrawCards;
    extern int balance;
    extern int wager;



    cout << "Enter 'yes' to begin playing\n";
    cin >> DrawCards;

    std::transform(DrawCards.begin(), DrawCards.end(), DrawCards.begin(),
        [](unsigned char c) { return std::tolower(c); });
   

    if (DrawCards == "yes") {
        
        
        AcePossible(); 
        

        if (PCard1 + PCard2 == 21 && DCard1 + DCard2 != 21) {
            wager *= 1.5;
            balance += wager; 
            cout << "Congratulations! You won a blackjack!";
            cout << "Your have won " + std::to_string(wager) + ", Your total balance is " + std::to_string(balance) << endl;
            PlayorNoPlay();
        }
        else if (PCard1 + PCard2 == 21 && DCard1 + DCard2 == 21) {
            cout << "Push!, the dealers second card was " + std::to_string(DCard2); 
            cout << "You'll recieve your initial wager back\n Your balance is " + std::to_string(balance) << endl;
            PlayorNoPlay();
        }
        else if (PCard1 + PCard2 > 21) {
            balance -= wager;
            cout << "Bust!, you've lost your entire wager\nYour Balance is " + std::to_string(balance) << endl;
            PlayorNoPlay();

        }
        else {
            ChooseNextMove(); 
        }
    }

    else {
        cout << "Game has ended early.";
        PlayorNoPlay();
    }

}

void ChooseNextMove() {
    
    
    extern std::string NextPlay; 
  

    while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "double down" && NextPlay != "split" && NextPlay != "surrender") {
        cout << "Choose 'Stand', 'Hit', 'Double Down', 'Split' or 'Surrender': ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::getline(std::cin, NextPlay);

        std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
            [](unsigned char c) { return std::tolower(c); });
        
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

void Surrender() {
    
    extern int wager;
    extern int balance; 
    wager /= 2; 
    balance -= wager;
    cout << "You'll recive half your wager back, but the dealers second card was " + std::to_string(DCard2) + "\n";
    cout << "Your balance is " + std::to_string(balance) + "\n"; 
    PlayorNoPlay();

}

int PTotalCard = PCard1 + PCard2;

void Hit() {
    
    extern int balance; 
    extern int wager; 
    extern int PTotalCard; 
    
    int PCardEx = cards[rand() % 13];
    cout << "Your extra card is " + std::to_string(PCardEx) + "\n";
    
    
    
    PTotalCard += PCardEx;
    

    if (PTotalCard == 21 && DCard1 + DCard2 != 21) {
        wager *= 1.5;
        balance += wager;
        cout << "Congratulations! You won a blackjack! ";
        cout << "Your have won " + std::to_string(wager) + ", Your total balance is " + std::to_string(balance) << endl;
        PlayorNoPlay();
    }
    else if (PTotalCard == 21 && DCard1 + DCard2 == 21) {
        cout << "Push!, the dealers second card was " + std::to_string(DCard2);
        cout << "You'll recieve your initial wager back\nYour balance is " + std::to_string(balance) << endl;
        PlayorNoPlay();
    }
    else if (PTotalCard > 21) {
        balance -= wager;
        cout << "Bust!, you've lost your entire wager\nYour Balance is " + std::to_string(balance) << endl;
        PlayorNoPlay();

    }
    else {
        
        extern std::string NextPlay;

        cout << "Choose what you'd like to do next, 'Stand', 'Hit', or 'Surrender': ";
        getline(cin, NextPlay);

        std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
            [](unsigned char c) { return std::tolower(c); });

        while (NextPlay != "stand" && NextPlay != "hit" && NextPlay != "surrender") {
            cout << "Try Again, choose 'Stand', 'Hit', 'Split' or 'Surrender': ";
            getline(cin, NextPlay);

            std::transform(NextPlay.begin(), NextPlay.end(), NextPlay.begin(),
                [](unsigned char c) { return std::tolower(c); });
        }




        if (NextPlay == "stand") {
            Stand();
        }
        else if (NextPlay == "hit") {
            Hit();
        }
        else if (NextPlay == "surrender") {
            Surrender();
        }
    }
    

}

void Stand() {
   
    extern int wager;
    extern int balance;
    extern int PTotalCard; 
    
    if (PCard1 + PCard2 == DCard1 + DCard2 || PTotalCard == DCard1 + DCard2) {
       
        cout << "The Player and the Dealer have the same amount, nobody looses!" << endl;
        cout << "Your balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }

    else if (PCard1 + PCard2 > DCard1 + DCard2 || PTotalCard > DCard1 + DCard2) {

        wager *= 2;
        balance += wager;
        cout << "Congratulations you win, the dealers total was " + std::to_string(DCard1 + DCard2) + "\n";
        cout << "Your balance is " + std::to_string(balance) + "\n";
        PlayorNoPlay();
    }

    else if (PCard1 + PCard2 < DCard1 + DCard2 || PTotalCard < DCard1 + DCard2) {
        
        balance -= wager;
        cout << "cards = " + std::to_string(PCard1 + PCard2);

        cout << "The dealer had a total of " + std::to_string(DCard1 + DCard2) + " You loose" << endl;
        PlayorNoPlay();
    }
    
}

void DoubleDown() {
    
    extern int wager; 
    wager *= 2;
   
    cout << "Your wager has doubled to " + std::to_string(wager) << endl;
    
    Hit();

}

void Split() {
    
    extern int PCard1; 
    extern int PCard2; 

    if (PCard1 == PCard2) {
        
         // TODO finish split
    }
    else {
        cout << "You can't split because your two cards aren't the same";
        ChooseNextMove(); 

    }
        

}

void RunItAll() {

    WagerAmmount();

    GenerateCards();

    ChooseNextMove();
}

void PlayorNoPlay () {
    
    extern int PlayorNot; 
    extern int i; 

    cout << "To Play another round enter '1', to quit the game enter '2': ";
    cin >> PlayorNot;

    if (PlayorNot == 1) {
        
        RunItAll();
    }
    else if (PlayorNot == 2) {
        exit(EXIT_SUCCESS);
    }

}

