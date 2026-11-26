#ifndef GAME_HPP
#define GAME_HPP

#include "Deck.hpp"
#include <vector>
#include "Player.hpp"
#include "ScoreCalculator.hpp"

class Game {
    private:
    std::vector<Player> giocatori;
    ScoreCalculator calcola;
    Deck mazzo;
     const int numeroPlayer;
     int roundCorrente;
     int carteDistribuite;
     int punteggioRound;
    public:
    Game(int numeroPlayer);
    void inizializzaRound();
    void inizializzaPartita();
    void terminaRound();
};

#endif // GAME_HPP