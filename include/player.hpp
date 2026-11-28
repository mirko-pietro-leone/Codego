#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "MemoryBoard.hpp"

class Player {
private:
    const int id;
    MemoryBoard plancia;
    std::vector<Card> mano;
    int punteggioTot;
    int numerocom;
public:
Player(int idplayer);

 void riceviMano(std::vector<Card>&& carte);
 
 std::vector<Card> cediMano();

 Card giocaCarta(int i);

 void aggiungipunti(int punti);

int getPunteggioTot() const;

void aggiungiCommenti();

int getCommentiTot()const;

const MemoryBoard& getplancia() const;

bool allocaCarta(Card&& carta);

bool rimuoviultimacarta();

void resetPlancia();

void svuotaMano();

std:: size_t getNumeroMano()const; // restituisce il numero di carte presenti nella mano 
};

#endif // PLAYER_HPP