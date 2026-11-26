#ifndef SCORECALCULATOR_HPP
#define SCORECALCULATOR_HPP

#include "Player.hpp"
#include <vector>

class ScoreCalculator {
    private:
    public:
    ScoreCalculator();
    int calcolaPunteggioBase(const MemoryBoard& plancia) const;
};
#endif // SCORECALCULATOR_HPP

