#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "MemoryBoard.hpp"

class Player {
private:
    MemoryBoard plancia;
    const int id;
    std::vector<Card> mano;
public:
Player(int idplayer);

};

#endif // PLAYER_HPP