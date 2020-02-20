#include "Cell.h"

Cell::Cell(){

    this->state = 0;
    this->column = 0;
    this->row = 0;
    this->neighbourAmount = 0;
}

Cell::Cell(int column, int row){
    this->state = false;
    this->column = column;
    this->row = row;
    this->neighbourAmount = 0;
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

bool Cell::getState(){
    return state;
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
