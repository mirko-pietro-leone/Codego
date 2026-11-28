#include "Game.hpp"
#include <stdexcept>
#include <iostream>


Game :: Game (int numeroPlayer): numeroPlayer(numeroPlayer), roundCorrente(1), partitaFinita(false){
   
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
    if(partitaFinita){
        return;
    }
    //calclolo punti round attuale
    for(Player& giocatore: giocatori){
        giocatore.aggiungipunti(calcola.calcolaPunteggioBase(giocatore.getplancia()));
    }
    //reset plancia
    for(Player& giocatore: giocatori){
        giocatore.resetPlancia();
        giocatore.svuotaMano();
    }
   
    if(roundCorrente<3){
    roundCorrente++;
    } else {

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
       partitaFinita = true; 
    }
    
}



void Game :: passaMano(){                               //passa mano
    std::vector<std::vector<Card>> manitemp;
    manitemp.reserve(giocatori.size());
    
    for(size_t i = 0; i<giocatori.size();i++){
        manitemp.push_back(giocatori[i].cediMano());
    }

     for(size_t i = 0; i<giocatori.size();i++){
        std::size_t prossimo = (i+1)%giocatori.size();
        giocatori[prossimo].riceviMano(std::move(manitemp[i]));
    }
}



void Game::eseguiTurno(const std::vector<Scelta>& indicescelti){
    bool fineRound = false;
    if (partitaFinita) {
        throw std::logic_error("La partita è terminata");
    }
    if(indicescelti.size()!= giocatori.size()){
        throw std::invalid_argument("Numoro di scelte non valido");
    }
    
    for (std::size_t i=0; i<giocatori.size(); i++){
        int indice =indicescelti[i].indiceCarta;
        if(indice < 0 || static_cast<std::size_t>(indice) >= giocatori[i].getNumeroMano()){
            throw std::invalid_argument("Numero di carte nella mano non valido");
        }
        
    }

    std::vector<Card> carteScelte;                      // preleviamo le carte scelte 
    carteScelte.reserve(giocatori.size());
    
    for(std::size_t i=0; i <giocatori.size(); i++){
        Card carta= giocatori[i].giocaCarta(indicescelti[i].indiceCarta);
        carteScelte.push_back(std::move(carta));
    }

    for(size_t i=0; i<giocatori.size(); i++){                       // gestione delle carte 
        bool risultato = gestisciCarta(i,std::move(carteScelte[i]));
        if(!risultato){
            fineRound = true;
        }
    }
    if (fineRound ){
        terminaRound();
    } else {
        passaMano();                                            //passaggio delle mani        
    }
}



bool Game:: gestisciCarta(std:: size_t indiceGiocatore, Card&& carta, std::size_t indiceBersaglio){
    switch (carta.getType())
    {
    case CardType::Char:
    case CardType:: Int:
    case CardType::Double:{
        
        bool allocata =giocatori[indiceGiocatore].allocaCarta(std::move(carta));
        if(!allocata){
            std::cout << "Overflow: termina il round" << std::endl;
            return false;
        }

       if(giocatori[indiceGiocatore].getplancia().getoccupato() ==20){          //controllo se la carta occupata occupa tutta la plancia
            std::cout << "Memoria massima" << std::endl;
            return false;
        }

        return true;
    }
    case CardType::Pointer:
    break;

    case CardType::Array:
    break;

    case CardType::Pop:
    break;

    case CardType::Comment:
        giocatori[indiceGiocatore].aggiungiCommenti();
    return true;

    default:
        break;
    }
}



bool Game::bersaglioValido(std::size_t indiceBersaglio) const{  //controlliamo se la plancia del giocatore è vuota in modo da poter usare pointer e pop
    if(indiceBersaglio>= giocatori.size()){
        return false;
    }

    if(giocatori[indiceBersaglio].getplancia().getCarte().empty()){
        return false ;
    }
    
    return true;
}

bool Game:: gestisciPop( std::size_t indiceBersaglio){
    if(!bersaglioValido(indiceBersaglio)){
        return false;
    }
   return giocatori[indiceBersaglio].rimuoviultimacarta();
}