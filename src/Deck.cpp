#include "Deck.hpp"
#include <random>
#include <stdexcept>
#include <utility>

Deck:: Deck(){

}

void Deck:: inizializzaMazzo(){
    mazzo.clear();
    for (int i=0; i<21; i++){
        mazzo.emplace_back(CardType::Char);
        mazzo.emplace_back(CardType::Int);
        mazzo.emplace_back(CardType::Double);
    }
    for (int i=0;  i<14; i++){
        mazzo.emplace_back(CardType::Pointer);
    }
    for (int i=0; i<11; i++){
        mazzo.emplace_back(CardType::Array);
    }
    for (int i=0; i<9; i++){
        mazzo.emplace_back(CardType::Pop);
    }
    for (int i=0; i<8; i++){
        mazzo.emplace_back(CardType::Comment);
    }
    std::random_device rd;
    std::mt19937 generatore(rd());
    std::shuffle(mazzo.begin(),mazzo.end(),generatore);
}

Card Deck::pesca(){
    if(mazo.empty()){
        throw std::out_of_range("Mazzo vuoto");
    }
   
    Card pescata =std::move(mazzo.back());
    mazzo.pop_back();
    return pescata;
}

size_t Deck::getNumeroCarte() const {
   return mazzo.size();
}

std::vector <Card> Deck::distribuisciMano(int numerocarte){    //distribuisci la mano 
    std::vector<Card> mano;
    if (numerocarte < 0 || static_cast<std::size_t>(numerocarte) > mazzo.size()) {
    throw std::out_of_range("Carte insufficienti nel mazzo");
    }
    mano.reserve(numerocarte);
    for (int i=0; i<numerocarte; i++){
        mano.push_back(pesca());
    }
    return mano;
}