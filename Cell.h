#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

class Cell {
/**
 * @class Cell
 * @brief a class for occupant of one cell on a board
 */
private:

    /**
     * Private variables:
     * @param state, boolean that tells whether the cell is "alive"(true) or "dead"(false)
     * @param column, integer that shows the column in the board that the cell is in
     * @öaram row, integer that show the row in the board that the cell is in
     * @param neighbourAmount, integer that shows how many neighbours of the cell are alive
     */
    bool state;
    int column;
    int row;
    int neighbourAmount;

public:

    /**
     * @brief initializers for a cell object
     */
     /**
      * Default constructor without parameters
      */
    Cell();
    /**
     * @brief Constructor for cell object with two integers that indicate it's position on the board
     * @param c, integer that shows the column in the board that the cell is in
     * @param r, integer that show the row in the board that the cell is in
     */
    Cell(int c, int r);

    /**
     * @brief Function for manipulating the state of a cell according to the rules of Game of Life
     * https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
     */
    void applyRules();

     /**
      * @brief getter for column of Cell object
      * @return int column
      */
    int getColumn();

    /**
     * getter for row of Cell object
     * @return int row
     */
    int getRow();

    /**
     * getter for the state of Cell object
     * @return bool state
     */
    bool getState();

    /**
     * @brief overload that replaces the default call of the Cell object with a boolean check
     * @return state of the Cell (alive or dead)
     */
    operator bool() const;

    /**
     *@brief overload for operator =, assigns bool b to Cell object
     * @param b, boolean to be assigned
     */
    void operator=( bool b);

    /**
     * setter for neighbours of a Cell object
     * @param n amount of neighbours the Cell object has
     */
    void setNeighbourAmount(int n);
};

#endif //GAME_OF_LIFE_CELL_H