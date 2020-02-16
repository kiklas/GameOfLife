//
// Created by Niklas on 07/02/2020.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H


class Cell {

private:

    bool state;
    int column;
    int row;
    int neighbourAmount;

public:

    Cell();
    Cell(bool s, int c, int r);
    void setState(bool s);
    void applyRules();
    int getColumn();
    int getRow();
    operator bool() const;
    void operator=( bool b);
    void setNeighbourAmount(int n);
    int getNeighbourAmount();
};


#endif //GAME_OF_LIFE_CELL_H
