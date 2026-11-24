#include <vector>
#include "Player.hpp"
#include <utility>
#include <stdexcept>

Player:: Player(int idplayer) : id(idplayer),punteggioTot(0),numerocom(0){

}

void Player::riceviMano(std::vector<Card>&& carte){
    mano = std::move(carte);
}

std::vector<Card> Player::cediMano() {
    std::vector<Card> manoceduta;
    manoceduta.swap(mano);
    return manoceduta;
}

Card Player:: giocaCarta(int i){
    if (i<0 || static_cast<std::size_t>(i) >= mano.size()){
      throw std::out_of_range("Indice della carta non valido");
    }
    
    Card temp = std::move(mano[i]);
    mano.erase(mano.begin() + i);
    return temp;
}

void Player:: aggiungipunti(int punti){
    punteggioTot +=punti;
}

int Player::getPunteggioTot() const {
    return punteggioTot;
}

void Player::aggiungicommenti(){
    numerocom += 1;
}

int Player::getcoomentiTot() const{
    return numerocom;
}

const MemoryBoard& Player:: getplancia() const{
    return plancia;
}

void Player:: resetplancia(){
    plancia.reset();
}

bool Player :: giocacarta(Card&& carta){
      return plancia.aggiungicarta(std::move(carta));
}

bool Player:: rimuoviultimacarta(){
    return plancia.popcarte();
}