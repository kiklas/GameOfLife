//
// Created by Niklas on 07/02/2020.
//

#include "Cell.h"

Cell::Cell(){

    this->state = 0;
    this->column = 0;
    this->row = 0;
}

Cell::Cell(bool state, int column, int row){

    this->state = state;
    this->column = column;
    this->row = row;
}

void Cell::setState(bool s) {

    state = s;
}

void Cell::applyRules(){

    if(state){
        if(neighbourAmount <= 1 || neighbourAmount >= 4)
            state = false;
    }
    else{
        if(neighbourAmount == 3)
            state = true;
    }
}

int Cell::getColumn() {
    return this->column;
}

int Cell::getRow() {
    return this->row;
}

Cell::operator bool() const {
    return state;
}

void Cell::operator=(bool b) {

    state = b;
}

void Cell::setNeighbourAmount(int n) {

    neighbourAmount = n;
}

int Cell::getNeighbourAmount() {
    return neighbourAmount;
}

