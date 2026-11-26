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

void Game::terminaRound(){
    //calclolo punti round attuale
    for(Player& giocatore: giocatori){
        giocatore.aggiungipunti(calcola.calcolaPunteggioBase(giocatore.getplancia()));
    }
    //reset plancia
    for(Player& giocatore: giocatori){
        giocatore.resetPlancia();
    }
   
    if(roundCorrente<3){
    roundCorrente++;
    } else{

        int numerocommenti= 0;
        int commenti_max = giocatori.front().getCommentiTot();
        int commenti_min = giocatori.front().getCommentiTot();
        
        for(const Player& giocatore: giocatori){      //controllo chi ha il max e min di commenti

            numerocommenti= giocatore.getCommentiTot();
            if(numerocommenti>=commenti_max){
                commenti_max= numerocommenti;
                
            } 
            if(numerocommenti<= commenti_min){
                commenti_min=numerocommenti;
            }
        } 
        
        if(commenti_max!=commenti_min){                 //assegno punti commento

            for(Player& giocatore:giocatori){
               numerocommenti= giocatore.getCommentiTot();

                 if (numerocommenti == commenti_max){
                    giocatore.aggiungipunti(6);
                 }
                 if (numerocommenti == commenti_min){
                    giocatore.aggiungipunti(-6);
                }
            }
        }
    }
    
}