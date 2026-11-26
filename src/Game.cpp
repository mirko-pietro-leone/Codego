#include "Game.hpp"
#include <stdexcept>


Game :: Game (int numeroPlayer): numeroPlayer(numeroPlayer), roundCorrente(1){
   
    if(numeroPlayer >5 || numeroPlayer<2){
        throw std::invalid_argument ("Numero di giocatori errato");
    }
    
    giocatori.reserve(numeroPlayer);
    for(int i=0; i<numeroPlayer; i++){
            giocatori.emplace_back(i+1);
    }
    switch(numeroPlayer)
    {
    case 2:
       carteDistribuite = 10;
        break;
    case 3: 
        carteDistribuite =9;
        break;
    case 4:
       carteDistribuite = 8;
        break;
    case 5: 
        carteDistribuite =7;
        break;
    }
}

void Game::inizializzaPartita(){
    mazzo.inizializzaMazzo();
}

void Game ::inizializzaRound(){
    for (Player& giocatore: giocatori){
        giocatore.riceviMano(mazzo.distribuisciMano(carteDistribuite));
     }
}