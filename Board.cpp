//
// Created by Niklas on 07/02/2020.
//
#include <iostream>
#include "Board.h"
#include "stdexcept"

Board::Board() {

}

Board::Board(int size) {

    std::vector<Cell> cellRow;
    for (int i = 0; i < size; i++){
        cells.push_back(cellRow);
        for (int j = 0; j < size; j++){
            cells[i].push_back(Cell());
        }
    }
}

int Board::checkNeighbours(Cell c) {

    int i = c.getColumn() - 1;
    int j = c.getRow() - 1;
    int neighbours = 0;

    for(i; i <= c.getColumn() + 1; i++)  {

        try{
            if(cells.at(i).at(j)){
                neighbours++;
            }
        } catch(std::out_of_range){

        }
        for (j; j <= c.getRow() + 1; ++j) {

            try {

                if(cells.at(i).at(j)){
                    neighbours++;
                }
            } catch (std::out_of_range) {

            }
        }
        j = c.getRow() - 1;
    }

    return neighbours;

}

void Board::nextState() {

    int j;
    for (int i = 0; i < cells.size(); i++) {
        j = 0;
        for (auto it = cells[i].begin(); it != cells[i].end(); it++, j++) {
            it->setNeighbourAmount(checkNeighbours(*it));
        }
    }
   for (int i = 0; i < cells.size(); i++) {
        j = 0;
        for (auto it = cells[i].begin(); it != cells[i].end(); it++, j++) {
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

    for (int i = 0; i < cells.size(); i++)
     {
        for (int j = 0; j < cells.size(); j++) {
            text += "[";
            text += std::to_string(cells.at(i).at(j));
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
    } catch(std::out_of_range){
        std::cout << "Index out of range" << std::endl;
    }
}



