#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "Card.hpp"


class Deck {
private:
    std::vector<Card> mazzo;

public:
    Deck();
    void inizializzaMazzo();
    Card pesca();
    size_t getNumeroCarte() const;
    std:: vector <Card>  distribuisciMano(int numeroCarte);
};

#endif // DECK_HPP