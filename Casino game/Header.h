#include <string>

#ifndef HEADER_H
#define HEADER_H

int WagerAmmount();

void GenerateCards();

void ChooseNextMove(); 

void Surrender();

void Hit();

void Stand();

void DoubleDown();

void Split();

void PlayorNoPlay(); 

void RunItAll();

void AcePossible(); 

int HitforHand(int wagerh, int phand, std::string handh);

void HitH2(); 

void StandforHand(int wagers, int phands, std::string hands);

//void SurrenderforHand(int wagersur, int phandsur);

//void DoubleDownforHand(); 

#endif