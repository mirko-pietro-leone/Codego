#include "card.hpp"
#include <stdexcept>

 Card:: Card(CardType type) : id(1000 + ++contatore), type(type), costo(0), punteggio(0){

    switch(type){
        case CardType::Char:
            costo = 1;
            punteggio = 1;
            break;

        case CardType::Int:
            costo = 4;
            punteggio = 2;
            break;     

        case CardType:: Double:
            costo =8;
            punteggio = 4;
            break;

        case CardType:: Pointer:
            costo= 4;
            break;

        case CardType:: Array:
            break;

        case CardType:: Pop:
            break;

        case CardType:: Comment:
            break;

    default:
    throw std::invalid_argument("Tipo di carta non valido");
    }
}



int Card :: getID() const{
    return id;
}

CardType Card :: getType() const {
    return type;
}

int Card:: geteCosto() const {
    return costo;
}

int Card:: getPunteggio() const {
    return punteggio;
}
