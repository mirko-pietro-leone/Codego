
#ifndef CARD_HPP
#define CARD_HPP


enum class CardType {
    Char,
    Int,
    Double,
    Pointer,
    Array,
    Pop,
    Comment
};

class Card {
private:
inline static int contatore =0;
    int id;
    CardType type;
    int costo;
    int punteggio;

public: Card( CardType type);


int getID() const; 

CardType getType() const;

int geteCosto() const;

int getPunteggio() const ;

};
#endif // CARD_HPP
