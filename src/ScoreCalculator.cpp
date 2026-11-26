#include "ScoreCalculator.hpp"

ScoreCalculator::ScoreCalculator() {}

int ScoreCalculator ::calcolaPunteggioBase(const MemoryBoard& plancia) const{
    int punteggio=0;
    for (const Card& carta :plancia.getCarte()){
        punteggio +=carta.getPunteggio();
    }
    return punteggio;
}