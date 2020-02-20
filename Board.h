#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <vector>
#include "Cell.h"

class Board {
/**
 * @class Board
 * @brief Class for the space where Cell objects reside
 */
private:

    /**
     * Private variables
     * @param cells, a vector that contains vectors which contain Cell objects
     */
    std::vector<std::vector<Cell>> cells;

public:

    /**
     * @brief initializers for a board object
     */
    /**
     * Default constructor without parameters
     */
    Board();

    /**
     * Constructor for a Board object with integer that indicates it's size (n x n)
     * @param n, integer that indicates the size of the board
     */
    Board(int n);

    /**
     * @brief Function that returns the number of alive Cells adjacent to the Cell object given as parameter
     * @param c, Cell object whose neighbours are to be determined
     * @return integer that indicates the number of adjacent Cells that are alive
     */
    int checkNeighbours(Cell c);

    /**
     * @brief Applies the rules of Game of Life once for every cell on the board
     */
    void nextState();

    /**
     * @brief Plays the game for 11 turns
     */
    void automaticGame();

    /**
     * @brief Prints the state of the game to console with "1" indicating an alive cell, and "0" a dead one
     */
    void printBoard();

    /**
     * @brief Function that sets one cell on the board to being alive
     * @param i, integer that depicts the column of the board the cell is in
     * @param j, integer that depicts the row of the board the cell is in
     */
    void setAlive(int i, int j);
};

#endif //GAME_OF_LIFE_BOARD_H