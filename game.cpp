#include "game.h"
#include <cmath>

Game::Game(int fieldSize){
    gameField.createField(fieldSize);
    winStatus = false;
    loseStatus = false;
}

void Game::updateWinStatus(){
    std::vector<std::vector<Cell>>& currentField = gameField.getField();
    for(int i = 0; i < gameField.getSize(); i++){
        for(int j = 0; j < gameField.getSize(); j++){
            if(currentField[i][j].haveWinValue()){
                winStatus = true;
                return;
            }
        }
    }
    winStatus = false;
}

void Game::updateLoseStatus(){
    if(!gameField.getMovableStatus()){
        loseStatus = true;
    }else{
        loseStatus = false;
    }
}

void Game::moveByMouse(std::vector<std::vector<int>> mouseCoords){
    std::string direction;
    int incrementForScore = 0;
    //std::vector<std::vector<Cell>>& currentField = gameField.getField();
    //int vectorSize = mouseCoords.size();
    if (mouseCoords.size()< 2){
        std::cerr << "Not enough mouse points for move" << std::endl;
    }
    int xMove = mouseCoords[0][0] - mouseCoords[mouseCoords.size()-1][0];
    int yMove = mouseCoords[0][1] - mouseCoords[mouseCoords.size()-1][1];


    if(std::abs(xMove) > std::abs(yMove)) {
        //*HORIZONTAL*//
        if(xMove > 0){
            direction = "RIGHT";
        }else{
            direction = "LEFT";
        }
    }else{
        //*VERTICAL*//
        if(yMove > 0){
            direction = "DOWN";
        }else{
            direction = "UP";
        }
    }

    incrementForScore = gameField.moveCells(direction);
    gameScore.updateCurrentScore(incrementForScore);
}

void Game::moveByKeyboard(std::string pressedKey){
    std::string direction;
    int incrementForScore = 0;

    if(pressedKey == "a" || pressedKey == "A"){
        direction = "LEFT";
    }else if(pressedKey == "w" || pressedKey == "W"){
        direction = "UP";
    }else if(pressedKey == "d" || pressedKey == "D"){
        direction = "RIGHT";
    }else if(pressedKey == "s" || pressedKey == "S"){
        direction = "DOWN";
    }

    incrementForScore = gameField.moveCells(direction);
    gameScore.updateCurrentScore(incrementForScore);
}

void Game::startGame(int fieldSize){
    gameField.createField(fieldSize);
    int numberOfStartsValues = 2;
    gameField.addNumbers(numberOfStartsValues);

    gameField.printFieldConsole();
    gameScore.printScoreConsole();

    // std::string dir = "d";

    // //std::cin >> dir;
    // moveByKeyboard(dir);
    // gameField.printFieldConsole();
    // gameScore.printScoreConsole();

}
