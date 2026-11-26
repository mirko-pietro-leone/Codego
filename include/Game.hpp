#ifndef GAME_HPP
#define GAME_HPP

#include "Deck.hpp"
#include <vector>
#include "Player.hpp"

class Game {
    private:
    std::vector<Player> giocatori;
    Deck mazzo;
     const int numeroPlayer;
     int roundCorrente;
     int carteDistribuite;
    public:
    Game(int numeroPlayer);
    void inizializzaRound();
    void inizializzaPartita();
};

#endif // GAME_HPP