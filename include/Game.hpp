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
    void passaMano();
    void eseguiTurno(const std::vector<int>& indicescelti); //indicescelti è l indice delle carte scelte dai giocatori
    void gestisciCarta(std::size_t indiceGiocatore, Card&& carta);
};

#endif // GAME_HPP