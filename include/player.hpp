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
}

int getpunteggioTot() const;
#endif // PLAYER_HPP

void aggiungicommenti();

int getcommentiTot()const;

const MemoryBoard& getplancia() const;

void giocacarta(Card&& carta);

bool rimuoviultimacarta();