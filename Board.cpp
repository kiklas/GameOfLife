#include <iostream>
#include "Board.h"
#include "stdexcept"

Board::Board() = default;

Board::Board(int size) {

    std::vector<Cell> cellRow;
    //Initialize matrix with a vector of cells and fill it with Cell objects
    for (int i = 0; i < size; i++){
        cells.push_back(cellRow);
        for (int j = 0; j < size; j++){
            cells[i].push_back(Cell(i, j));
        }
    }
}

int Board::checkNeighbours(Cell c) {

    int i = c.getColumn() - 1;
    int j = c.getRow() - 1;
    int neighbours = 0;

    //Checks the neighbours of Cell c, and increments int neighbours by one whenever an alive
    //Cell is found in the adjacent spaces
    for(i; i <= c.getColumn() + 1; i++)  {

        //continue if out of bounds
        if(i < 0 || i > cells.size()) continue;

        for (j; j <= c.getRow() + 1; j++) {

            //continue if out of bounds
            if(j < 0 || j > cells.size()) continue;

            //continue if indexes point to self
            if(i == c.getColumn() && j == c.getRow()) continue;

            if(cells.at(i).at(j).getState()){
                neighbours++;
            }
        }
        j = c.getRow() - 1;
    }
    return neighbours;
}

void Board::nextState() {

    //Set neighbourAmount for every cell on the board
    for (int i = 0; i < cells.size(); i++) {
        for (auto it = cells[i].begin(); it != cells[i].end(); it++) {
            it->setNeighbourAmount(checkNeighbours(*it));
        }
    }

    //Apply the rules of the game for every cell on the board
   for (int i = 0; i < cells.size(); i++) {
        for (auto it = cells[i].begin(); it != cells[i].end(); it++) {
            it->applyRules();
        }
    }
    printBoard();
}

void Board::automaticGame() {

    int counter = 0;

    for (;counter < 11; counter++) {

        nextState();
    }
}

void Board::printBoard() {

    std::string text = "";

    //Append every space of the board to a stringstream, then print them to console
    for (int i = 0; i < cells.size(); i++)
     {
        for (int j = 0; j < cells.size(); j++) {
            text += "[";
            if(cells.at(i).at(j) < 1) text += "0";
            else text += "1";
            //text += std::to_string(cells.at(i).at(j));
            text += "] ";
        }
        std::cout << text << std::endl;
        text = "";
    }
    std::cout << std::endl << std::endl;
}

void Board::setAlive(int column, int row) {

    try {
        cells.at(column).at(row) = true;
    } catch(const std::out_of_range &e){
        std::cout << "Index out of range" << std::endl;
    }
}