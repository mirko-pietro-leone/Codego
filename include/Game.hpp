#ifndef GAME_HPP
#define GAME_HPP

#include "Deck.hpp"
#include <vector>
#include "Player.hpp"
#include "ScoreCalculator.hpp"
#include "Scelta.hpp"

class Game {
    private:
    std::vector<Player> giocatori;
    ScoreCalculator calcola;
    Deck mazzo;
    bool partitaFinita;
     const int numeroPlayer;
     int roundCorrente;
     int carteDistribuite;
     int punteggioRound;

    
    bool gestisciCarta(std::size_t indiceGiocatore, Card&& carta,std::size_t indiceBersaglio);
    bool gestisciPop(std::size_t indiceBersaglio);
    bool bersaglioValido(std::size_t indiceBersaglio) const;

    public:
    Game(int numeroPlayer);
    void inizializzaRound();
    void inizializzaPartita();
    void terminaRound();
    void passaMano();
    void eseguiTurno(const std::vector<Scelta>& indicescelti); //indicescelti è l indice delle carte scelte dai giocatori
   
};

#endif // GAME_HPP