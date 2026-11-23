
    #include <iostream>

    #include "card.hpp"
    #include <stdexcept>

    int main() {
        std::cout << "Hello, World!" << std::endl;
        
        Card carta (CardType :: Int);
        int idcarta = carta.getID();
        std::cout <<idcarta << std:: endl; 
 
        Card carta2 (CardType :: Double);
        int idcarta2 = carta2.getID();
        std::cout <<idcarta2 << std:: endl; 
        return 0;
    }
