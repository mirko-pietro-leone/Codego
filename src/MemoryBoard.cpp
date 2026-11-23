#include <utility>
#include <vector>
#include "Card.hpp"
#include "MemoryBoard.hpp"

MemoryBoard ::MemoryBoard() : occupato(0){
}

 bool MemoryBoard :: getspazio (const Card& carta) const{

    if (occupato+ carta.geteCosto() <=20 && carta.geteCosto()>=0 )
        return true;
    else 
        return false;
 }

bool  MemoryBoard :: aggiungicarta(Card&& carta){
    if (getspazio(carta)){
        int costo = carta.geteCosto();
        carte.push_back(std::move(carta));
        occupato += costo;
        return true;
    }
    else   { 
        return false;
    }
}   

bool  MemoryBoard ::popcarte (){
    if (carte.empty()) {
        return false;
    }
    int costo = carte.back().geteCosto();
    carte.pop_back();
    occupato -= costo;
    return true;
}

void  MemoryBoard :: reset(){
    carte.clear();
    occupato=0;
}

int MemoryBoard ::getoccupato()const {
    return occupato;
}

const std::vector<Card>& MemoryBoard :: getCarte() const{
return carte;
}