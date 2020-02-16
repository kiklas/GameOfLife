//
// Created by Niklas on 07/02/2020.
//

#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <vector>
#include "Cell.h"

class Board {
private:

    std::vector<std::vector<Cell>> cells;

public:

    Board();
    Board(int n);
    int checkNeighbours(Cell c);
    void nextState();
    void automaticGame();
    void printBoard();
    void setAlive(int i, int j);
};


#endif //GAME_OF_LIFE_BOARD_H
