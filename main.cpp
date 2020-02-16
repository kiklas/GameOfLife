#include <iostream>
#include <sstream>
#include "Board.h"

int main() {

    Board gameBoard;

    while(true) {

        std::stringstream ss;
        std::string initializerString;
        int boardSize = 0;

        std::cout << "Input a number to initialize the board" << std::endl;
        std::cin >> initializerString;
        ss << initializerString;

        ss >> boardSize;
        gameBoard = Board(boardSize);

        if (ss.fail()) {
            std::cout << "Input an integer" << std::endl;
            ss.str("");
        } else {
            break;
        }
    }

    while(true){

        std::stringstream ss;
        std::string text;
        int column = 0;
        int row = 0;
        char separator = ' ';
        bool isValid = false;

        std::cout << "Enter a pair of integers separated by comma to set a board space alive" << std::endl;
        std::cout << "First number is column, second is row" << std::endl;
        std::cout << "For example: \n3,4" << std::endl;
        std::cout << "If you are done press 0 to start the game" << std::endl;
        std::cin >> text;
        ss << text;

        ss >> column;
        ss >> separator;
        ss >> row;

        if (ss.fail()) {
            std::cout << "Input an integer" << std::endl;
            ss.str("");
        }
        else{
            isValid = true;
        }
        if (column == 0 && !isValid){

            break;
        }
        else if (isValid){
            gameBoard.setAlive(column, row);
            gameBoard.printBoard();
        }

        column = 0;
        row = 0;
        isValid = false;
    }

    while (true){

        std::string inputString = "";

        std::cout << "Choose an action" << std::endl;
        std::cout << "1: Start automatic game" << std::endl;
        std::cout << "2: Next state" << std::endl;

        std::cin >> inputString;

        if (inputString == "1"){
            gameBoard.automaticGame();
        }
        else if (inputString == "2"){
            gameBoard.nextState();
        }
        else{
            std::cout << "Input either 1 or 2" << std::endl;
        }
        std::cin.clear();
    }
    std::cin.clear();

    return 0;
}


