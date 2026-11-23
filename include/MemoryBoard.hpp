
#ifndef MEMORYBOARD_HPP
#define MEMORYBOARD_HPP
#include <utility>
#include <vector>
#include "Card.hpp"

class MemoryBoard
{
private:
     std::vector<Card> carte;
      int occupato;

public:

 MemoryBoard();

bool getspazio (const Card& carta) const; //spazio restante

bool aggiungicarta(Card&& carta);

bool popcarte ();

void reset();

int getoccupato()const;  //spazio occupato

const std::vector<Card>& getCarte() const; //lettura carte 

};
#endif // MEMORYBOARD_HPP